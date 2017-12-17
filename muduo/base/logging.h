#ifndef _MUDUO_LOGGING_H_
#define _MUDUO_LOGGING_H_
#include "SourceFile.h"
#include "LogStream.h"
namespace muduo
{
class Logger
{
  public:
    enum LogLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NUM_LOG_LEVELS,
    };
    Logger(SourceFile file, int line, LogLevel level, const char *func);
    static LogLevel logLevel();
    LogStream &stream() { return impl_.stream_; }

    class Impl
    {
      public:
        typedef Logger::LogLevel LogLevel;
        Impl(LogLevel level, int old_errno, const SourceFile &file, int line);
        LogStream stream_;

    };

    Impl impl_;
};
#define LOG_DEBUG                                          \
    if (muduo::Logger::logLevel() <= muduo::Logger::DEBUG) \
    muduo::Logger(__FILE__, __LINE__, muduo::Logger::DEBUG, __func__).stream()
};

#endif //_MUDUO_LOGGING_H_