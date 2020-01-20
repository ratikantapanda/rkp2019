#include <iostream>
#include <string.h>
 using namespace std;

class String 
{
private:
  struct StringValue 
  {
    size_t refCount;
    char *data_;
    StringValue(const char *data):refCount(1)
	{
	   data_=new char[strlen(data) + 1];
	   strcpy(data_,data);
	}
    ~StringValue()
	{
	  delete [] data_;
	}
  };
  StringValue *value;
  size_t len;
public:
  String(const char *initValue = ""): value(new StringValue(initValue)){}
  String(const String& rhs): value(rhs.value)
  {
     ++value->refCount;
  }
  ~String()
  {
     if (--value->refCount == 0) delete value;
  }
  String& operator=(const String& rhs)
  {
     if (value == rhs.value) 
	 {
        return *this; // are already the same; this
     } 
    if (--value->refCount == 0)
    {
       delete value;
    }
    value = rhs.value;
    ++value->refCount;
    return *this;
  }
//Copy on write
  const char& operator[](int index) const  // for const Strings
  {
	  std::cout << "for constant string called " << std::endl;
    if(index >=0 && index <= len)
	return value->data_[index];
  }
  char& operator[](int index)
 {
	 std::cout << "for non constant string called " << std::endl;
    if (value->refCount > 1) {
    --value->refCount;
    value =new StringValue(value->data_);
 }
 return value->data_[index];
 }
 };
 
int main()
{
	const String s1="Ratikanta Panda";
	const char c= s1[10];

	std::cout << c << std::endl;
	return 0;
}
