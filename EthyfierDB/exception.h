#pragma once

#include "pch.h"

namespace EthyfierDB {
	enum class ExceptionType
	{
		ItemNotFound,
		UndefinedType,
		UnknownType,
	};

	class Exception
	{
	public:
		Exception(const int32_t& address,
			const std::wstring& description,
			const ExceptionType& exceptionType);

		int32_t address();
		std::wstring description();
		ExceptionType exceptionType();

	private:
		int32_t m_address;
		std::wstring m_description;
		ExceptionType m_exceptionType;
	};
}
