#include <string>
#include <iostream>

using namespace std;

string encode(string s)
{
	if(s.size()==0)
		return "";
	string result;
	int count=0;
	char prev=s[0];
	for(int i=0; i < s.size(); i++){
		if(s[i] == prev){
			count++;
		}
		else{
			result +=std::to_string(count)+prev;
			prev=s[i];
			count=1;
		}
	}
	result +=std::to_string(count)+prev;
	return result;
}

int main(){
	std::cout <<encode("a a a") << '\n';
	return 0;
}
