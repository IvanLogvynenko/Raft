cmake_minimum_required(VERSION 3.16)
project(Raft)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Werror -fsanitize=address")

add_compile_definitions(ERROR)
add_compile_definitions(FULL_LOGGING)

add_compile_definitions(DEFAULT_PORT="37373")

add_compile_definitions(BUFFER_SIZE=50)
add_compile_definitions(DEFAULT_MESSAGE="")

add_compile_definitions(HANDLING_TIMEOUT=500)
add_compile_definitions(DEFAULT_TIMEOUT=500)

add_compile_definitions(MAX_CONNECTION_ATTEMPTS=50)

set(src_files
    src/Leader.cpp
    src/Candidat.cpp
    src/Follower.cpp

    src/Heartbeat.cpp
    src/IdentityMessage.cpp

    src/Log.cpp

    src/RaftServer.cpp

    src/ServerStateWrapper.cpp

    src/Server.cpp
    src/Client.cpp
    src/Connection.cpp
    src/Message.cpp
    src/Responce.cpp

    src/Timer.cpp
) 

add_executable(leader src/main.cpp ${src_files})
target_include_directories(leader PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(leader PRIVATE INITIAL_STATE="Leader")
target_compile_definitions(leader PRIVATE EXECUTABLE_NAME="LEADER")

add_executable(follower src/main.cpp ${src_files})
target_include_directories(follower PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(follower PRIVATE EXECUTABLE_NAME="FOLLOWER")

add_executable(client src/client.cpp ${src_files})
target_include_directories(client PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(client PRIVATE EXECUTABLE_NAME="CLIENT")