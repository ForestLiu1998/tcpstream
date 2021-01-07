#include "../timer/timer.h"
#include "../timer/pocket_watch.h"
#include <iostream>
#include <thread>
using namespace std;
using namespace tcpstream;

int count = 0;

void timeout_cb()
{
    cout<<"*******************************\n";
    cout<<"time out!"<<count<<endl;
    cout<<"time is :"<<time(NULL)<<endl;
    cout<<"*******************************\n";
    count++;
    
    
}



void attach_a_timer(int seconds)
{
    cout<<"-------------------------------\n";
    cout<<"attach a timer for "<<seconds<<" seconds"<<endl;
    cout<<"timeout will be "<<seconds+time(NULL)<<endl;
    cout<<"-------------------------------\n";
    pocket_watch* new_watch = new pocket_watch(function<void()>(timeout_cb));
    new_watch->reset(time(NULL)+seconds);
}

int main()
{
    
    Timer::getInstance();
    vector<thread> tv;
    cout<<"sys ready!\n";
    
    tv.push_back(thread(attach_a_timer,5));
    tv[0].join();
    tv.push_back(thread(attach_a_timer,7));
    tv[1].join();
    tv.push_back(thread(attach_a_timer,13));
    tv[2].join();
    while(1);
}


