#include <iostream>
#include <thread>
using namespace std;



int main()
{
    []  {cout << "hello"; } ();
    //auto func = [] () { cout << "Hello world"; };
    
    //func();
    
}



