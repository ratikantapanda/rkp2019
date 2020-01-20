#include <iostream>
#include <sys/time.h>
#include <sstream>

using namespace std;
/********************************************************************************
 **********************************************************************************/
struct longDouble
{
	static long toLong(double d)
	{
		long r=(long)(d*1000000);
		if(r >0)
		{
			r %10 > 5 ? r+=5:r-=5;	
		}
		//ex- -1.322456
		else if(r <0)
		{
			r%10 > -5 ? r+=5:r-=5; 
		}
		return r;
	}
	static double toDouble(long l){
		return (double)l/1000000.00;
	}
};

/********************************************************************************
 **********************************************************************************/
unsigned long long getEpochTime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return ((( t.tv_sec * 1000000 ) + t.tv_usec ));
}
/********************************************************************************
 **********************************************************************************/
template <typename T>
struct StrNumber
{
        //stoi,stol,stoll,stoul,stoull,stof,stod,stold
	static T StringToNumber(std::string const & text)
	{
		T value;
		std::stringstream ss(text);
		ss >> value;
		return value;
	}
       //std::to_string(),std::to_wstring()
	static std::string NumberToString(T num)
	{
		std::ostringstream ss;
		ss << num;
		return ss.str();
	}
};
bool _atoi(const char* s, uint32_t *r)
{
  unsigned long long res = 0;
  if(s==NULL) return false;
  for (int i = 0; s[i] != '\0'; i++)
  {
    int d;
    switch (s[i])
    {
      case '0': d = 0; break;
      case '1': d = 1; break;
      case '2': d = 2; break;
      case '3': d = 3; break;
      case '4': d = 4; break;
      case '5': d = 5; break;
      case '6': d = 6; break;
      case '7': d = 7; break;
      case '8': d = 8; break;
      case '9': d = 9; break;
      default: return false;
    }
    res = res * 10 + d;
    if (res > ((1ULL << 32) -1ULL))
      return false;
  }
  *r = res;
  return true;
}
//-------------------------------------------------------------------------------
inline long int convertStringToLongInt (string &str, int base =10)
    {
        //This code is adapted from http://linux.die.net/man/3/strtol
        int errno ;
        long int val;
        char *endPtr;

        val = strtol(str.c_str(), &endPtr, base);

        /*if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0)) {
           // LOG_CRITICAL_EVENT(ERROR, "Unable to convert "<<str<<" to long int");
            //throw logic_error("Error in converting string to long int");
        }

        if (endPtr == str) {
           // LOG_CRITICAL_EVENT(ERROR, "No digits were found while converting "<<str<<" to long int");
            //throw logic_error("Error in converting string to long int");
        }

        if (*endPtr != '\0') {
            //LOG_CRITICAL_EVENT(ERROR, "Ignoring Further characters " <<endPtr<<" while converting ");
            //throw logic_error("Error in converting string to long int");
        }
*/
        return val;

    }
//----------------------------------------------------------------------------------------
inline string toString(int num)
{
        char buf[64];
        snprintf(buf, 64, "%d", num);
        return buf;
}



/********************************************************************************
 **********************************************************************************/
bool isNumeric(const string& s)
{
	int len=s.size();
	for(int i=0; i < len; i++){
		if(s[i] < '0' || s[i] >'9')
			return false;
	}
	return true;
}
/********************************************************************************
 **********************************************************************************/


int main(){
	long l=longDouble::toLong(12.3456734587);
	double d=longDouble::toDouble(l);
	std::cout << d << '\n';
	std::cout << getEpochTime() << '\n';
	std::cout << StrNumber<double>::NumberToString(123.345) << '\n';
}
