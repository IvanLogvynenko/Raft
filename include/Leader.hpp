#pragma once

#include "Server.hpp"

#include <vector>
#include <queue>

#include <atomic>
#include <mutex>
#include <thread>

class Leader : public Server
{
private:
    std::vector<Connection> m_servers;

    std::queue<Message> m_messages;
    std::mutex m_message_mutex;
    std::atomic_bool m_hearbeating;
public:
    Leader();
    ~Leader();

    void startHeartbeat(int delay);
    void stopHeartbeat();
};
