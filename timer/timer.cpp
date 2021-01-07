#include "timer.h"
#include<iostream>

using namespace tcpstream;

extern "C"
{
void tick_outside(int id=0)
{
    Timer::getInstance()->tick(0);
};
}

Timer* Timer::getInstance()
{
    //thread safe
    static Timer timer_;
    return &timer_;
}

void Timer::set_time(pocket_watch& pw)
{
    mtx.lock();
    //std::cout<<"new clock set:"<<pw.get_queue_time()<<std::endl;
    //std::cout<<"now time:"<<time(NULL)<<std::endl;
    time_heap_.push(pw);
    mtx.unlock();
};


void Timer::tick(int id)
{
    std::cout<<"heap size: "<<time_heap_.size()<<std::endl;

    if(time_heap_.empty())
    {
        //没有pw加载，等10s回来看看
        std::cout<<"empty queue,return later\n";
        alarm(10);
        return;
    }

    mtx.lock();
    pocket_watch pw = time_heap_.top();

    //std::cout<<"ready to pop,time now is:"<<time(NULL)<<std::endl;
    //std::cout<<"the front time is: "<<pw.get_queue_time()<<std::endl;

    while(pw.get_queue_time()<=time(NULL))
    {
        //将所有的超过时间的pw全都停掉
        time_heap_.pop();
        //std::cout<<"got time:"<<pw.get_queue_time()<<std::endl;
        pw.times_up();
        if(time_heap_.empty())
        {
            //std::cout<<"empty queue,return later\n";
            alarm(3);
            return;
        }
        pw = time_heap_.top();
        //std::cout<<"go again?\n";
    }

    mtx.unlock();
    
    //std::cout<<"finally out\n";
    time_t next_tick = pw.get_next_time();

    
    if(!((next_tick - time(NULL))>0))
    {
        //该pw时间刷新过，以下次时间为准，重新tick一次
        Timer::tick(0);
        //std::cout<<"we gonna do it again\n";
    }
    else
    {
        //读取下一pw时间，进行alarm
        alarm(next_tick-time(NULL));
        //std::cout<<"next alarm set to "<<next_tick-time(NULL)<<" seconds\n";
    }
};


Timer::Timer()
{
    signal(SIGALRM,tick_outside);
    alarm(2);
};






