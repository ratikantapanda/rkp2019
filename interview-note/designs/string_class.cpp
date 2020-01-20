#include <iostream>
#include <cstring>

using namespace std;

struct mystring
{
	char* str;
	size_t len;
	~mystring();
	mystring():str(nullptr),len(0){}
	mystring(const char* _str);
	mystring(const mystring&);
	mystring& operator=(const mystring&);
	size_t size()const{ return len;}
	friend ostream& operator<<(ostream& os,mystring& s);
	char operator[](int index) const;
	char& operator[](int index);
	//string append
	mystring& operator+(const mystring &s);
	/*string&  operator +=(const mystring& s);
	string&  operator +=(const char* s);
	string&  operator +=(char c);*/
	friend bool operator ==(const mystring& s1, const mystring& s2);
        friend bool operator !=(const mystring& s1, const mystring& s2);
        friend bool operator >=(const mystring& s1, const mystring& s2);
        friend bool operator <=(const mystring& s1, const mystring& s2);
        friend bool operator > (const mystring& s1, const mystring& s2);
        friend bool operator < (const mystring& s1, const mystring& s2);
};
mystring::~mystring()
{
		if(str!= nullptr){
			delete str;
		}
}
mystring::mystring(const char* _str):len(0)
{
		while(_str[len++] != '\0');
		str= new char[len];
		for(int i=0; i < len ; i++){
			str[i]=_str[i];
		}
		str[len]='\0';
}
mystring::mystring(const mystring & s)
{
		len=s.len;
		str=new char[len];
		for(int i=0;i < len; i++){
			str[i]=s.str[i];
		}
		str[len]='\0';
}
mystring& mystring::operator=(const mystring& s)
{
		if( &s==this){
			return *this;
		}
		if(str !=nullptr){
			delete str;
		}
		len=s.len;
		str=new char[len];
		for(int i=0; i <=len; i++){
			str[i]=s.str[i];
		}
		str[len]='\0';
		return *this;
}
ostream& operator<<(ostream& os,mystring& s)
{
	os << s.str;
}
// for const objects: can only be used for access
//const char&  mystring::operator[](int index) const
char mystring::operator[](int index) const
{
	if(index >=0 && index < len)
		return str[index];
}
// for non-const objects: can be used for assignment
char& mystring::operator[](int index)
{
	if(index >=0 && index < len)
		return str[index];
}
bool operator ==(const mystring& s1, const mystring& s2)
{
	if(s1.size() != s2.size())
		return false;
	int len=s1.size();
	for(int i=0; i < len; i++){
		if(s1[i] != s2[i])
			return false;
	}
	return true;
}
/* '+' operator */
mystring& mystring::operator+(const mystring &s)
{
}
//========================================================

//String class implementation with ref count and copy on write
//============================================================
struct  String
{
	struct StringValue 
	{
		size_t refCount;
		char* data;
		StringValue(const char *_data):refCount(1)
		{
			data=new char[strlen(_data) + 1];
			strcpy(data,_data);
		}
		~StringValue()
		{
			delete [] data;
		}
	};
	StringValue *value;
	size_t len;
  ~String();
  String(const char *initValue = ""): value(new StringValue(initValue)){}
  String(const String& rhs);
  String& operator=(const String& rhs);
  const char& operator[](int index) const;  // for const Strings
  char& operator[](int index); // for non-const Strings
};
  String::String(const String& rhs): value(rhs.value)
  {
     ++value->refCount;
  }
  String::~String()
  {
     if (--value->refCount == 0) delete value;
  }
  String& String::operator=(const String& rhs)
  {
	  if (this==&rhs || value == rhs.value) 
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
  const char&  String::operator[](int index) const  // for const Strings
  {
	  if(index >=0 && index <= len)
		  return value->data[index];
  }
  char& String::operator[](int index)
  {
	  if (value->refCount > 1) {
		  --value->refCount;
		  value =new StringValue(value->data);
	  }
	  return value->data[index];
  }

//=================================================================
int main()
{
	const mystring s1("ratikanta panda");
	mystring s2;
	s2=s1;
	//std::cout << s2.str << '\n';
	std::cout << s2 << '\n';
	bool result=(s1==s2);
	std::cout << result << '\n';
	
}

