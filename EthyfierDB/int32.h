#pragma once

#include "item.h"
#include "pch.h"

namespace EthyfierDB {
	/// <summary>
	/// Used to contains 32 bits wide numbers.
	/// </summary>
	class Int32 : public Item
	{
	public:
		/// <summary>
		/// Create an EthyfierDB's Int32 item.
		/// </summary>
		/// <param name="name">Name of the item.</param>
		/// <param name="value">Value of the item.</param>
		Int32(const std::wstring& name,
			const int32_t& value);

		/// <summary>
		/// Returns the type of the Item.
		/// </summary>
		/// <returns>EthyfierDB::ItemType::Int32</returns>
		ItemType getType() override;

		/// <summary>
		/// Return the value of the Item.
		/// </summary>
		/// <returns>Value of the Item.</returns>
		int32_t getValue();

		/// <summary>
		/// Change the value of the Item.
		/// </summary>
		/// <param name="newValue">New value of the Item.</param>
		void setValue(const int32_t& newValue);

	private:
		int32_t m_value;
	};
}