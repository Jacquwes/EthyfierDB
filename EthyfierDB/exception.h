#pragma once

#include "pch.h"

namespace EthyfierDB {
	/// <summary>
	/// Represents the reason of an exception.
	/// </summary>
	enum class ExceptionType
	{
		ItemNotFound,
		UndefinedType,
		UnknownType,
	};

	/// <summary>
	/// Thrown by EthyfierDB instead of [std::exception](https://en.cppreference.com/w/cpp/error/exception).
	/// </summary>
	class Exception
	{
	public:
		/// <summary>
		/// Create a new Exception
		/// </summary>
		/// <param name="address">Used when EthyfierDB can't correctly parse a database.</param>
		/// <param name="description">Textual description of the error.</param>
		/// <param name="exceptionType">Type of the exception.</param>
		Exception(const int32_t& address,
			const std::wstring& description,
			const ExceptionType& exceptionType);

		/// <summary>
		/// Used when EthyfierDB can't correctly parse a database.
		/// </summary>
		/// <returns>Address of the error.</returns>
		int32_t address();

		/// <summary>
		/// Textual description of the error.
		/// </summary>
		/// <returns>Textual description of the error.</returns>
		std::wstring description();

		/// <summary>
		/// Type of the exception.
		/// </summary>
		/// <returns>Type of the exception.</returns>
		ExceptionType exceptionType();

	private:
		int32_t m_address;
		std::wstring m_description;
		ExceptionType m_exceptionType;
	};
}
