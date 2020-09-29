#pragma once

#include "pch.h"

namespace EthyfierDB::Utils
{
	/// <summary>
	/// Return the content of a file as a `std::vector<wchar_t>`.
	/// </summary>
	/// <param name="fileName">Path to the file.</param>
	/// <returns>Content of the file.</returns>
	inline std::vector<wchar_t> readWideChars(const std::wstring& fileName)
	{
		std::vector<wchar_t> values;
		std::fstream file(std::filesystem::path(fileName), std::ios::in | std::ios::binary);
		if (file)
			for (wchar_t temp; file.read(reinterpret_cast<char*>(&temp), sizeof(temp));)
				values.push_back(temp);
		file.close();
		return values;
	}

	/// <summary>
	/// Writes data to a file.
	/// </summary>
	/// <param name="fileName">Path to the file.</param>
	/// <param name="wideChars">Data to write.</param>
	inline void writeWideChars(const std::wstring& fileName, const std::vector<wchar_t>& wideChars)
	{
		std::fstream file(std::filesystem::path(fileName), std::ios::out | std::ios::binary);
		file.write((char*)&wideChars[0], wideChars.size() * sizeof(wideChars[0]));
	}
}
