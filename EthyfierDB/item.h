#ifndef ITEM_H
#define ITEM_H

#include "pch.h"

namespace EthyfierDB {
	struct RawEthyfierItem
	{
		std::vector<wchar_t> header;
		std::vector<wchar_t> body;
	};

	enum class ItemType
	{
		Int16,
		Int32,
		Object,
		String,
	};

	class Item
	{
	public:
		Item(const std::wstring& name);

		const std::wstring& getName();

		virtual ItemType getType();

		void setName(const std::wstring& newName);

	protected:
		std::wstring m_name;
	};
}

#endif // ITEM_H
