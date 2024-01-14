#pragma once

#include "Responce.hpp"
#include "ServerStateWrapper.hpp"

#include "basic.hpp"

#include <regex>
#include <string.h>

class IdentityMessage : public Responce
{
private:
    ServerStateWrapper m_state;
public:
    IdentityMessage(std::string data);
    IdentityMessage(ServerStateWrapper state);
    ~IdentityMessage();
    static ServerStateWrapper parse(std::string = "");

    operator std::string();
    operator const char*();
};