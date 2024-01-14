#include "ServerStateWrapper.hpp"
#include "basic.hpp"

ServerStateWrapper::ServerStateWrapper(const std::string state_s)
{
    if (state_s != "")
        this->m_state = *parseState(state_s);
}

ServerStateWrapper::~ServerStateWrapper() {}

std::unique_ptr<ServerState> ServerStateWrapper::parseState(const std::string state_s)
{
    if (state_s == "Follower")
        return std::make_unique<ServerState>(ServerState::Follower);
    if (state_s == "Leader")
        return std::make_unique<ServerState>(ServerState::Leader);
    if (state_s == "Candidate")
        return std::make_unique<ServerState>(ServerState::Candidate);
    throw std::runtime_error("Parsing failed");
}

ServerStateWrapper::operator std::string() const
{
    switch (m_state)
    {
    case ServerState::Leader:
        return "Leader";
    case ServerState::Follower:
        return "Follower";        
        break;
    case ServerState::Candidate:
        return "Candidate";
        break;
    default:
        return "Unknown state";
    }
}

ServerState ServerStateWrapper::getState() const
{
    return this->m_state;
}

ServerStateWrapper::operator ServerState() const
{
    return this->m_state;
}