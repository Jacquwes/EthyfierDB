#pragma once

#include "pch.h"

namespace EthyfierDB {
	struct RawEthyfierItem
	{
		std::vector<wchar_t> header;
		std::vector<wchar_t> body;
	};

	enum class ItemType
	{
		Int16,
		Int32,
		Object,
		String,
	};

	/// <summary>
	/// Base EthyfierDB item. Cannot be saved, only used to be inherited by "real" items.
	/// </summary>
	class Item
	{
	public:
		/// <summary>
		/// Create an EthyfierDB item.
		/// </summary>
		/// <param name="name">Name of the item.</param>
		/// <returns></returns>
		Item(const std::wstring& name);

		/// <summary>
		/// Easily "cast" any item to another type.
		/// </summary>
		template<class T>
		inline T& as()
		{
			return (T&)*this;
		}

		/// <summary>
		/// Returns the name of the item.
		/// </summary>
		/// <returns></returns>
		const std::wstring& getName();

		/// <summary>
		/// Returns the type of the item.
		/// </summary>
		/// <returns></returns>
		virtual ItemType getType();

		/// <summary>
		/// Set the name of the item.
		/// </summary>
		/// <param name="newName"></param>
		void setName(const std::wstring& newName);

	protected:
		std::wstring m_name;
	};
}

