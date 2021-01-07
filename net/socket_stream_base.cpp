#include "socket_stream_base.h"

using namespace tcpstream;

socket_stream_base::socket_stream_base():std::iostream(NULL)
{};

socket_stream_base::~socket_stream_base()
{
    
}


void socket_stream_base::set_new_buf(socket_buf_base* buf_base)
{
    std::streambuf* old_buf = rdbuf(buf_base);
    delete old_buf;
};

int socket_stream_base::get_socket_fd()
{
    return socket_fd_;
}


