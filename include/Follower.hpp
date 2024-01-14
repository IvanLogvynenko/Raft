#pragma once

#include "Server.hpp"

class Follower : public Server
{
private:
    Client m_client;
public:
    Follower();
    ~Follower();
};
