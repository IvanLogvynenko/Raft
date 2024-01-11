cmake_minimum_required(VERSION 3.16)
project(Raft)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Werror -fsanitize=address")

include("references/ServerClientLib.cmake")

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE ServerClientLib)