#include "ServerStateWrapper.hpp"

ServerStateWrapper::ServerStateWrapper(const std::string state_s)
{
    this->state = *parseState(state_s);
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

ServerState ServerStateWrapper::getState() const
{
    return this->state;
}

ServerStateWrapper::operator ServerState() const
{
    return this->state;
}