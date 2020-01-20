#include <iostream>

using namespace std;

struct  Singleton 
{
private:
   static Singleton* pInstance;
   static std::mutex m_mutex;
public:
   static Singleton* instance();
};
 
Singleton* Singleton::pInstance = 0;
std::mutex Singleton::m_mutex;
 
/*Singleton* Singleton::instance() 
{
   if (pInstance == 0) 
   {
      pInstance = new Singleton;
   }
   return pInstance;
}
*/
//Duble checked locking pattern
Singleton* Singleton::instance() 
{
   if (pInstance == 0) {
      std::lock_guard<std::mutex> lock(m_mutex);
      //Lock lock;
      if (pInstance == 0) 
      {
         pInstance =new Singleton; 
      }
   }
   return pInstance;
}
//DCLP and Instruction Ordering
Singleton* Singleton::instance() 
{
   if (pInstance == 0) 
   {
      Lock lock;
      if (pInstance == 0) 
      {
         pInstance = // Step 3
            operator new(sizeof(Singleton)); // Step 1
         new (pInstance) Singleton; // Step 2
      }
   }
   return pInstance;
}
/*
 * If one wished to use this idiom in C++11 (For instance with Visual Studio 2013 because lack of "Magic statics" [3] ) they should use acquire and release fences:[4]
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}
*/
int main()
{
	return 0;
}
