#include "pch.h"
#include "exception.h"
#include "item.h"

namespace EthyfierDB {
	Item::Item(const std::wstring& name)
		: m_name(name)
	{}

	const std::wstring& Item::getName()
	{
		return m_name;
	}

	ItemType Item::getType()
	{
		throw(Exception(0,
			L"This item doesn't have a type.",
			ExceptionType::UndefinedType));
	}

	void Item::setName(const std::wstring& newName)
	{
		m_name = newName;
	}
}