#pragma once

#include <streambuf>

namespace tcpstream
{
    class socket_buf_base : public std::streambuf
    {
    public:
        socket_buf_base(std::size_t buf_size);
        virtual ~socket_buf_base();
        
        void malloc_buf();
        void free_buf();
        int underflow();
        int overflow(int c = traits_type::eof());
        int sync();
    
    protected:
        virtual ssize_t precv(void *buf,std::size_t len,int flags) = 0;
        virtual ssize_t psend(const void *buf,std::size_t len,int flags) = 0;

        bool malloced;

        const std::size_t buf_size_;
    };

}