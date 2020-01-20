#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;


//spaces trimmed from left
string& trim_l(string& s)
{
	int i=0;
	for(; s[i]==' ' || s[i]=='\t'; ++i);
        s.erase(0,i);
	return s;	
}
//trimmed from left
string& trim_l(string& s,char c)
{
	int i=0;
	for(i; s[i]==c;++i);
        s.erase(0,i);
	return s;	
}

//spaces trimmed from right
string& trim_r(string& s)
{
	 long pos(s.size());
        for ( ; pos && s[pos-1]==' ' || s[pos-1]=='\t'; --pos );
        s.erase(pos, s.size()-pos);
        return s;

}
//spaces trimmed
string& trim_r(string& s,char c)
{
	 long pos(s.size());
        for ( ; pos && s[pos-1]==c ; --pos );
        s.erase(pos, s.size()-pos);
        return s;

}
string trim_(string& s, char c=' ')
{
	if(c==' ' || c=='\t')
		trim_l(s);
	        trim_r(s);
		return s;
}
//sqeeze spaces

inline string& squeeze( string& str, char c = ' ')
{
        if(str.size() <= 0)
                return str;

        string::size_type iPos = 0;
        while((iPos = str.find_first_of(c)) != string::npos)
                str.erase(iPos, 1);

        return str;
}


/***********************************************************************************
 * *********************************************************************************/

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}
int main()
{
	std::string s=" 1234 aa";
	cout << squeeze(s) <<"MR";
	return 0;
}
