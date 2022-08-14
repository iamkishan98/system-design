#include <iostream>
#include "singleton.h"
#include "mingw.thread.h"
#include <mutex>
using namespace std;

static int val;

Singleton *Singleton:: Instance = NULL;

Singleton :: Singleton()
{
    cout<<"Singleton class is instantiated"<<endl;
    val ++;
}

Singleton *Singleton:: getInstance(){
    if(!Instance){
        Instance = new Singleton();
    }
    return Instance;
}

void first(){
    Singleton *s1 = Singleton::getInstance();
    cout<<val<<endl;
}
void second(){
    Singleton *s2 = Singleton::getInstance();
    cout<<val<<endl;
}

int main()
{
    thread t1();
    t1.join();
    thread t2();
    t2.join();
    return 0;
}