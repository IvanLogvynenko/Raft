#pragma once

#include "Candidat.hpp"
#include "Follower.hpp"
#include "Leader.hpp"

#include "Heartbeat.hpp"

#include <memory>

class RaftServer
{
private:
    std::unique_ptr<Server> m_server;
public:
    RaftServer();
    ~RaftServer();
};