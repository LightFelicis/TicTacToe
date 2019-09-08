cmake_minimum_required (VERSION 2.6)
project (TicTacToe)


include_directories(include)

set(SOURCES
    src/Board.cpp
    src/GameView.cpp
    src/Logic.cpp
    src/PlatformDependent.cpp
    src/TicTacToe.cpp
    )
add_executable(TicTacToe ${SOURCES})
