cmake_minimum_required(VERSION 3.16)
project(Raft)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Werror -fsanitize=address")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/references/")
include("references/ServerClientLib.cmake")

add_compile_definitions(ERROR)
add_compile_definitions(FULL_LOGGING)

set(src_files 
    src/main.cpp

    src/Leader.cpp
    src/Candidat.cpp
    src/Follower.cpp

    src/Heartbeat.cpp

    src/RaftServer.cpp

    src/ServerStateWrapper.cpp
) 

add_executable(leader ${src_files})
target_link_libraries(leader PUBLIC ServerClientLib)
target_include_directories(leader PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(leader PRIVATE INITIAL_STATE="Leader")
target_compile_definitions(leader PRIVATE EXECUTABLE_NAME="LEADER")

add_executable(follower ${src_files})
target_link_libraries(follower PUBLIC ServerClientLib)
target_include_directories(follower PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(follower PRIVATE EXECUTABLE_NAME="FOLLOWER")