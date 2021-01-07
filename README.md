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
- [x] 整理Markdown手册
- [ ] 改善项目
   - [x] 优化首页显示方式
   - [x] 修复闪退问题
   - [ ] 修复视频卡顿
- [ ] A3项目修复
   - [x] 修复数值错误
