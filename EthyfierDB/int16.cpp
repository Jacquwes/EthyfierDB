#include "pch.h"
#include "int16.h"
#include "item.h"

namespace EthyfierDB {
	Int16::Int16(const std::wstring& name,
		const int16_t& value)
		: Item(name),
		m_value(value)
	{}

	ItemType Int16::getType()
	{
		return ItemType::Int16;
	}

	int16_t Int16::getValue()
	{
		return m_value;
	}

	void Int16::setValue(const int16_t& newValue)
	{
		m_value = newValue;
	}
}