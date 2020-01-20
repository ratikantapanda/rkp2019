#include <iostream>
using namespace std;

template<typename T>
struct sharedptr
{
	struct pointerval
	{
		T* ptr;
		size_t count;
		pointerval(T* _ptr):count(1),ptr(_ptr){}
		~pointerval()
		{
			delete ptr;
		}
	};
	pointerval val;
	sharedptr(const T* _val=nullptr):val(_val)
	{
		++val->count;
	}
	~sharedptr()
	{
		--val->count;
		if(val->count==0)
		{
			delete val;
		}
	}
	sharedptr(const sharedptr& r):val(r.val)
	{
		++val->count;
	}
	sharedptr& operator=(const sharedptr& r)
	{
		if( &r == this || r.val==val)
		{
			return *this;
		}
		if(val != nullptr)
		{
			--val->count;
			if(val->count ==0)
			{
				delete val;
			}
		}
		val=r.val;
		val->count++;
	}




};
//----------------------------------------------------------------------
template<typename T>
struct smart_pointer
{
    T* pointer;
    size_t *refs;
    void clear();
    ~smart_pointer();
    smart_pointer(T* p = NULL): pointer(p), refs(new std::size_t(1)){}
    smart_pointer(const smart_pointer<T>& other);
    smart_pointer& operator=(const smart_pointer<T>& other);
    smart_pointer& operator=(T* p);
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;
    size_t getCounts();
};

template<typename T>
void smart_pointer<T>::clear()
{
        if (!--*refs){
            delete pointer;
            delete refs;
        }
}

template<typename T>
smart_pointer<T>::smart_pointer(const smart_pointer<T>& other): pointer(other.pointer), refs(other.refs)
{
	++*refs;
}

template<typename T>
smart_pointer<T>::~smart_pointer()
{
	clear();
}
template<typename T>
smart_pointer<T>& smart_pointer<T>::operator=(const smart_pointer<T>& other)
{
        if (this != &other){
            clear();
            pointer = other.pointer;
            refs    = other.refs;
            ++*refs;
        }
        return *this;
}
template<typename T>
smart_pointer<T>& smart_pointer<T>::operator=(T* p)
{
        if (pointer != p){
            pointer = p;
            *refs = 1;
        }
        return *this;
}

template<typename T>
T& smart_pointer<T>::operator*()
{
        return *pointer;
}

template<typename T>
const T& smart_pointer<T>::operator*() const
{
  return *pointer;
}

template<typename T>
T* smart_pointer<T>::operator->()
{
        return pointer;
}

template<typename T>
const T* smart_pointer<T>::operator->() const
{
        return pointer;
}

template<typename T>
std::size_t smart_pointer<T>::getCounts()
{
        return *refs;
}

int main()
{
	smart_pointer<int> sp=new int(10);
}


