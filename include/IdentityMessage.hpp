#include "Responce.hpp"
#include "ServerStateWrapper.hpp"

class IdentityMessage : public Responce
{
private:
public:
    IdentityMessage(ServerStateWrapper state);
    ~IdentityMessage();
    static ServerStateWrapper parse(std::string = "");

    operator std::string();
    operator const char*();
};