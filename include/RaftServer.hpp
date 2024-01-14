#pragma once

#include "Candidat.hpp"
#include "Follower.hpp"
#include "Leader.hpp"

#include "Heartbeat.hpp"
#include "IdentityMessage.hpp"

#include "ServerStateWrapper.hpp"

#include "Connection.hpp"

#include <memory>

#ifndef INITIAL_STATE
    #define INITIAL_STATE "Follower"
#endif // !INITIAL_STATE

class RaftServer
{
private:
    ServerStateWrapper m_state;
    std::unique_ptr<Server> m_server;

    std::vector<Connection> m_clients;
    std::vector<Connection> m_servers;
public:
    RaftServer(std::string initial_state = INITIAL_STATE);
    ~RaftServer();
    
};