#pragma once

#include "pch.h"
#include "exception.h"

namespace EthyfierDB
{
	template<class T>
	class Manager
	{
	public:
		T* find(std::function<bool(const T*)>& testFunction)
		{
			for (auto _item : m_items)
				if (testFunction(_item))
					return _item;
			return nullptr;
		}

		T* get(const std::wstring& name)
		{
			auto _item = std::find_if(
				m_items.begin(),
				m_items.end(),
				[&name](T* tempItem) { return tempItem->getName() == name; }
			);
			return (_item == m_items.end())
				? nullptr
				: *_item;
		}

		std::vector<T*> items()
		{
			return m_items;
		}

		void remove(std::wstring& name)
		{
			size_t index{};
			auto _item = std::find_if(
				m_items.begin(),
				m_items.end(),
				[&index, &name](T* tempItem)
				{
					if (tempItem->getName() == name)
						return true;
					index++;
					return false;
				}
			);
			if (_item != m_items.end())
				m_items.erase(m_items.begin() + index);
		}

		void set(T* item)
		{
			T* _item = get(item->getName());
			if (_item)
				*_item = *item;
			else
				add(item);
		}

	private:
		std::vector<T*> m_items;

		void add(T* item)
		{
			m_items.push_back(item);
		}
	};
}
