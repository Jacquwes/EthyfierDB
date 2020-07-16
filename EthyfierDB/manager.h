#pragma once

#include "pch.h"
#include "exception.h"

namespace EthyfierDB
{
	/// <summary>
	/// Used to manage EthyfierDB's items.
	/// </summary>
	/// <typeparam name="T">Type of items to manage.</typeparam>
	template<class T>
	class Manager
	{
	public:
		/// <summary>
		/// Iterates on each item of the manager, and returns the first item for wchich `testFunction` returns `true`.
		///
		/// Throws Exception if `testFunction` didn't returned `true` once.
		/// </summary>
		/// <param name="testFunction">Testing function.</param>
		/// <returns>Any item of the manager.</returns>
		T& find(std::function<bool(T&)> testFunction)
		{
			for (T& _item : m_items)
				if (testFunction(_item))
					return _item;
			throw Exception(0, L"Item not found.", ExceptionType::ItemNotFound);
		}

		/// <summary>
		/// Retrieve an item by its name.
		///
		/// Throws Exception if no item has the name `name`.
		/// </summary>
		/// <param name="name">Name of the item.</param>
		/// <returns>Any item of the manager.</returns>
		T& get(const std::wstring& name)
		{
			auto _item = std::find_if(
				m_items.begin(),
				m_items.end(),
				[&name](T& tempItem) { return tempItem.getName() == name; }
			);
			if (_item == m_items.end())
				throw Exception(0, L"Item \"" + name + L"\" not found.", ExceptionType::ItemNotFound);
			else return *_item;
		}

		/// <summary>
		/// Every item of the manager.
		/// </summary>
		/// <returns>Reference to the manager's items.</returns>
		std::vector<T>& items()
		{
			return m_items;
		}

		/// <summary>
		/// Remove an item from the manager if it exists.
		/// </summary>
		/// <param name="name">Name of the item.</param>
		void remove(const std::wstring& name)
		{
			size_t index{};
			auto _item = std::find_if(
				m_items.begin(),
				m_items.end(),
				[&index, &name](T& tempItem)
				{
					if (tempItem.getName() == name)
						return true;
					index++;
					return false;
				}
			);
			if (_item != m_items.end())
				m_items.erase(m_items.begin() + index);
		}

		/// <summary>
		/// Change an item to another, or add it if it doesn't already exist.
		/// </summary>
		/// <param name="item">Item to set/add.</param>
		void set(T item)
		{
			try
			{
				T& _item = get(item.getName());
				_item = item;
			}
			catch (Exception&)
			{
				add(item);
			}
		}

		/// <summary>
		/// Retrieve an item by its name.
		///
		/// Throws Exception if no item has the name `name`.
		/// </summary>
		/// <param name="name">Name of the item.</param>
		/// <returns>Any item of the manager.</returns>
		T& operator[](const std::wstring& name)
		{
			return get(name);
		}

	private:
		/// <summary>
		/// Contains every item of the manager.
		/// </summary>
		std::vector<T> m_items;

		/// <summary>
		/// Add an item to the manager.
		/// </summary>
		/// <param name="item">Item to add.</param>
		void add(T& item)
		{
			m_items.push_back(item);
		}
	};
}
