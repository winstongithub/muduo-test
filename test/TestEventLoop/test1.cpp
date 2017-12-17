#include "net/EventLoop.h"
using namespace muduo;

void threadFunc()
{
    printf("threadFunc():tid= %d \n",std::this_thread::get_id());
    EventLoop loop;
    loop.loop();
}

int main()
{
    printf("main():tid=%d\n",std::this_thread::get_id());
    EventLoop loop;
    std::thread t(threadFunc);
    loop.loop();
    t.join();
}