#pragma once

#include "item.h"
#include "pch.h"

namespace EthyfierDB {
	class Int16 : public Item
	{
	public:
		Int16(const std::wstring& name,
			const int16_t& value);

		ItemType getType() override;

		int16_t getValue();

		void setValue(const int16_t& newValue);

	private:
		int16_t m_value;
	};
}
