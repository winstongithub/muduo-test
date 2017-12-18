#ifndef _MUDUO_LOGSTREAM_H_
#define _MUDUO_LOGSTREAM_H_
#include "NonCopyable.h"
#include <cstdint>
#include <algorithm>
namespace muduo
{
namespace detail
{

const int kSmallBuffer = 4000;
const int kLargeBuffer = 4000 * 1000;
const char digitsHex[] = "0123456789ABCDEF";

template <int SIZE>
class FixedBuffer : noncopyable
{
  public:
    void append(const char * /*restrict*/ buf, size_t len)
    {
        // FIXME: append partially
        if (static_cast<size_t>(avail()) > len)
        {
            memcpy(cur_, buf, len);
            cur_ += len;
        }
    }
    int avail() const { return static_cast<int>(end() - cur_); }
    char *current() { return cur_; }
    void add(size_t len) { cur_ += len; }

  private:
    const char *end() const { return data_ + sizeof data_; }
    char data_[SIZE];
    char *cur_;
};
};
class LogStream : public noncopyable
{
    typedef LogStream self;

  public:
    typedef detail::FixedBuffer<detail::kSmallBuffer> Buffer;
    size_t convertHex(char buf[], uintptr_t value)
{
    uintptr_t i = value;
    char *p = buf;

    do
    {
        int lsd = static_cast<int>(i % 16);
        i /= 16;
        *p++ = detail::digitsHex[lsd];
    } while (i != 0);

    *p = '\0';
    std::reverse(buf, p);

    return p - buf;
}
  self& operator<<(short);
  self& operator<<(unsigned short);
  self& operator<<(int);
  self& operator<<(unsigned int);
  self& operator<<(long);
  self& operator<<(unsigned long);
  self& operator<<(long long);
  self& operator<<(unsigned long long);
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
    self &operator<<(const void *p)
    {
        uintptr_t v = reinterpret_cast<uintptr_t>(p);
        if (buffer_.avail() >= kMaxNumericSize)
        {
            char *buf = buffer_.current();
            buf[0] = '0';
            buf[1] = 'x';
            size_t len = convertHex(buf + 2, v);
            buffer_.add(len + 2);
        }
        return *this;
    }

  private:
    Buffer buffer_;
    static const int kMaxNumericSize = 32;
};
};
#endif //_MUDUO_LOGSTREAM_H_