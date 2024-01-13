#pragma once

#include "Message.hpp"

class Heartbeat : public Message
{
private:
public:
    Heartbeat();
    ~Heartbeat();
};