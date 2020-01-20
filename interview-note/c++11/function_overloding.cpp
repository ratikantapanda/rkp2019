#include <iostream>
#include <string>

using namespace std;

/*string  f(const string s)
{
	std::cout << "const string s" << std::endl;
	return "Hello";
}*/
/*string  f(string s)
{
	std::cout << "string s" << std::endl;
	return "Hello";
}*/
string  f(string&  s)
{
	std::cout << "const string s" << std::endl;
	return "Hello";
}
string  f(const string&  s)
{
	std::cout << "const string s" << std::endl;
	return "Hello";
}

void display(char *p)
{
    cout<<p;
}
void display(const char *p)
{
    cout<<"const " << " " << p << std::endl;
}

int main()
{
    display("Hello");
    display("World");
    const string arg1="Hello";
    string s1=f(arg1);

}

