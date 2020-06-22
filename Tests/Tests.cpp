#include <iostream>
#include <EthyfierDB/ethyfierdb.h>

int main()
{
	EthyfierDB::DB* db = new EthyfierDB::DB(L"D:/tests");
	std::cout << (*db->data()->Int16Items())[L"int16 ouié"]->getValue();
}