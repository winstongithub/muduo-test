#include "../base/MutexLockGuard.h"
#include <iostream>
#include<thread>
using namespace muduo;
class Counter:noncopyable
{
    public:
    Counter() :m_value(0){}
    int64_t value() const
    {
        MutexLockGuard lock(m_mutex);
        return m_value;
    }
    int64_t getAndIncrease()
    {
        MutexLockGuard lock(m_mutex);
        int64_t ret = m_value++;
        return ret;
    }
    private:
    int64_t m_value;
    mutable std::mutex m_mutex;
};
void addValue(Counter *counter)
{
    for( auto i=0; i<100000; i++)
    {
        counter->getAndIncrease();
    }
}
int main()
{
    Counter counter;
    std::thread th1(addValue,&counter);
    std::thread th2(addValue,&counter);
    std::cout << counter.value() << std::endl;
    th1.join();
    std::cout << counter.value() << std::endl;
    th2.join();
    std::cout << counter.value() << std::endl;
    

}