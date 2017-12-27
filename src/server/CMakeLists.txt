cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pthread")

set(SOURCE_FILES
        src/main.cpp
        src/Server.cpp
        include/Server.h
        src/FileReader.cpp
        include/FileReader.h
        include/Command.h
        include/CommandsManager.h
        include/StartCommand.h
        include/JoinCommand.h
        src/JoinCommand.cpp
        src/StartCommand.cpp
        src/CommandsManager.cpp
        include/ListCommand.h
        src/ListCommand.cpp
        include/ClientHandler.h
        src/ClientHandler.cpp
        include/ConverString.h
        src/ConverString.cpp src/PlayGame.cpp include/PlayGame.h src/GameData.cpp src/GameData.h)

add_executable(server ${SOURCE_FILES})


