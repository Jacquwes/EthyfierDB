#pragma once

#include "item.h"
#include "pch.h"

namespace EthyfierDB {
	class Int32 : public Item
	{
	public:
		Int32(const std::wstring& name,
			const int32_t& value);

		ItemType getType() override;

		int32_t getValue();

		void setValue(const int32_t& newValue);

	private:
		int32_t m_value;
	};
}