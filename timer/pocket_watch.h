#pragma once
#include "timer.h"
#include <time.h>
#include <functional>

namespace tcpstream
{
class Timer;

class pocket_watch
{
public:
    pocket_watch(std::function<void ()> times_up_cb);
    void reset(time_t next_time);
    void times_up();

    time_t get_next_time();

    time_t get_queue_time();

     bool operator <(const pocket_watch &b)const 
    {
        return queue_time_>b.queue_time_;
    };


private:
    time_t next_time_;
    time_t queue_time_;
    bool   attached_;
    //connection* master_connection_;

    std::function<void()> times_up_cb_;
};




}
