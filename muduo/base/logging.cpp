#include "logging.h"
using namespace muduo;

extern Logger::LogLevel g_logLevel;
Logger::LogLevel Logger::logLevel()
{
    return g_logLevel;
}

Logger::Logger(SourceFile file, int line, LogLevel level, const char *func)
     : impl_(level, 0, file, line)
{

}