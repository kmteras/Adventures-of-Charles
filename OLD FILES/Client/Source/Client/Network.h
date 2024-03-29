#ifndef NETWORK_H
#define NETWORK_H

class Network {
    static SDLNet_SocketSet server;
    static TCPsocket connection;
    static char buffer[1028];
    static int networkID;
    static bool connected;
public:
    static void Connect(std::string, int);
    static void Disconnect();
    static void SendMessage(std::string);
    static void SendGameData();
    static void ReceiveMessage();
};

#endif