#include "RaftServer.hpp"

RaftServer::RaftServer(std::string initial_state)
{
    ServerStateWrapper state = ServerStateWrapper(initial_state);
    m_state = std::move(state);
    switch (m_state)
    {
    case ServerState::Leader:
        m_server = std::make_unique<Leader>();
        break;
    case ServerState::Follower:
        m_server = std::make_unique<Leader>();
    default:
        break;
    }   
}

RaftServer::~RaftServer()
{
    LOG("RaftServer::~RaftServer")
}