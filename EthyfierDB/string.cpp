#include "item.h"
#include "pch.h"
#include "string.h"

namespace EthyfierDB {
	String::String(const std::wstring& name,
		const std::wstring& value)
		: Item(name),
		m_value(value)
	{}

	ItemType String::getType()
	{
		return ItemType::String;
	}

	const std::wstring String::getValue()
	{
		return m_value;
	}

	void String::setValue(const std::wstring& newValue)
	{
		m_value = newValue;
	}
}