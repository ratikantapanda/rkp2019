
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <vector>
//#include <boost/lexical_cast.hpp>
//#include <boost/algorithm/string.hpp>
#include <time.h>


using namespace std;

const std::string TICK_ENTER_COMMAND   ="TICK:";
const std::string QUERY_COMMAND_1      ="QUERY:allTickersForAsset";
const std::string QUERY_COMMAND_2      ="QUERY:allBankForTicker";
const std::string QUERY_COMMAND_3      ="QUERY:bestReturnForTickerInTimeRange";
const std::string EXIT_COMMAND         ="exit"; 
//-----------------------------------------------------------------------------------------

int str_to_int(const string& s)
{
  int i;
  std::istringstream(s) >> i;
  return i;
}

double str_to_double(const string& s)
{
  double i;
  std::istringstream(s) >> i;
  return i;
}
 
template <class Container>
void split_str(Container& cont, const std::string& str, const char delim = ' ')
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

void parseTICKString(const string& str,vector<string>& tokens,const string& delimiters ="|")
{
	std::string::size_type idx;
	string::size_type pos1;
	string::size_type pos2;
	if (!tokens.empty())
		tokens.clear(); 

	idx=str.find("TICK:",0);
	if(idx != std::string::npos)
	{
    pos1 = str.find_first_not_of(delimiters, idx+5);
    pos2 = str.find_first_of(delimiters, pos1);
	while ( pos1 != string::npos)
	{
		if( pos2 == string::npos)
		{
        tokens.push_back(str.substr(pos1));
		return;
		}
		tokens.push_back(str.substr(pos1, pos2 - pos1));
        pos1 = str.find_first_not_of(delimiters, pos2);
		pos2 = str.find_first_of(delimiters, pos1);
	}
	}
}


//-----------------------------------------------------------------------------------------
struct doubleLongConverter {
	static long toLong(double d) {
			long r = (long) (d*1000000);
			if(r>0) { r%10 > 5? r+=5: r-=5 ; }
			else if(r < 0) { r%10 >-5 ? r+=5 : r-=5; }
			return r;
		
		}
	static double toDoule(long ll) {
		return (double) ll/1000000.00;
	
	}

};

//---------------------------------------------------------------------------
class TimeType {
	public:
	static time_t getBaseEpoc() { 

		struct tm tm;
		char const  *s = "2014-11-30 0:0:0";
		strptime(s,"%Y-%m-%d %H:%M:%S", &tm);
		time_t epoc = mktime(&tm);
		return epoc ;

	}
	static time_t getinSec_HourMinSec(int hr , int Min , int Sec) {
		return hr * 3600 + Min *60 +Sec;
	}
	TimeType(std::string  const&str):timeStr(str) {
		time(&epocTime);
	}
	TimeType(struct tm tmsP){
		 epocTime=mktime(&tmsP);
		 char Buffer[100]={'\0'};
		 strftime(Buffer,sizeof(Buffer),"%Y-%m-%d:%H:%M:%S",&tmsP);
		 timeStr=std::string(Buffer);
	}
	TimeType(time_t epocTime){
		struct tm *tmm = localtime(&epocTime);
		struct tm myTime = *tmm;
		char Buffer[256]={'\0'};
		strftime(Buffer,sizeof(Buffer),"%Y-%m-%d:%H:%M:%S",&myTime);	
		timeStr=std::string(Buffer);
		this->epocTime = epocTime;
	}
	TimeType() { 
		epocTime=0;
	}
	TimeType & operator = ( TimeType const &rhs) {	
		if(this != &rhs){
			this->epocTime = rhs.epocTime;
			this->timeStr  = rhs.timeStr;
		}
		return *this;		

	}
	long getEpocTime() 	  const  {	return epocTime; }
	std::string getTimeAscii() const{ std::cout<<getEpocTime()<<std::endl;  return timeStr;  }
	private:
	std::string timeStr;
	long epocTime;
	friend bool operator < ( TimeType const & lhs , TimeType const &rhs);
	friend bool operator > (TimeType const & lhs , TimeType const &rhs);
};

bool operator <(TimeType const &lhs ,TimeType const &rhs) {
	return lhs.epocTime < rhs.epocTime;
}

bool operator > (TimeType const &lhs ,TimeType const &rhs) {
	return lhs.epocTime  > rhs.epocTime;
}

//-------------------------------------------------------------------------
class MarketData {
	private:
	TimeType    timeStamp;
	std::string secName;
	std::string assetClassifier;
	std::string bankID;
        long        bidPrice;
	long        askPrice;
	public:
	//typedef     boost::shared_ptr<MarketData> sptr;
	typedef     std::shared_ptr<MarketData> sptr;
	MarketData(){
		bidPrice = 0;
		askPrice = 0;	
	}
	void setEpocTime(TimeType const &tsm) 		{ timeStamp = tsm;  }
	void setSecName(std::string const & sN) 	{ secName   = sN;   }
	void setBankID(std::string const &bID) 		{ bankID    = bID;  }
	void setAssetClassifier(std::string const& acf)	{ assetClassifier = acf; }
	void setBidSize(double dd)			{ bidPrice = doubleLongConverter::toLong(dd);}
	void setAskSize(double dd) 			{ askPrice = doubleLongConverter::toLong(dd);}
	TimeType getTime() const	 		{ return timeStamp; }
	std::string getSecName() const			{ return secName;   }  
	std::string getassetClassifier() const		{ return assetClassifier; }
	std::string getBankID()	const			{ return bankID; 	  }
	long getBid() const				{ return bidPrice; 	  }
	long getAsk() const	 			{ return askPrice;        }
	friend std::ostream &operator<< (std::ostream &coutL , MarketData const &ref){
		coutL<<"Time:"<<ref.getTime().getTimeAscii()<<std::endl;
		//coutL<<"secName:"<< ref.getSecName()<<std::endl;	
		//coutL<<"assetClassifier:" <<ref.getassetClassifier()<<std::endl;
		coutL<<"bidPrice"<<doubleLongConverter::toDoule(ref.getBid())<<std::endl;
		coutL<<"askPrice:"<<doubleLongConverter::toDoule(ref.getAsk())<<std::endl;
		coutL<<"bankID:"<<ref.getBankID()<<std::endl;
		return coutL;
	}
};
//-------------------------------------------------------------------------------------------------------
class BidAskFilterTime{
        public:

        BidAskFilterTime(TimeType const &rT1 , TimeType const &rT2) : _criteria1(rT1),_criteria2(rT2){}
        bool operator()  (MarketData::sptr const &rhs ) const {
		std::cout<<"EPOC DATA :"<<rhs->getTime().getEpocTime()<<std::endl;
                std::cout<<"EPOC CRITERIA LEFT"<<_criteria1.getEpocTime()<<std::endl;
                std::cout<<"EPOC CRITERIA RIGT"<<_criteria2.getEpocTime()<<std::endl;
                if(rhs->getTime() > _criteria1 && rhs->getTime() < _criteria2 ){
			std::cout<<"TRUE"<<std::endl;
                        return true;
                }
                return false;
        }
        private:
        TimeType _criteria1;
        TimeType _criteria2;
};

//-----------------------------------------------------------------------------------------
class  UniqueKey {
	public:
	UniqueKey() { _keyValue = 0; }
	UniqueKey( long k) { _keyValue = k ;}
	UniqueKey(UniqueKey const &rhs) {
		this->_keyValue = rhs._keyValue;
	}
	UniqueKey & operator =(UniqueKey const &rhs) {
		if(this != &rhs){
			this->_keyValue = rhs._keyValue;
		}
		return *this;
	}
	long getNativeType() const{ return _keyValue; }
	private:
	long _keyValue;
	friend bool operator<(UniqueKey const &rhs , UniqueKey const&lhs);
	friend bool operator == (UniqueKey const &rhs , UniqueKey const&lhs) ;
	
};
bool operator < (UniqueKey const &rhs , UniqueKey const&lhs) {
	return rhs._keyValue < lhs._keyValue;
}
	
bool operator ==  (UniqueKey const &rhs , UniqueKey const&lhs) {
	return rhs._keyValue == lhs._keyValue;
}
template<typename KEY>
struct Quote {
        KEY              _ask_key;
        KEY              _bid_key;
};
template<typename KEY>
class OrderTable{
	struct SortKey {
                KEY  _key;
                long _bidAsk;
		
                SortKey() {_bidAsk=0;}
                SortKey(KEY const & r,long BidAsk):_key(r),_bidAsk(BidAsk) {
                }
                bool operator < ( SortKey const & rhs) const{
                        return this->_bidAsk  < rhs._bidAsk;
                }
        };

	typedef std::multiset<SortKey> indexBidAsk;
        typedef typename std::multiset<SortKey>::const_iterator citer_s;
        typedef typename std::multiset<SortKey>::iterator  itr_s ;
	typedef typename std::multiset<SortKey>::reverse_iterator ritr_s; 


	public:
	void add(KEY const & key , MarketData::sptr const& md) {
		SortKey skBid(key , md->getBid());
		SortKey skAsk(key , md->getAsk());
		_BidList.insert(skBid);
		_AskList.insert(skAsk);
		std::vector<KEY> tt = getAllQuotes();
		getBestQuote();	
		//getBidValues();
		//getAskValues();
		
	} 
	std::vector<KEY>  getBidValues(){
		std::vector<KEY> ret;
		for(ritr_s  it1 = _BidList.rbegin(); it1 != _BidList.rend() ; ++it1){
			std::cout<<"BID KEY"<<it1->_key.getNativeType()<<std::endl; 
			ret.push_back(it1->_key);
		}
		return ret;
	}
	std::vector<KEY>  getAskValues(){
			std::vector<KEY> ret;
			citer_s itA = _AskList.begin();
			for(;itA != _AskList.end(); ++itA){
				std::cout<<"ASK KEY"<<itA->_key.getNativeType()<<std::endl;
				ret.push_back(itA->_key);
			}
			return ret;

	}
	Quote<KEY>  getBestQuote() {
		Quote<KEY> quote;
		ritr_s  it1 = _BidList.rbegin();
		citer_s it2 = _AskList.begin();
		if( it1 != _BidList.rend() && it2 != _AskList.end()) {
			quote._ask_key = it1->_key;
			quote._bid_key = it2->_key;

		}
		return quote;

	}
	std::vector<KEY> getAllQuotes() {
		//dump amy one 
		std::vector<KEY> ret;
		for( ritr_s it = _BidList.rbegin(); it != _BidList.rend() ; ++it){	
			ret.push_back(it->_key);
		}
		return ret;
	}
	void dumpAll() {
		std::cout<<"BID LIST"<<std::endl;
		for(ritr_s it = _BidList.rbegin(); it != _BidList.rend() ; ++it){
                        std::cout<<it->_key.getNativeType()<<std::endl;
                }
		std::cout<<"ASK LIST"<<std::endl;
		for(citer_s it = _AskList.begin() ; it != _AskList.end() ; ++it){
			std::cout<<it->_key.getNativeType()<<std::endl;
		}

	}
	void clear(KEY const &key){ 
		//TDB
	}
	private: 
	indexBidAsk _BidList;
	indexBidAsk _AskList;
	

};

template<typename KEY,typename DATA>
class MultiIndexContainer {
	public:
	typedef std::vector<KEY> keyList;
	typedef typename std::vector<KEY>::const_iterator citer_kl;
	typedef typename std::vector<KEY>::iterator iter_kl;
	
	typedef std::map<KEY,typename DATA::sptr > dataContainer;
	typedef typename std::map<KEY,typename DATA::sptr >::const_iterator citer_ds;
	typedef typename std::map<KEY,typename DATA::sptr >::iterator iter_ds;
	
	typedef std::map<std::string,keyList > indexSecName;
	typedef typename std::map<std::string,keyList >::const_iterator citr_isec;
	typedef typename std::map<std::string,keyList >::iterator itr_isec;
	
	typedef std::map<std::string,keyList > indexBank;
	typedef typename std::map<std::string,keyList >::const_iterator citer_bi;
	typedef typename std::map<std::string,keyList >::iterator iter_bi;
	
	
	typedef std::map<std::string ,OrderTable<KEY> > indexOrderBook;
	typedef typename std::map<std::string ,OrderTable<KEY> >::const_iterator citer_ob;
	typedef typename std::map<std::string ,OrderTable<KEY> >::iterator  iter_ob;

	 
	typedef std::map<std::string , keyList > assetClass;
	typedef typename std::map<std::string,keyList >::const_iterator citer_ac;
	typedef typename std::map<std::string,keyList >::iterator iter_ac;
	
	//typedef std::set< KEY> 	 qu 
	UniqueKey  insert(typename DATA::sptr sptr ) {
		//Address always unqiue
		long ptr = (long)sptr.get(); 
		UniqueKey key(ptr);
		addToDataSurce(key,sptr);
		addToIndexSecName(sptr->getSecName(),key);
		addToIndexBank(sptr->getBankID(),key);
		addToIndexAssetClassifer(sptr->getassetClassifier() ,key);
		addToIndexOB(sptr->getSecName(),key, sptr);
		return key;
	}
	void erase(long id) {
		//clean TBD

	}
	
	MarketData::sptr  getMaketData(KEY const & key){
		MarketData::sptr ret;
		iter_ds it = _dataContainer.find(key);
		if(_dataContainer.end()	!= it) {
			ret = it->second;
			
		}
		return ret;
	}
	void dumpDataSource() {
		for(citer_ds it = _dataContainer.begin(); it != _dataContainer.end() ; ++it){
			MarketData const &rmd = *(it->second);
			std::cout<<rmd;
		}
	}
	void dumpDataSource (KEY const & key) {
		for(citer_ds it = _dataContainer.begin(); it != _dataContainer.end() ; ++it){	
			if(key  == it->first) {
				MarketData const &rmd = *(it->second);
                        	std::cout<<rmd;
				break;
			}			
		}
	}
	
	//Bd ; Rate at which any Bank is willing to buy : Take Highrest 
	
	std::vector<std::pair<MarketData::sptr , MarketData::sptr> > 
	getQotesInTimeRange(std::string const TikerName ,BidAskFilterTime const&filter){
		std::vector<std::pair<MarketData::sptr,MarketData::sptr> > retQuotes;
		iter_ob itr = _indexOB.find(TikerName);
		if(itr != _indexOB.end()){
			OrderTable<KEY>  &orT = itr->second;	
			std::vector<KEY> vList1 = orT.getBidValues();
			std::vector<KEY> vList2 = orT.getAskValues();
			std::vector<MarketData::sptr> filterASK;
			std::vector<MarketData::sptr> filterBID; 
			typename std::vector<KEY>::iterator itB = vList1.begin();
			typename std::vector<KEY>::iterator itA = vList2.begin();
			for(; itB != vList1.end();++itB ){
				 
				MarketData::sptr const &ref = getMaketData(*itB);
				if(ref && filter(ref)){
					std::cout<<"CHK10"<<*ref<<std::endl;
					filterASK.push_back(ref);
				}
			}
			for(;itA != vList2.end();++itA ){
                                MarketData::sptr const &ref = getMaketData(*itA);
                                if(ref && filter(ref)){
				     std::cout<<"CHK11"<<*ref<<std::endl;	
                                     filterBID.push_back(ref);           
                                }
                        }       
 			std::vector<MarketData::sptr>::iterator itASK = filterASK.begin();
			std::vector<MarketData::sptr>::iterator itBID = filterBID.begin();
			for(;itASK != filterASK.end() && itBID != filterBID.end(); ++itASK,++itBID) {
				std::pair<MarketData::sptr,MarketData::sptr> d;
				d.first  = *itASK;
				d.second = *itBID;
				retQuotes.push_back(d);
			}
		}
		return retQuotes;
	}
	
	
	void addToIndexOB(std::string const &secName , KEY const &ref , MarketData::sptr const & sp) {
		 _indexOB[secName].add(ref,sp);
	}
	
 void getMDForTickers(std::string const& filter,std::vector<MarketData::sptr > &resList){
    //citr_isec chk = _indexSecName.find(filter);
    itr_isec chk = _indexSecName.find(filter);
    if(chk != _indexSecName.end()){
      keyList const &kl = chk->second;
      for(citer_kl it = kl.begin() ; it != kl.end(); ++it){
                                citer_ds chk = _dataContainer.find(*it);
                                if(chk != _dataContainer.end()){
                                        resList.push_back(chk->second);
                                }
                                else{
                                     //Broken Invalid Login Cant be here
                                }
                          }
    }
  }

	//Get All Data for a Sepefic Asset Write top level function to filter speciifc data
	void getMDForAsset(std::string const &filter ,std::vector<MarketData::sptr > &resList){
		   iter_ac itr = _indexAssetClass.find(filter)	;
		   if( _indexAssetClass.end() != itr ){
			 keyList const &kl = itr->second;
			 for(citer_kl it = kl.begin() ; it != kl.end(); ++it){
				citer_ds chk = _dataContainer.find(*it);
				if(chk != _dataContainer.end()){
					resList.push_back(chk->second);	
				}
				else{
					//Broken Invalid Login Cant be here
				}
			  }
		   }	
	}
	void addToIndexAssetClassifer(std::string const &assClas , UniqueKey const& key){
		_indexAssetClass[assClas].push_back(key);
	}
	
	void addToIndexBank(std::string const &bID, UniqueKey const& key){
		_indexBank[bID].push_back(key); 
	}
	void addToIndexSecName(std::string const &secName , UniqueKey const& key){
		_indexSecName[secName].push_back(key);
	}
	void addToDataSurce( UniqueKey const &key , typename DATA::sptr const&rhs) {
		_dataContainer.insert(typename dataContainer::value_type(key,rhs));
	}
	dataContainer 	_dataContainer;
	indexSecName 	_indexSecName;
	indexBank 	_indexBank;
	assetClass 	_indexAssetClass; 
	indexOrderBook 	_indexOB;
	//indexAsk	_indexAsk;

}; 

	
typedef MultiIndexContainer<UniqueKey,MarketData> MIDataType;
#define GETBASEEPOC  (YEAR,MONTH,DAY,
int main(int , char**){
	MIDataType mm;
	time_t bEpoc = TimeType::getBaseEpoc();
  std::cout << "Type the input as given format specified in"  << std::endl;
  string command;
	command.reserve(1024);
	while(true)
    {
        getline(cin,command);
		if(0 == command.compare(EXIT_COMMAND))
        {
            break;
        }
        else if(0 == command.compare(0,5,TICK_ENTER_COMMAND))
        {
            vector<string> token;
						parseTICKString(command, token);
            MarketData *mdata  = new MarketData();
						 //int  h1=boost::lexical_cast<int>(token[0].substr(0,2));
             //int  m1=boost::lexical_cast<int>(token[0].substr(3,2));
             //int s1=boost::lexical_cast<int>(token[0].substr(6,2));
						 int  h1=str_to_int(token[0].substr(0,2));
             int  m1=str_to_int(token[0].substr(3,2));
             int s1=str_to_int(token[0].substr(6,2));
  					 time_t tt = TimeType::getinSec_HourMinSec(h1,m1,s1) + bEpoc;
  					TimeType myTime(tt);
						mdata->setEpocTime(myTime);
  					mdata->setSecName(token.at(1));
  					mdata->setBankID( token.at(3));
  					mdata->setAssetClassifier(token.at(2));
  					mdata->setBidSize(str_to_double(token.at(4)));
  					mdata->setAskSize(str_to_double(token.at(5)));
  					MarketData::sptr sp(mdata);
  					//UniqueKey p = mm.insert(sp);
  					 mm.insert(sp);
  					//mm.dumpDataSource(p);
  					//mm.dumpDataSource();

            //std::cout << "tick entered" << std::endl;
        }
        else if(0 == command.compare(0,24,QUERY_COMMAND_1))
        {  
			std::size_t pos1= command.find_first_of("\"");
			std::size_t  pos2= command.find_last_of("\"");
			string  arg1=command.substr(pos1+1,pos2-pos1-1);
			std::vector<MarketData::sptr > v1;
  		mm.getMDForAsset(arg1,v1);
  for(std::vector<MarketData::sptr >::iterator ii=v1.begin(); ii!=v1.end(); ++ii){
       std::cout <<  (*ii)->getSecName() << std::endl;
       }

        }
        else if(0 == command.compare(0,22,QUERY_COMMAND_2))
        {
            
			std::size_t pos1= command.find_first_of("\"");
			std::size_t  pos2= command.find_last_of("\"");
			string  arg1=command.substr(pos1+1,pos2-pos1-1);
			std::vector<MarketData::sptr > v2;
			mm.getMDForTickers(arg1,v2);
			for(std::vector<MarketData::sptr >::iterator ii=v2.begin(); ii!=v2.end(); ++ii)
  {std::cout  << (*ii)->getBankID() << std::endl;}


						
        }
		else if(0 == command.compare(0,36,QUERY_COMMAND_3))
        {
            std::cout << "QUERY:bestReturnForTickerInTimeRange" << std::endl;


						std::size_t pos1= command.find_first_of("\"");
             std::size_t  pos2= command.find_last_of("\"");
             string  argline=command.substr(pos1,pos2-pos1+1);
             vector<string> args;
            // boost::split(args,argline,boost::is_any_of(","));
             split_str(args,argline,',');
            std::size_t  p1= args[0].find_first_of("\"");
            std::size_t  p2= args[0].find_last_of("\"");
            string ticker=args[0].substr(1,p2-p1-1);
            std::cout << ticker  << std::endl;
            std::size_t  p3= args[1].find_first_of("\"");
            std::size_t  p4= args[1].find_last_of("\"");
             string time1=args[1].substr(1,p4-p3-1);
             //int  hr1=boost::lexical_cast<int>(time1.substr(0,2));
             //int  min1=boost::lexical_cast<int>(time1.substr(3,2));
             //int sec1=boost::lexical_cast<int>(time1.substr(6,2));
             int  hr1=str_to_int(time1.substr(0,2));
             int  min1=str_to_int(time1.substr(3,2));
             int sec1=str_to_int(time1.substr(6,2));
            std::size_t  p5= args[2].find_first_of("\"");
            std::size_t  p6= args[2].find_last_of("\"");
             string time2=args[2].substr(1,p6-p5-1);
             //int  hr2=boost::lexical_cast<int>(time2.substr(0,2));
             //int  min2=boost::lexical_cast<int>(time2.substr(3,2));
             //int sec2=boost::lexical_cast<int>(time2.substr(6,2));
             int  hr2=str_to_int(time2.substr(0,2));
             int  min2=str_to_int(time2.substr(3,2));
             int sec2=str_to_int(time2.substr(6,2));
          time_t tt11= TimeType::getinSec_HourMinSec(hr1,min1,sec1) + bEpoc;
  				time_t tt22= TimeType::getinSec_HourMinSec(hr2,min2,sec2) + bEpoc;
	TimeType tt_11(tt11);
	TimeType tt_22(tt22);
	BidAskFilterTime Tfilter(tt_11,tt_22);
	std::vector<std::pair<MarketData::sptr , MarketData::sptr> > ret = mm.getQotesInTimeRange(ticker,Tfilter);
	for (std::vector<std::pair<MarketData::sptr , MarketData::sptr> >::iterator i = ret.begin();i != ret.end(); ++i){
		MarketData::sptr first = i->first; 
		MarketData::sptr sec   = i->second;
		std::cout<<"BUY | "<< *first;
		std::cout<<"SHELL| "<<*sec;	

	}
        }
        else
        {
           std::cout << "Type the input as given format specified in" << std::endl;
        }
    }

	return 0;	
}

