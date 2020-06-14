#ifndef STRING_H
#define STRING_H

#include "item.h"
#include "pch.h"

namespace EthyfierDB {
	class String : public Item
	{
	public:
		String(const std::wstring& name,
			const std::wstring& value);

		ItemType getType() override;

		const std::wstring getValue();

		void setValue(const std::wstring& newValue);

	private:
		std::wstring m_value;
	};
}

#endif // STRING_H
