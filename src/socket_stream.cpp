#include "socket_stream.h"
using namespace tcpstream;

socket_stream::socket_stream(std::size_t buf_size):socket_stream_base(),socket_buf_base(buf_size),established(false)
{};

socket_stream::~socket_stream()
{
    
};


void socket_stream::set_connection(int socket_fd)
{
    socket_fd_ = socket_fd;
    //malloc buffer for this connection
    malloc_buf();
    set_new_buf(this);
    established = true;
}

void socket_stream::swap_connection(int socket_fd)
{
    if(!established)
    return set_connection(socket_fd);
    //TODO: sync the buf and reset it
    socket_fd_ = socket_fd;
    overflow();
}

int socket_stream::send_now()
{
    return overflow();
}

ssize_t socket_stream::precv(void *buf,std::size_t len,int flags)
{
    //recv from socket
    if(!established)
    {
        return -1;
    }
    return recv(socket_fd_,buf,len,flags);
};

ssize_t socket_stream::psend(const void *buf,std::size_t len,int flags)
{
    //recv from socket
    if(!established)
    return -1;
    return send(socket_fd_,buf,len,flags);
};
