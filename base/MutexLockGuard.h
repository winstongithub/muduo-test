#ifndef _MUDUO_BASE_MUTEXLOCKGUARD_H_
#define _MUDUO_BASE_MUTEXLOCKGUARD_H_
#include "NonCopyable.h"
#include <mutex>

namespace muduo
{
    class MutexLockGuard : noncopyable
    {
        public:
        MutexLockGuard( std::mutex &owern)
            :m_owern{owern}
        {
            m_owern.lock();
        }
        ~MutexLockGuard()
        {
            m_owern.unlock();
        }
        std::mutex & m_owern;
    };
};

#endif //_MUDUO_BASE_MUTEXLOCKGUARD_H_