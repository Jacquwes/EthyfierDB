#pragma once

#include "pch.h"
#include "int16.h"
#include "int32.h"
#include "item.h"
#include "manager.h"
#include "string.h"

namespace EthyfierDB {
	/// <summary>
	/// Used to contain other items.
	/// </summary>
	class Object : public Item
	{
	public:
		/// <summary>
		/// Create an EthyfierDB Object.
		/// </summary>
		/// <param name="name">Name of the object.</param>
		/// <returns></returns>
		Object(const std::wstring& name);

		Manager<Int16>& Int16Items();
		Manager<Int32>& Int32Items();
		Manager<Object>& ObjectItems();
		Manager<String>& StringItems();

		size_t childrenSize();

		void deserialize(const RawEthyfierItem& rawObject);

		ItemType getType() override;

		const RawEthyfierItem serialize();

		Item& operator[](const std::wstring& name);

	private:
		Manager<Int16> m_itemsInt16;
		Manager<Int32> m_itemsInt32;
		Manager<Object> m_itemsObject;
		Manager<String> m_itemsString;
	};
}
