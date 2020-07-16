#pragma once

#include "item.h"
#include "pch.h"

namespace EthyfierDB {
	/// <summary>
	/// Represents an EthyfierDB's String item.
	/// </summary>
	class String : public Item
	{
	public:
		/// <summary>
		/// Create a new String.
		/// </summary>
		/// <param name="name">Name of the String.</param>
		/// <param name="value">Content of the String.</param>
		String(const std::wstring& name,
			const std::wstring& value);

		/// <summary>
		/// Returns the type of the Item.
		/// </summary>
		/// <returns>EthyfierDB::ItemType::String</returns>
		ItemType getType() override;

		/// <summary>
		/// Get the value of the String.
		/// </summary>
		/// <returns>Value of the String.</returns>
		const std::wstring getValue();

		/// <summary>
		/// Change the value of the String.
		/// </summary>
		/// <param name="newValue">New String value.</param>
		void setValue(const std::wstring& newValue);

	private:
		std::wstring m_value;
	};
}
