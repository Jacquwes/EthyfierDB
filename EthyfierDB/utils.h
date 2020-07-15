#pragma once

#include "pch.h"

namespace EthyfierDB::Utils
{
	inline std::vector<wchar_t> readWideChars(const std::wstring& fileName)
	{
		std::vector<wchar_t> values;
		std::fstream file(fileName, std::ios::in | std::ios::binary);
		if (file)
			for (wchar_t temp; file.read(reinterpret_cast<char*>(&temp), sizeof(temp));)
				values.push_back(temp);
		file.close();
		return values;
	}

	inline void writeWideChars(const std::wstring& fileName, const std::vector<wchar_t>& wideChars)
	{
		std::fstream file(fileName, std::ios::out | std::ios::binary);
		file.write((char*)&wideChars[0], wideChars.size() * sizeof(wideChars[0]));
	}
}
