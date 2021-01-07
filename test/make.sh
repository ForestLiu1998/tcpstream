g++ -c ../src/socket_buf_base.cpp
g++ -c ../src/socket_stream_base.cpp
g++ -c ../src/socket_stream.cpp
g++ stream_test.cpp socket_buf_base.o socket_stream.o socket_stream_base.o -lpthread
./a.out