#ifndef CONNECTIONS_HPP_
#define CONNECTIONS_HPP_

class Node;

#include "iconnections.hpp"
#include "queue.hpp"
#include "message.hpp"
#include "storage.hpp"

#include <thread>

class Connections : public IConnections {
private:
    void handler(int fd, Message &m);

    Storage storage;
    Node* parent;

public:
    Connections();
    Connections(Node *parent, int nThread);
    ~Connections();

    //ip:port
    bool sendHello(std::string ipS);
    bool sendUpdate(std::string ipS);

    //return the port for the test
    int sendStartBandwidthTest(std::string ip);

    Storage* getStorage();
};

#endif