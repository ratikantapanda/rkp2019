// https://www.quora.com/Where-can-I-find-difficult-algorithm-data-structure-problems

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <exception>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <future>
//Miscellaneous headers:
#include <assert.h>
#include <errno.h>
#include <setjmp.h>
#include <stdarg.h>
/**
 * C++ Standard Library -Input/output 	Strings
*  Standard Template Library -algorithm functional Sequence containers 
			      Associative containers 
			      Unordered associative containers
*  C standard library -Data types Character classification Strings Mathematics
			File input/output Date/time Localization
			Memory allocation Process control Signals Alternative tokens
**/

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


int main()
{
	return 0;
}
