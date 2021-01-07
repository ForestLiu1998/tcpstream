g++ -c ../timer/timer.cpp
g++ -c ../timer/pocket_watch.cpp 
echo ofile complete
g++ timer_test.cpp timer.o pocket_watch.o  -lpthread

