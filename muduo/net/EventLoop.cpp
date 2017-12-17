
#include "EventLoop.h"
#include <iostream>
#include <assert.h>
#include <poll.h>
#include "base/logging.h"

using namespace std;
using namespace muduo;
thread_local EventLoop * t_loopInThisThread = 0;
EventLoop::EventLoop()
    :looping_(false),
    threadId_(std::this_thread::get_id())
{
    LOG_DEBUG << "EventLoop created " << this << " in thread " << threadId_;
    if( t_loopInThisThread )
    {
        cout << "another eventLoop " << t_loopInThisThread << "exists in this thread"
        << threadId_ << endl;
    }
    else
    {
        t_loopInThisThread = this;
    }
}

EventLoop::~EventLoop()
{
    assert(!looping_);
    t_loopInThisThread = NULL;
}

EventLoop * EventLoop::getEventLoopOfCurrentThread()
{
    return t_loopInThisThread;
}

void EventLoop::loop()
{
    assert(!looping_);
    assertInLoopThread();
    looping_ = true;
    ::poll(NULL,0,5*1000);
    cout << "EventLoop" << this << "stop looping" << endl;
    looping_ = false;
}