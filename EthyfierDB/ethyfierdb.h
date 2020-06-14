#ifndef ETHYFIERDB_H
#define ETHYFIERDB_H

#include "exception.h"
#include "int16.h"
#include "int32.h"
#include "item.h"
#include "object.h"
#include "string.h"
#include "pch.h"

namespace EthyfierDB {
	class DB
	{
	public:
		DB(const std::wstring& path);

		Object* data();

		void save();

	private:
		Object* m_data;
		std::wstring m_path;
	};
}

#endif // ETHYFIERDB_H
