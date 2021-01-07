#include "pocket_watch.h"
using namespace tcpstream;



pocket_watch::pocket_watch(std::function<void ()> times_up_cb):times_up_cb_(times_up_cb)
{

};

void pocket_watch::reset(time_t next_time)
{
    next_time_ = next_time;
    Timer::getInstance()->set_time(this);
};

void pocket_watch::times_up()
{
    time_t now = time(NULL);
    if(next_time_ > now)//do not times up
    {
        reset(next_time_);
        queue_time_ = next_time_;
    }
    else
    {   //times up,use time_up_callback
        times_up_cb_();
    }

};

time_t pocket_watch::get_next_time()
{
    return next_time_;
}

time_t pocket_watch::get_queue_time()
{
    return queue_time_;
}
