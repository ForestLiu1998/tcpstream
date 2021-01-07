#pragma once
#include "socket_buf_base.h"
#include "socket_stream_base.h"
#include <sys/socket.h>

namespace tcpstream
{
class socket_stream : public socket_stream_base,public socket_buf_base
{
public:
    socket_stream(std::size_t buf_size);
    virtual ~socket_stream();
    void set_connection(int socket_fd);
    void swap_connection(int socket_fd);

    int send_now();
    

protected:
    virtual ssize_t precv(void *buf,std::size_t len,int flags);
    virtual ssize_t psend(const void *buf,std::size_t len,int flags);
    bool established;
};


}