#pragma once

#include "pch.h"
#include "exception.h"

namespace EthyfierDB
{
	template<class T>
	class Manager
	{
	public:
		T& find(std::function<bool(T&)> testFunction)
		{
			for (T& _item : m_items)
				if (testFunction(_item))
					return _item;
			throw(Exception(0, L"Item not found.", ExceptionType::ItemNotFound));
		}

		T& get(const std::wstring& name)
		{
			auto _item = std::find_if(
				m_items.begin(),
				m_items.end(),
				[&name](T& tempItem) { return tempItem.getName() == name; }
			);
			if (_item == m_items.end())
				throw(Exception(0, L"Item \"" + name + L"\" not found.", ExceptionType::ItemNotFound));
			else return *_item;
		}

		std::vector<T>& items()
		{
			return m_items;
		}

		void remove(std::wstring& name)
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

		T& operator	[](const std::wstring& name)
		{
			return get(name);
		}

	private:
		std::vector<T> m_items;

		void add(T item)
		{
			m_items.push_back(item);
		}
	};
}
