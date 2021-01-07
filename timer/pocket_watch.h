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

    bool operator()(pocket_watch& x,pocket_watch& y)
    {
        return x.get_queue_time()>y.get_queue_time();//小的优先级高 ,从小到大排 
    };

private:
    time_t next_time_;
    time_t queue_time_;
    //connection* master_connection_;

    std::function<void()> times_up_cb_;
};



}
