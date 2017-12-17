#ifndef _MUDUO_EVENTLOOP_H_
#define _MUDUO_EVENTLOOP_H_
#include "base/NonCopyable.h"
#include "thread"

namespace muduo{
class EventLoop;
class EventLoop : noncopyable
{
public:
    EventLoop();
    ~EventLoop();
    void loop();
    static EventLoop * getEventLoopOfCurrentThread();
    void assertInLoopThread()
    {
        if( !isInLoopThread())
        {
            abortNotInLoopThread();
        }
    }
    bool isInLoopThread() const { return threadId_ == std::this_thread::get_id();}
private:
    void abortNotInLoopThread();
    bool looping_;
    const std::thread::id threadId_;
};
};
#endif//_MUDUO_EVENTLOOP_H_
