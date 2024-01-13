#include "RaftServer.hpp"

#ifndef INITIAL_STATE
    #define INITIAL_STATE "Follower"
#endif // !INITIAL_STATE

int main() {
    RaftServer server = RaftServer();
}