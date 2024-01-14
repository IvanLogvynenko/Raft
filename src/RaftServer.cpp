#include "RaftServer.hpp"

RaftServer::RaftServer(std::string initial_state)
{
    ServerStateWrapper state = ServerStateWrapper(initial_state);
    m_state = std::move(state);
    switch (m_state)
    {
    case ServerState::Leader:
        m_server = Leader();
        break;
    case ServerState::Follower:
        m_server = Follower();
        break;
    case ServerState::Candidate:
        m_server = Candidat();
        break;
    default:
        m_server = Server();
        break;
    }
}

RaftServer::~RaftServer()
{
    LOG("RaftServer::~RaftServer")
}

Connection & RaftServer::awaitNewConnection(std::function<void(Connection&)>)
{
    
}
