#pragma once
#include "ServerState.hpp"

#include <string>
#include <memory>

class ServerStateWrapper
{
private:
    ServerState state;
public:
    ServerStateWrapper(const std::string = std::string(""));
    ~ServerStateWrapper();

    static std::unique_ptr<ServerState> parseState(const std::string = std::string(""));

    inline ServerState getState() const;
    inline operator ServerState();
};