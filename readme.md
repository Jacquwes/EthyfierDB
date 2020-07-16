//! \mainpage Presentation

# EthyfierDB

EthyfierDB is a lightweight object based storage library for C++17.

Ideal for your small softwares.

Online documentation available at https://jacquesatan.github.io/EthyfierDB.

## How to use it

⚠️ - Only supports `std::wstring`/`wchar_t`. You can't use `std::string`/`char` with EthyfierDB.

```cpp
#include "EthyfierDB/ethyfierdb.h"
#include <iostream>
#include <string>

int main()
{
    auto db = EthyfierDB::DB(L"C:/yourApp/data");
    // Add data
    db.data().StringItems().set(EthyfierDB::String(L"variable name", L"value"));
    db.data().Int16Items().set(EthyfierDB::Int16(L"price", 0xff5));

    // Create a new object
    auto object = EthyfierDB::Object(L"settings");
    object.Int32Items().set(EthyfierDB::Int32(L"amount", 0x123456789));
    db.data().ObjectItems().set(object);

    // "set" can also be used to replace a value
    db.data().StringItems().set(EthyfierDB::String(L"variable name", L"new value"));

    // Remove items
    db.data().Int16Items().remove(L"price");

    try
    {
        // Find by name
        auto item = db.data().StringItems().get(L"variable name");
        // Or
        item = db.data().StringItems()[L"variable name"];
        // Also 
        item = db.data()[L"variable name"].as<EthyfierDB::String>();
    
        std::wcout << item.getValue();
    }
    catch (EthyfierDB::Exception& e)
    {
        // If variable not found
        if (e.exceptionType() == EthyfierDB::ExceptionType::ItemNotFound)
            std::wcout << e.description();
    }

    // Find by value
    db.data().StringItems().find([](EthyfierDB::String& item)
        {
            return item.getValue() == L"new value";
        });

    // Don't forget to save your modifications !
    db.save();
}
```