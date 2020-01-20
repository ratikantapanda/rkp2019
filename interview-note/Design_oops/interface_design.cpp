
interface MakeFries 
{    
  BagOfFries transformPotatoIntoFries(Potato spud);
}
class Chef extends Person implements MakeFries 
{
    ...
    BagOfFries transformPotatoIntoFries(Potato spud) 
    {
       ...
    }
}
class FrenchFryMaker extends Machine implements MakeFries 
{
    ...
    BagOfFries transformPotatoIntoFries(Potato spud) 
    {
       ...
    }
}

//---------------------------------------
 class HasName 
{    
public:
        virtual string getName() = 0;
};
class HasNameAndAddress 
{
public:
        virtual string getName() = 0;
        virtual string getAddress() = 0;
};
class ImplementsBoth : public HasName, public HasNameAndAddress 
{
    public:
        virtual string getName() 
            { return "called ImplementsBoth::getName"; }
        virtual string getAddress() 
            { return "called ImplementsBoth::getAddress"; }
};
int main()
{
    HasNameAndAddress *anObject = new ImplementsBoth;
    string hmmm = anObject->getName();
    cout << hmmm << endl ;
    return 0;
}
Back to Article

Listing Three
 template <class PTR_CONTAINER>void deleteAll(PTR_CONTAINER &ptrs) 
{
    PTR_CONTAINER::iterator it = ptrs.begin();
    while (it != ptrs.end()) {
       delete *it++;
    }
}
Back to Article

Listing Four
 template <class CLIST, class ITEMTYPE>class CListSTLFwdIterAdapter {
    CLIST &rList;
public:
    CListSTLFwdIterAdapter(CLIST &aList) : rList(aList) { }
class iterator {
        CLIST *pList ;
        POSITION p ;
      public:
        iterator(CLIST *aList) { 
            pList = aList; 
            p = (pList == NULL ? NULL : pList->GetHeadPosition()); 
        }
        iterator(const iterator &it) { 
            pList = it.pList; 
            p = it.p; 
        }
        // item de-ref
        ITEMTYPE operator*() { 
            return pList->GetAt(p); 
        }
        // pre increment
        iterator operator++() { 
            pList->GetNext(p); 
            return *this; 
        }
        // post increment
        iterator operator++(int) { 
            iterator it(*this) ;
            pList->GetNext(p); 
            return it; 
        }
        bool operator==(const iterator &rhs) { 
            return this->p == rhs.p; 
        }
        bool operator!=(const iterator &rhs) { 
            return this->p != rhs.p; 
        }
    };
    iterator begin() { 
        iterator it(&rList);
        return it;
    }
    iterator end() { 
        iterator it(NULL);
        return it;
    }
};
Back to Article

Listing Five
 int main (){
    typedef CList<CString*,CString*> CListOfStrPtrs ;
    CListOfStrPtrs nameList;
    
    nameList.AddTail(new CString("Simon"));
    nameList.AddTail(new CString("Peter"));
    nameList.AddTail(new CString("James"));
    nameList.AddTail(new CString("John"));
    nameList.AddTail(new CString("Andrew"));
    nameList.AddTail(new CString("Ivan"));


</p>
    typedef CListSTLFwdIterAdapter<CListOfStrPtrs,CString*>
                                           StringPtrListAdapter ;
    StringPtrListAdapter nameListAdapter(nameList);


</p>
    deleteAll(nameListAdapter);
    return 0;
}NOTIFIERS
Back to Article

Copyright © 1998, Dr. Dobb's Journal


1 2 Next
Relat
