cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES
        src/Board.cpp
        include/Board.h
        src/BoardScanner.cpp
        include/BoardScanner.h
        src/Cell.cpp
        include/Cell.h
        include/Client.h
        src/Client.cpp
        include/ConvertString.h
        src/ConvertString.cpp
        src/Game.cpp
        include/Game.h
        src/GameManager.cpp
        include/GameManager.h
        include/Player.h
        src/Player.cpp
        src/Point.cpp
        include/Point.h
        src/AI.cpp
        include/AI.h
        src/Human.cpp
        include/Human.h
        src/Flip.cpp
        include/Flip.h)

set(TEST_FILES
        src/Board.cpp
        include/Board.h
        src/BoardScanner.cpp
        include/BoardScanner.h
        src/Cell.cpp
        include/Cell.h
        include/Client.h
        src/Client.cpp
        include/ConvertString.h
        src/ConvertString.cpp
        src/Game.cpp
        include/Game.h
        src/GameManager.cpp
        include/GameManager.h
        include/Player.h
        src/Player.cpp
        src/Point.cpp
        include/Point.h
        src/AI.cpp
        include/AI.h
        src/Human.cpp
        include/Human.h
        src/Flip.cpp
        include/Flip.h
        tests/PointTest.cpp
        tests/CellTest.cpp
        tests/BoardTest.cpp
        tests/BoardScannerTest.cpp
        tests/TestMain.cpp
        tests/FlipTest.cpp
        tests/HumanTest.cpp
        tests/AI_Test.cpp)

add_executable(Reversi ${SOURCE_FILES} src/main.cpp)
add_executable(ReversiTest ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(ReversiTest gtest gtest_main)