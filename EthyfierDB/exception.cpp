#include "pch.h"
#include "exception.h"

namespace EthyfierDB {
	Exception::Exception(const int32_t& address,
		const std::wstring& description,
		const ExceptionType& exceptionType)
		: m_address(address),
		m_description(description),
		m_exceptionType(exceptionType)
	{}

	int32_t Exception::address()
	{
		return m_address;
	}

	std::wstring Exception::description()
	{
		return m_description;
	}

	ExceptionType Exception::exceptionType()
	{
		return m_exceptionType;
	}
}