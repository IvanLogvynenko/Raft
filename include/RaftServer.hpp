#pragma once

#include "Candidat.hpp"
#include "Follower.hpp"
#include "Leader.hpp"

#include "Log.hpp"

#include "Heartbeat.hpp"
#include "IdentityMessage.hpp"

#include "ServerStateWrapper.hpp"

#include "Connection.hpp"
#include "Client.hpp"

#include <queue>
#include <vector>

#include <memory>

#ifndef INITIAL_STATE
    #define INITIAL_STATE "Follower"
#endif // !INITIAL_STATE

class RaftServer
{
private:
    Server m_server;

    ServerStateWrapper m_state;

    std::vector<Log> m_logs;
public:
    RaftServer(std::string initial_state = INITIAL_STATE);
    ~RaftServer();

    Connection& awaitNewConnection(std::function<void(Connection&)> = nullptr);
};