#pragma once

#include "item.h"
#include "pch.h"

namespace EthyfierDB {
	/// <summary>
	/// Used to contains 16 bits wide numbers.
	/// </summary>
	class Int16 : public Item
	{
	public:
		/// <summary>
		/// Create an EthyfierDB's Int16 item.
		/// </summary>
		/// <param name="name">Name of the item.</param>
		/// <param name="value">Value of the item.</param>
		Int16(const std::wstring& name,
			const int16_t& value);

		/// <summary>
		/// Returns the type of the Item.
		/// </summary>
		/// <returns>EthyfierDB::ItemType::Int16</returns>
		ItemType getType() override;

		/// <summary>
		/// Return the value of the Item.
		/// </summary>
		/// <returns>Value of the Item.</returns>
		int16_t getValue();

		/// <summary>
		/// Change the value of the Item.
		/// </summary>
		/// <param name="newValue">New value of the Item.</param>
		void setValue(const int16_t& newValue);

	private:
		int16_t m_value;
	};
}
