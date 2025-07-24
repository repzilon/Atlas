cmake_minimum_required(VERSION 3.24)
project(atlas)

set(CMAKE_CXX_STANDARD 14)

add_executable(atlas AtlasCore.cpp
        AtlasExtension.cpp
        AtlasFile.cpp
        AtlasLogger.cpp
        AtlasMain.cpp
        AtlasParser.cpp
        AtlasStats.cpp
        AtlasTypes.cpp
        GenericVariable.cpp
        Pointer.cpp
        PointerHandler.cpp
        Table.cpp
        stdafx.cpp)
