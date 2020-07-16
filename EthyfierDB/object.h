#pragma once

#include "pch.h"
#include "int16.h"
#include "int32.h"
#include "item.h"
#include "manager.h"
#include "string.h"

namespace EthyfierDB {
	/// <summary>
	/// Used to contain other items.
	/// </summary>
	class Object : public Item
	{
	public:
		/// <summary>
		/// Create an EthyfierDB Object.
		/// </summary>
		/// <param name="name">Name of the object.</param>
		Object(const std::wstring& name);

		/// <summary>
		/// Int16 items manager.
		/// </summary>
		/// <returns>Reference to the Object's Int16 items manager.</returns>
		Manager<Int16>& Int16Items();
		/// <summary>
		/// Int32 items manager.
		/// </summary>
		/// <returns>Reference to the Object's Int32 items manager.</returns>
		Manager<Int32>& Int32Items();
		/// <summary>
		/// Object items manager.
		/// </summary>
		/// <returns>Reference to the Object's Object items manager.</returns>
		Manager<Object>& ObjectItems();
		/// <summary>
		/// String items manager.
		/// </summary>
		/// <returns>Reference to the Object's String items manager.</returns>
		Manager<String>& StringItems();

		/// <summary>
		/// Get the number of children items of the Object at depth 1.
		/// </summary>
		/// <returns>Number of children items.</returns>
		size_t childrenSize();

		/// <summary>
		/// Remove every item from the Object and create new ones from rawObject.
		/// </summary>
		/// <param name="rawObject">Raw EthyfierDB Object.</param>
		void deserialize(const RawEthyfierItem& rawObject);

		/// <summary>
		/// Returns the type of the Item.
		/// </summary>
		/// <returns>EthyfierDB::ItemType::Object</returns>
		ItemType getType() override;

		/// <summary>
		/// Create a raw Object from the current Object.
		/// </summary>
		/// <returns>Raw EthyfierDB Object.</returns>
		const RawEthyfierItem serialize();

		/// <summary>
		/// Searches in every Manager of the Object to find an Item with the specified name.
		///
		/// Throws Exception if no item has the name `name`.
		/// </summary>
		/// <param name="name">Name of the item.</param>
		/// <returns>Found item.</returns>
		Item& operator[](const std::wstring& name);

	private:
		Manager<Int16> m_itemsInt16;
		Manager<Int32> m_itemsInt32;
		Manager<Object> m_itemsObject;
		Manager<String> m_itemsString;
	};
}
