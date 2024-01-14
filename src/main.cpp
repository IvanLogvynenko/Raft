#include "RaftServer.hpp"
#include "IdentityMessage.hpp"

#include <functional>

#ifndef INITIAL_STATE
    #define INITIAL_STATE "Follower"
#endif // !INITIAL_STATE

int main() {
    auto workload = [&](std::string data) {
        return std::hash<std::string>{}(data);
    };
    LOG(workload("some"));
    RaftServer server = RaftServer(INITIAL_STATE);
}