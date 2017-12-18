#include "logging.h"
using namespace muduo;

Logger::LogLevel initLogLevel()
{
  if (::getenv("MUDUO_LOG_TRACE"))
    return Logger::TRACE;
  else if (::getenv("MUDUO_LOG_DEBUG"))
    return Logger::DEBUG;
  else
    return Logger::INFO;
}
Logger::LogLevel g_logLevel = initLogLevel();

Logger::LogLevel Logger::logLevel()
{
    return g_logLevel;
}

Logger::Logger(SourceFile file, int line, LogLevel level, const char *func)
     : impl_(level, 0, file, line)
{

}