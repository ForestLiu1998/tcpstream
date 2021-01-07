g++ -c ../timer/pocket_watch.cpp ../timer/timer.cpp 
echo ofile complete
g++ timer_test.cpp pocket_watch.o timer.o  -lpthread

