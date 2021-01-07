# tcpstream
This is a repository which can use "&lt;&lt;" &amp; ">>" to get message from socket

# HOW TO USE
you need include the "socket_stream.h"

```c++
#include "socket_stream.h"
using namespace tcpstream;

void serv()
{
//do socket works first
//accept the clnt by socket function

socket_stream *serv_stream = new socket_stream(50);
serv_stream->set_connection(clnt_fd);

(*serv_stream)<<"hello world!\n";


//do other works you need
}

```
