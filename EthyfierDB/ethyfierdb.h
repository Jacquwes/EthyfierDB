#pragma once

#include "exception.h"
#include "int16.h"
#include "int32.h"
#include "item.h"
#include "object.h"
#include "string.h"
#include "pch.h"

namespace EthyfierDB {
	/// <summary>
	/// Main library class. Used to interact with any EthyfierDB database.
	/// </summary>
	class DB
	{
	public:
		/// <summary>
		/// Opens a database.
		/// </summary>
		/// <param name="path">Path of the database. Parent directory must exist.</param>
		DB(const std::wstring& path);

		/// <summary>
		/// Main Object. Lets you interact with the database.
		/// </summary>
		/// <returns>Database's main object.</returns>
		Object& data();

		/// <summary>
		/// Writes the current state of the database.
		/// </summary>
		void save();

	private:
		Object m_data;
		std::wstring m_path;
	};
}
