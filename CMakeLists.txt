cmake_minimum_required(VERSION 3.16)
project(Raft)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Werror -fsanitize=address")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/references/")
include("references/ServerClientLib.cmake")

add_executable(main 
    src/main.cpp

    src/Leader.cpp
    src/Candidat.cpp
    src/Follower.cpp

    src/RaftServer.cpp
)
target_link_libraries(main PUBLIC ServerClientLib)
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)