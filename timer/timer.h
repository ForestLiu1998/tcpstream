#pragma once 
#include "pocket_watch.h"
#include <unordered_map>
#include <queue>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
namespace tcpstream
{

class pocket_watch;
void tick_outside(int id);

class Timer
{
public:
    static Timer* getInstance();

    void set_time(pocket_watch* pw);
    void tick(int id=0);

protected:
    Timer();

    void times_up(pocket_watch* pw);

    std::priority_queue<pocket_watch*,std::vector<pocket_watch*> > time_heap_;
    
};



}