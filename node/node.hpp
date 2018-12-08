#ifndef NODE_HPP_
#define NODE_HPP_

#include "inode.hpp"
#include "connections.hpp"
#include "server.hpp"
#include "factory.hpp"

class Node : virtual public INode {
public:
    Node(std::string ip, std::string port, int nThreads);
    ~Node();

    virtual void initialize(Factory* factory = NULL);

    //start listener for incoming ping and directions
    void start();
    //stop everything
    void stop();

    virtual IConnections* getConnections();
    virtual IStorage* getStorage();

    virtual void setMyIp(std::string ip);
    virtual std::string getMyIp();

    //start iperf command line server and return the port it is open in
    virtual int startIperf();

    virtual Server* getServer();
protected:

    int timerReport;

    //ip of the server node 
    std::string ipS;
    //port of the server node
    std::string portS;

    //ip to differentiate between other nodes in the list and self
    std::string myIp;

    int timeTimerTest;

    bool running;

    std::thread timerThread;
    std::thread timerTestThread;
    Server* server;

    Connections * connections;
    IStorage* storage;

    Factory tFactory;
    Factory * factory;

    int nThreads;

    //timer for hearthbeat
    void timer();

    //timer for latency and bandwidth tests
    void TestTimer();
    
    //test the Bandwidth with another node
    void testBandwidth(std::string ip, int port= -1);
    //test the latency with another node
    void testPing(std::string ip);

    //get the hardware of this node
    void getHardware();
};

#endif















































































