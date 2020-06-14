#include "ethyfierdb.h"
#include "pch.h"
#include "utils.h"

namespace EthyfierDB {
	DB::DB(const std::wstring& path)
		: m_data(new Object(L"index")),
		m_path(path)
	{
		if (!std::filesystem::exists(path))
		{
			std::filesystem::create_directory(path);
			return;
		}

		std::vector<wchar_t> header = Utils::readWideChars(path + L"/h.edb");
		std::vector<wchar_t> body = Utils::readWideChars(path + L"/b.edb");

		m_data->deserialize({ header, body });
	}

	Object* DB::data()
	{
		return m_data;
	}

	void DB::save()
	{
		RawEthyfierItem data = m_data->serialize();
		Utils::writeWideChars(m_path + L"/h.edb", data.header);
		Utils::writeWideChars(m_path + L"/b.edb", data.body);
	}
}