cmake_minimum_required(VERSION 3.17)
project(EthyfierDB)

set(CMAKE_CXX_STANDARD 17)

include_directories(EthyfierDB)

add_library(EthyfierDB
        EthyfierDB/ethyfierdb.cpp
        EthyfierDB/ethyfierdb.h
        EthyfierDB/exception.cpp
        EthyfierDB/exception.h
        EthyfierDB/framework.h
        EthyfierDB/int16.cpp
        EthyfierDB/int16.h
        EthyfierDB/int32.cpp
        EthyfierDB/int32.h
        EthyfierDB/item.cpp
        EthyfierDB/item.h
        EthyfierDB/manager.h
        EthyfierDB/object.cpp
        EthyfierDB/object.h
        EthyfierDB/pch.cpp
        EthyfierDB/pch.h
        EthyfierDB/string.cpp
        EthyfierDB/string.h
        EthyfierDB/utils.h)
