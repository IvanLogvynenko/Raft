#include "IdentityMessage.hpp"

IdentityMessage::IdentityMessage(ServerStateWrapper state) : m_state(state)
{
    std::string data = "IdentityMessage<";
    data.append(m_state);
    data.append(">");
    this->m_data = std::move(data);
}
IdentityMessage::IdentityMessage(std::string data) : 
    Responce(data),
    m_state(parse(data))
{}

IdentityMessage::~IdentityMessage() {}

ServerStateWrapper IdentityMessage::parse(std::string data)
{
    std::regex pattern("<[a-zA-Z]+>");
    std::smatch match;
    std::regex_search(data, match, pattern);

    std::string first_match = match[0];
    first_match = first_match.substr(1, first_match.length() - 2);
    return ServerStateWrapper(first_match);
}
