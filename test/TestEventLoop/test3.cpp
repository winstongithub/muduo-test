#include "net/EventLoop.h"
#include <iostream>
using namespace muduo;
using namespace std;


int main()
{
    EventLoop loop;
     EventLoop loop1;
 cout << "main():tid=" <<std::this_thread::get_id() << endl;
 std::cout << typeid(this_thread::get_id()).name() << std::endl;  
}