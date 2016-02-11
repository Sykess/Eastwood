#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
using namespace std;

// Program displays race conditions, before using the "fix" lines, a number close to,
// but not at the expected 1000 will display.  Using the fix lines will display 1000.


//void func(std::atomic<int>& counter); //fix
void func(int& counter);

int main()
   {
       int counter = 0;
       std::chrono::seconds sec(1);
       //std::atomic<int> counter(0);  //fix
       std::vector<std::thread> threads;
       for (int i = 0; i < 10; ++i) {
           threads.push_back(std::thread{ func, std::ref(counter) });
       }
       for (auto& t : threads) {
           t.join();
       }
       std::cout << "Result = " << counter << std::endl;
   }


//void func(std::atomic<int>& counter)  //fix
void func(int& counter)
   {
       for (int i = 0; i < 100; ++i) {
           ++counter;
           std::this_thread::sleep_for(std::chrono::milliseconds(1));
       }
   }
