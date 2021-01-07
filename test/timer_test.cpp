#include "../timer/timer.h"
#include "../timer/pocket_watch.h"
#include <iostream>
#include <thread>
using namespace std;
using namespace tcpstream;

int count = 0;

void timeout_cb()
{
    cout<<"time out!"<<count<<endl;
    count++;
}



void attach_a_timer(int seconds)
{
    cout<<"attach a timer for "<<seconds<<"seconds"<<endl;
    pocket_watch* new_watch = new pocket_watch(function<void()>(timeout_cb));
    new_watch->reset(time(NULL)+seconds);
}

int main()
{
    
    Timer::getInstance();
    vector<thread> tv;
    cout<<"sys ready!\n";
    for(int i=3;i<4;i++)
    {
        tv.push_back(thread(attach_a_timer,i));
    }
    while(1);
}


