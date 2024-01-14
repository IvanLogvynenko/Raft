#include "Client.hpp"
#include "basic.hpp"

int main(int argc, char** argv){
    if (argc != 3) {
        LOG("Usage: " << argv[0] << " [target_ip] [target_port]");
        return -1;
    }
    Client client = Client();
    client.connectTo(argv[1], argv[2]);
}