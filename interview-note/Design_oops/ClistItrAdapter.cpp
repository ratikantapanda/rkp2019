#include<iostream>

template<class CLIST,class ITEMTYPE>
class ClistIterAdapter
{
  CLIST& l;
public:
  ClistIterAdapter(CLIST& r):l(r) { }
  class iterator
  {
    CLIST* plist;
    POSITION p;
  public:
    iterator(CLIST* lp):plist(p) { }
    iterator(const iterator& i)
    {
      plist=i.plist;
      p=i.p;
    }
    iterator operator++()
    {
      plist=plist->next(p);
      return *this;
    }
    iterator operator++(this)
    {
      iterator temp(*this);
      plist=plist->next(p);
      return *this;
    }
    ITEMTYPE operator*()
    {
      return plist->getValueAt(p);
    }
    bool operator==(const iterator& it)
    {
      return ( p == it.p );
    }
    bool operator!=(const iterator& it)
    {
      return (p != it.p);
    }
  };
  iterator begin()
  {
    iterator it(&l);
    return it;
  }
  iterator end()
  {
   iterator it(NULL);
   return it;
  }
};



