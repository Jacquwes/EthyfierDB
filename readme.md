# EthyfierDB

EthyfierDB is a lightweight object based storage library for C++17.

Ideal for your small softwares.

## How to use it

⚠️ - Only supports `std::wstring`/`wchar_t`. You can't use `std::string`/`char` with EthyfierDB.

```cpp
#include "EthyfierDB/ethyfierdb.h"

int main()
{
    // Open a database
    auto db = new EthyfierDB::DB(L"C:/yourApp/data");
    // Add data
    db->data()->StringItems()->set(new EthyfierDB::String(L"variable name", L"value"));
    db->data()->Int16Items()->set(new EthyfierDB::Int16(L"price", 0xff5));

    // Create a new object
    auto object = new EthyfierDB::Object(L"settings");
    object->Int32Items()->set(new EthyfierDB::Int32("amount", 0x123456789));
    db->data()->ObjectItems()->set(object);

    // "set" can also be used to replace a value
    db->data()->StringItems()->set(new EthyfierDB::String(L"variable name", L"new value"));

    // Remove items
    db->data()->Int16Items()->remove(L"price");

    // Find by value
    db->data()->StringItems()->find([](EthyfierDB::String* item)
    {
        return item->getValue() == L"new value";
    });

    // Save your modifications
    db->save();
    delete db;
}
```