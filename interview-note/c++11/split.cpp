#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//PRINT_ELEMENTS()
template < typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr="")
{
        std::cout << optstr;
        for(const auto& elem:coll){
                std::cout << elem << ' ';
        }
        std::cout << std::endl;
}



bool isSpace(char c)
{
	return isspace(c);
}

bool isNotSpace(char c)
{
	return !isspace(c);
}

std::vector<std::string> split(const std::string& s)
{
	typedef std::string::const_iterator citer;
	vector<string> v1;
	for(citer i=s.begin();i!=s.end();){
		i=find_if(i,s.end(),isNotSpace);
		citer j=find_if(i,s.end(),isSpace);
		if(i !=s.end()){
			v1.push_back(string(i,j));
		}
		i=j;
	}
	return v1;
}
/*std::vector<std::string> split(const std::string& str)
{
typedef string::const_iterator iter;
vector<string> ret;
iter i = str.begin();
while (i != str.end()) {
// ignore leading blanks
i = find_if(i, str.end(), isNotSpace);
// find end of next word
iter j = find_if(i, str.end(), isSpace);
// copy the characters in [i, j)
if (i != str.end())
ret.push_back(string(i, j));
i = j;
}
return ret;
}
*/
int main()
{
	std::vector<string> v1=split("Ratikanta Panda,India.");
	PRINT_ELEMENTS(v1,"AFTER SPLIT\n");
	std::cout << "hello" << std::endl;
	return 0;
}
