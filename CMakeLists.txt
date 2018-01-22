cmake_minimum_required(VERSION 3.5)
project(chepp)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/src)
set(SOURCE_FILES
        src/board.h
        src/board.cpp
        src/piece.h
        src/king.cpp
        src/queen.cpp
        src/pawn.cpp
        src/rook.cpp
        src/knight.cpp
        src/bishop.cpp
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_executable(chepp main.cpp ${SOURCE_FILES})
target_link_libraries(chepp -static-libgcc -static-libstdc++)
