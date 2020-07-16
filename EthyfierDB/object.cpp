#include "pch.h"
#include "exception.h"
#include "int16.h"
#include "int32.h"
#include "item.h"
#include "manager.h"
#include "object.h"
#include "string.h"

namespace EthyfierDB {
	Object::Object(const std::wstring& name)
		: Item(name),
		m_itemsInt16(Manager<Int16>()),
		m_itemsInt32(Manager<Int32>()),
		m_itemsObject(Manager<Object>()),
		m_itemsString(Manager<String>())
	{}

	Manager<Int16>& Object::Int16Items() { return m_itemsInt16; }
	Manager<Int32>& Object::Int32Items() { return m_itemsInt32; }
	Manager<Object>& Object::ObjectItems() { return m_itemsObject; }
	Manager<String>& Object::StringItems() { return m_itemsString; }

	size_t Object::childrenSize()
	{
		return m_itemsInt16.items().size()
			+ m_itemsInt32.items().size()
			+ m_itemsObject.items().size()
			+ m_itemsString.items().size();
	}

	void Object::deserialize(const RawEthyfierItem& rawObject)
	{
		if (rawObject.header.empty() || rawObject.body.empty())
			return;

		m_itemsInt16.items().clear();
		m_itemsInt32.items().clear();
		m_itemsObject.items().clear();
		m_itemsString.items().clear();

		struct ItemData
		{
			int32_t address;
			std::wstring name;
			ItemType type;
			int32_t typeAddress;
		};

		std::vector<ItemData> items;

		// Read header

		for (size_t cursor = 1; cursor < rawObject.header.size(); cursor++)
		{
			int32_t typeAddress = static_cast<int32_t>(cursor);
			ItemType type = static_cast<ItemType>(rawObject.header[cursor++]);
			int16_t nameSize = rawObject.header[cursor++];
			std::wstring name(rawObject.header.begin() + cursor, rawObject.header.begin() + cursor + nameSize);
			cursor += nameSize;

			int32_t address = rawObject.header[cursor] << 16;
			cursor++;
			address |= rawObject.header[cursor];

			items.push_back({ address, name, type, typeAddress });
		}

		// Read body

		for (int32_t itemIndex = 0, itemsCount = rawObject.header[0]; itemIndex < itemsCount; itemIndex++)
		{
			const ItemData& item = items[itemIndex];
			size_t nextItemAddress = (itemIndex == itemsCount - 1)
				? rawObject.body.size()
				: items[(static_cast<size_t>(itemIndex) + 1)].address;

			switch (item.type) {
			case ItemType::String:
			{
				m_itemsString.set(String(item.name,
					std::wstring(rawObject.body.begin() + item.address, rawObject.body.begin() + nextItemAddress)));
				break;
			}
			case ItemType::Int16:
			{
				m_itemsInt16.set(Int16(item.name,
					rawObject.body[item.address]));
				break;
			}
			case ItemType::Int32:
			{
				m_itemsInt32.set(Int32(item.name,
					(rawObject.body[item.address] << 16) | rawObject.body[static_cast<size_t>(item.address) + 1]));
				break;
			}
			case ItemType::Object:
			{
				Object object(item.name);

				// Find header size

				int headerSize = 0;
				int cursor = item.address + 1;
				for (int subItemIndex = 0; subItemIndex < rawObject.body[item.address]; subItemIndex++)
				{
					int nameSize = rawObject.body[++cursor];
					headerSize += 4 + nameSize;
					cursor += nameSize + 3;
				}

				std::vector<wchar_t> header(
					rawObject.body.begin() + item.address,
					rawObject.body.begin() + item.address + 1 + headerSize);
				std::vector<wchar_t> body(
					rawObject.body.begin() + item.address + 1 + headerSize,
					rawObject.body.begin() + nextItemAddress
				);

				object.deserialize({ header, body });

				m_itemsObject.set(object);
				break;
			}
			default:
			{
				throw Exception(item.typeAddress,
					std::to_wstring(static_cast<int>(item.type)) + std::wstring(L" is not an EthyfierDB type."),
					ExceptionType::UnknownType);
				break;
			}
			}
		}
	}

	ItemType Object::getType()
	{
		return ItemType::Object;
	}

	const RawEthyfierItem Object::serialize()
	{
		std::vector<wchar_t> header;
		std::vector<wchar_t> body;

		header.push_back(static_cast<wchar_t>(childrenSize()));

		std::function<void(Item&)> writeHeader = [&header, &body](Item& item)
		{
			// Type + name size
			header.insert(header.end(), { static_cast<wchar_t>(item.getType()), static_cast<wchar_t>(item.getName().size()) });
			// Name
			for (wchar_t character : item.getName())
				header.push_back(character);
			// Address
			header.insert(header.end(), { static_cast<wchar_t>(body.size() >> 16), static_cast<wchar_t>(body.size() & 0xffff) });
		};

		for (Int16& item : m_itemsInt16.items())
		{
			writeHeader(item);
			body.push_back(item.getValue());
		}
		for (Int32& item : m_itemsInt32.items())
		{
			writeHeader(item);
			int32_t value = item.getValue();
			body.insert(body.end(), { static_cast<wchar_t>(value >> 16), static_cast<wchar_t>(value & 0xffff) });
		}
		for (Object item : m_itemsObject.items())
		{
			writeHeader(item);
			RawEthyfierItem object = item.serialize();
			body.insert(body.end(), object.header.begin(), object.header.end());
			body.insert(body.end(), object.body.begin(), object.body.end());
		}
		for (String item : m_itemsString.items())
		{
			writeHeader(item);
			std::wstring value = item.getValue();
			body.insert(body.end(), value.begin(), value.end());
		}

		return { header, body };
	}


	Item& EthyfierDB::Object::operator[](const std::wstring& name)
	{
		// ILL MAKE A CLEANER FUNCTION LATER SRY
		try
		{
			 return m_itemsInt16.get(name);
		}
		catch (Exception&)
		{
			try
			{
				return m_itemsInt32.get(name);
			}
			catch (Exception&)
			{
				try
				{
					return m_itemsObject.get(name);
				}
				catch (Exception&)
				{
					try
					{
						return m_itemsString.get(name);
					}
					catch (Exception& e)
					{
						throw e;
					}
				}
			}
		}
	}
}