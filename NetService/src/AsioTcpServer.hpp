#ifndef ASIOTCPSERVER_H_
#define ASIOTCPSERVER_H_

#include "asio.hpp"
#include "SocketServer.hpp"
#include "AsioTcpConnection.hpp"

class AsioTcpServer :public SocketServer
{
public:
    AsioTcpServer();
    ~AsioTcpServer();
    virtual bool start(unsigned int port);
private:
    asio::io_service& io_service_;
    asio::ip::tcp::acceptor acceptor_;
    void worker();
	void AcceptHandler( AsioTcpConnection* conn, const asio::error_code& error);
};


#endif /* ASIOTCPSERVER_H_ */