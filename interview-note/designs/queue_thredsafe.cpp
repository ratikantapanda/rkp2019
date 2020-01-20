1.design a stack using two queue
2.Hash function.

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
 
template <typename T>
class Queue
{
 public:
 
  T pop()
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty())
    {
      cond_.wait(mlock);
    }
    auto item = queue_.front();
    queue_.pop();
    return item;
  }
 
  void pop(T& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty())
    {
      cond_.wait(mlock);
    }
    item = queue_.front();
    queue_.pop();
  }
 
  void push(const T& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    queue_.push(item);
    mlock.unlock();
    cond_.notify_one();
  }
 
  void push(T&& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    queue_.push(std::move(item));
    mlock.unlock();
    cond_.notify_one();
  }
 
 private:
  std::queue<T> queue_;
  std::mutex mutex_;
  std::condition_variable cond_;
}
----------
class StackWith2Qs
    {

        Queue<int> firstQ = new Queue<int>(10);
        Queue<int> secondQ = new Queue<int>(10);

        public void Push(int item)
        {
            firstQ.Enqueue(item);
        }

        public int Pop()
        {
            // move all but last item from firstQ to 2nd Q.
            // then the last item remaining is what we need to return
            // after that swap two queue pointers
            while (firstQ.Length > 1)
            {
                secondQ.Enqueue(firstQ.Dequeue());
            }

            int item = firstQ.Dequeue();

            Queue<int> temp = firstQ;
            firstQ = secondQ;
            secondQ = temp;

            return item;
        }
----------------------
template<typename T>
struct stack {
    std::queue<T> q1;
    std::queue<T> q2;
 
    void push(T t)
    { 
        q1.push(t);
    }
 
    T pop()
    {
        T t;
        while (!q1.empty()) {
            t = q1.front();
            q1.pop();
            if (!q1.empty()) q2.push(t);
        }
        while (!q2.empty()) {
            T x = q2.front();
            q2.pop();
            q1.push(x);
        }
        return t;
    }
 
    bool empty()
    {
        return q1.empty();
    }
};
 
int main()
{
    stack<int> s;
    s.push(1);
    std::cout << s.pop() << std::endl;
    s.push(1);
    s.push(2);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
}
