#pragma once

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

		template<class T>
		T& as();

		const std::wstring& getName();

		virtual ItemType getType();

		void setName(const std::wstring& newName);

	protected:
		std::wstring m_name;
	};

	// Don't know why, but generates LNK2019 when declared in item.cpp
	template<class T>
	inline T& Item::as()
	{
		return (T&)*this;
	}
}

