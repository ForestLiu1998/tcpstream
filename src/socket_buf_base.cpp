#include "socket_buf_base.h"
#include <iostream>

using namespace tcpstream;

socket_buf_base::socket_buf_base(size_t buf_size):buf_size_(buf_size),malloced(false)
{
    
}

socket_buf_base::~socket_buf_base()
{
    free_buf();
}


void socket_buf_base::malloc_buf()
{
    char* gbuf = new char[buf_size_];
    char* pbuf = new char[buf_size_];

    setg(gbuf,gbuf,gbuf);
    setp(pbuf,pbuf+buf_size_);

    malloced = true;
}

void socket_buf_base::free_buf()
{
    delete[] eback();
    delete[] pbase();
    malloced = false;
}

int socket_buf_base::underflow()
{
    //std::cout<<"underflow called\n";
    //all input seq read over,read new data from socket recv buffer 
    int ret = precv(eback(),buf_size_,0);
    //std::cout<<"get "<<ret<<" chars\n";
    //std::cout<<eback()<<std::endl;
    if(ret>0)
    {
        //read sth from socket recv buffer,reset the input sequence
        setg(eback(),eback(),eback()+ret);
        return traits_type::to_int_type(*gptr());//return the current char,cast to int type
    }
    else
    {
        //socket recv buffer empty,raise EOF
        //std::cout<<"EOF!\n";
        return traits_type::eof();
    }
}

int socket_buf_base::sync()
{
    //use sync to move data into socket send buffer
    //std::cout<<"sync called\n";
    int sent = 0;
    int total = pptr() - pbase();//check how much left waiting in output sequence
    while(sent<total)
    {
        int ret = psend(pbase()+sent,total - sent,0);//sent [sent,total] chars by socket
        if(ret > 0)
        {
            sent+=ret;//sent success
        }
        else
        {
            return -1; //socket sent buf full,send failed
        }
    }

    setp(pbase(),pbase()+buf_size_); //reset the output sequence pointers
    pbump(0); //pptr = pbase
    return 0; //sync success
}


int socket_buf_base::overflow(int c)
{
    //output seq full,send all data,called by sputc
    //std::cout<<"overflow called\n";
    if(-1 == sync())//send data
    {
        //socket sent buf full,raise EOF
        return traits_type::eof();
    }
    else
    {
        if(!traits_type::eq_int_type(c,traits_type::eof()))
        {
            /*new char will be send,re-call sputc to put char into output seq*/
            sputc(traits_type::to_char_type(c));
        }
        return traits_type::not_eof(c);
    }
    
}