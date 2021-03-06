#include "net/EventLoop.h"
#include <iostream>
using namespace muduo;
using namespace std;

void threadFunc()
{
    cout << "threadFunc():tid=" <<std::this_thread::get_id() << endl;

    EventLoop loop;
    loop.loop();
}

int main()
{
    cout << "main():tid=" <<std::this_thread::get_id() << endl;
    EventLoop loop;
    std::thread t(threadFunc);
    loop.loop();
    t.join();
}