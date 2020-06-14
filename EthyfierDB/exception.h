#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "pch.h"

namespace EthyfierDB {
	enum class ExceptionType
	{
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

#endif // EXCEPTION_H
