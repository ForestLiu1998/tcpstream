# tcpstream
This is a repository which can use "&lt;&lt;" &amp; ">>" to get message from socket,
and containing some other little tools

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
# Warning
you must use a pointer and new this obj,otherwise dual free() error will happen,idk why,wish some guy could tell me!!!!!

# TODO list
- [x] socket_stream class
- [ ] more test for robustness
- [ ] timeout detection
- [ ] thread safe
