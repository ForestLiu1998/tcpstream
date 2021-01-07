#pragma once
#include "socket_stream.h"

enum ERROR_CODE
{
    TIMEOUT
};  

namespace tcpstream
{
class connection
{
public:
virtual int establish_connect(int fd) = 0;
virtual int close_connect();
virtual int hang_on();
virtual void times_up();


protected:
socket_stream*      stream_handler_;
time_t              expire_time;


};

}