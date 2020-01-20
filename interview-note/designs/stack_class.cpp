/* template < typename T, typename Container = std::deque < T > >class stack
{
public:
  explicit stack (const Container &);
  explicit stack (Container && = Container ());
  template < class Alloc > explicit stack (const Alloc &);
  template < class Alloc > stack (const Container &, const Alloc &);
  template < class Alloc > stack (Container &&, const Alloc &);
  template < class Alloc > stack (stack &&, const Alloc &);
  bool empty () const;
  size_t size () const;
  T & top ();
  T const & top () const;
  void push (T const &);
  void push (T &&);
  void pop ();
  void swap (stack &&);
};

Note:- Not Thread safe code
stack < int >s;
if (!s.empty ())
  {
    int const value = s.top ();
    s.pop ();
    do_something (value);
  }

  std::vector<int> result;
  some_stack.pop(result);

  
-----------------------------------------------
*/
#include <exception>
#include <memory>
#include <mutex>
#include <stack>
struct empty_stack: std::exception
{
const char* what() const throw();
};
template < typename T > 
class threadsafe_stack
{
private:
  std::stack < T > data;
  mutable std::mutex m;
public:
  threadsafe_stack ()
  {
  }
  threadsafe_stack (const threadsafe_stack & other)
  {
    std::lock_guard < std::mutex > lock (other.m);
    data = other.data;
  }
  threadsafe_stack & operator= (const threadsafe_stack &) = delete;
  void push (T new_value)
  {
    std::lock_guard < std::mutex > lock (m);
    data.push (new_value);
  }
  std::shared_ptr < T > pop ()
  {
    std::lock_guard < std::mutex > lock (m);
    if (data.empty ())
      throw empty_stack ();
    std::shared_ptr < T > const res (std::make_shared < T > (data.top ()));
    data.pop ();
    return res;
  }
  void pop (T & value)
  {
    std::lock_guard < std::mutex > lock (m);
    if (data.empty ())
      throw empty_stack ();
    value = data.top ();
    data.pop ();
  }
  bool empty () const
  {
    std::lock_guard < std::mutex > lock (m);
    return data.empty ();
  }
};
int main()
{
	return 0;
}
