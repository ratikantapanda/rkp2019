
#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(const string& str)
{
    if (str.empty())
        return false;

    int i = 0;                // first characters
    int j = str.length() - 1; // last character

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isPalindrom(string s,int low, int high)
{
	return ((low >=high) || ( s[low]==s[high] && isPalindrom(s,low+1,high-1)));
}

int main()
{
	std::cout << IsPalindrome("abbaccca") << std::endl;
	std::cout << isPalindrom("caaaaac",0, 6) << '\n';
 return 0;
} 
