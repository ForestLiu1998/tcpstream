#pragma once
#include <iostream>
#include "socket_buf_base.h"


/*将socket_buf_base注册到这个类中*/

namespace tcpstream
{
class socket_stream_base : public std::iostream
{
public:
    socket_stream_base();
    virtual ~socket_stream_base();
    virtual void set_connection(int socket_fd) = 0;
    void set_new_buf(socket_buf_base* buf_base);
    int  get_socket_fd();

protected:
    int                 socket_fd_;

};

}