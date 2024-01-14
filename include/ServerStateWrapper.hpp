#pragma once
#include "ServerState.hpp"

#include <string>
#include <memory>

class ServerStateWrapper
{
private:
    ServerState m_state;
public:
    ServerStateWrapper(const std::string = std::string(""));
    ~ServerStateWrapper();

    static std::unique_ptr<ServerState> parseState(const std::string = std::string(""));

    operator std::string() const;

    ServerState getState() const;
    operator ServerState() const;
};