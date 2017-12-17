#ifndef _MUDUO_LOGSTREAM_H_
#define _MUDUO_LOGSTREAM_H_
#include "NonCopyable.h"
namespace muduo
{
class LogStream : public noncopyable
{
    typedef LogStream self;
    self &operator<<(const char *str)
    {
        if (str)
        {
            buffer_.append(str, strlen(str));
        }
        else
        {
            buffer_.append("(null)", 6);
        }
        return *this;
    }
private:
  Buffer buffer_;
};
};
#endif //_MUDUO_LOGSTREAM_H_