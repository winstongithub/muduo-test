#ifndef _MUDUO_BASE_NONCOPYABLE_H_
#define _MUDUO_BASE_NONCOPYABLE_H_
namespace muduo
{
    class noncopyable
    {
        protected:
        noncopyable()=default;
        ~noncopyable()=default;
        private:
        noncopyable (const noncopyable &) = delete;
        noncopyable operator=(const noncopyable &)=delete;
    };
};




#endif//_MUDUO_BASE_NONCOPYABLE_H_
