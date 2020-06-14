#include "pch.h"
#include "int32.h"
#include "item.h"

namespace EthyfierDB {
	Int32::Int32(const std::wstring& name,
		const int32_t& value)
		: Item(name),
		m_value(value)
	{}

	ItemType Int32::getType()
	{
		return ItemType::Int32;
	}

	int32_t Int32::getValue()
	{
		return m_value;
	}

	void Int32::setValue(const int32_t& newValue)
	{
		m_value = newValue;
	}
}