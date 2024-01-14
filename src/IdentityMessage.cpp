#include "IdentityMessage.hpp"
#include "basic.hpp"

IdentityMessage::IdentityMessage(ServerStateWrapper state)
{
    LOG((int)state.getState());
}

IdentityMessage::~IdentityMessage()
{

}


