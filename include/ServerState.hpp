#pragma once

enum class ServerState {
    Follower = 'f',
    Candidate = 'c',
    Leader = 'l'
};