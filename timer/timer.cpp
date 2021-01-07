#include "timer.h"

using namespace tcpstream;

void tick_outside(int id)
{
    Timer::getInstance()->tick(0);
};


Timer* Timer::getInstance()
{
    //thread safe
    static Timer timer_;
    return &timer_;
}

void Timer::set_time(pocket_watch* pw)
{
    time_heap_.push(pw);
};


void Timer::tick(int id)
{
    if(time_heap_.empty())
    {
        //没有pw加载，等10s回来看看
        alarm(10);
        return;
    }

    pocket_watch* pw = time_heap_.top();
    while(pw->get_queue_time()<=time(NULL))
    {
        //将所有的超过时间的pw全都停掉
        time_heap_.pop();
        pw->times_up();
        pw = time_heap_.top();
    }
    
    time_t next_tick = time_heap_.top()->get_next_time();

    if(!((next_tick - time(NULL))>0))
    {
        //该pw时间刷新过，以下次时间为准，重新tick一次
        Timer::tick(0);
    }
    else
    {
        //读取下一pw时间，进行alarm
        alarm(next_tick-time(NULL));
    }
};


Timer::Timer()
{
    signal(SIGALRM,tick_outside);
    alarm(10);
};






