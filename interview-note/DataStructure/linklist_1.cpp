// linklist_1.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include<iostream>

class linklist{
public:
	struct node{
	int data;
	node* nextptr;}* lp; //lp is like head
public:
linklist();//default constructor
linklist(const linklist& theList);//copy constructor
~linklist();//destructor
void append(int);
void addatbeg ( int num );
void addafter ( int loc, int num );
void display( );
int count();
void del ( int num );
void reverse( ) ;
void add(int);
void merge(linklist&,linklist&);
void selection_sort ( int num ) ;
void bubble_sort ( int num ) ;
//void copy (linklist& l);
void printListInReverse(node* head);
void printListInReverse();
void printLast3rdNode( );
int GetNth(int index);
void getMiddleNode();
};
linklist::linklist(){lp=NULL;}
linklist::linklist(const linklist& theList){lp=theList.lp;}
linklist :: ~linklist( )
{
	node *q ;

    while ( lp != NULL )
    {
        q = lp ->nextptr ;
        delete lp ;
    	lp = q  ;
    }
}

void del ( int num );
// adds a node at the end of a linked list
void linklist :: append ( int num )
{
	node *temp, *r ;

    // if the list is empty, create first node
	if ( lp == NULL )
	{
		lp = new node ;
		lp -> data = num ;
		lp -> nextptr = NULL ;
	}
	else
	{
		// go to last node
		temp =lp ;
		while ( temp ->nextptr!= NULL )
		temp = temp ->nextptr ;

		// add node at the end
		r = new node ;
		r ->data = num ;
		r ->nextptr = NULL ;
		temp ->nextptr = r ;
	}
	/*else{
		temp=lp;
		while(temp->nextptr!=NULL){temp=temp->nextptr;}
		temp->nextptr=new node;
		temp->nextptr->data=num;
		temp->nextptr->nextptr=NULL;
	}*/

}
// adds a new node at the beginning of the linked list
void linklist :: addatbeg ( int num )
{
	node *temp ;

	// add new node
	temp = new node ;

	temp -> data = num ;
	temp -> nextptr = lp ;
	lp = temp ;
}
// adds a new node after the specified number of nodes
void linklist :: addafter ( int loc, int num )
{
	node *temp, *r ;
	temp = lp ;

	// skip to desired portion
	for ( int i = 0 ; i < loc ; i++ )
	{
		temp = temp ->nextptr ;

		// if end of linked list is encountered
		if ( temp == NULL )
		{
			cout << "\nThere are less than " << loc << " elements in list" << endl ;
			return ;
		}
	}
}

void linklist :: display( )
{
	node *temp = lp ;

	cout << endl ;
	// traverse the entire linked list
	while ( temp != NULL )
	{
		cout << temp -> data << "  " ;
		temp = temp ->nextptr;
	}
}

// counts the number of nodes present in the linked list
int linklist :: count( )
{
	node *temp = lp ;
	int c = 0 ;

	// traverse the entire linked list
	while ( temp != NULL )
	{
		temp = temp ->nextptr ;
		c++ ;
	}

	return c ;
}

// deletes the specified node from the linked list
void linklist :: del ( int num )
{
	node *old, *temp ;

	temp = lp ;

	while ( temp != NULL )
	{
		if ( temp -> data == num )
		{
			// if node to be deleted is the
			// first node in the linked list
			if ( temp == lp )
				lp = temp ->nextptr ;

			// deletes the intermediate nodes in the linked list
			else
				old ->nextptr = temp ->nextptr ;

			// free the memory occupied by the node
			delete temp ;
			return ;
		}

		// traverse the linked list till the last node is reached
		else
		{
            // old points to the previous node
			old = temp ;

            // go to the next node
			temp = temp ->nextptr ;
		}
	}

	cout << "\n\nElement " << num << " not found" ;
}

// deallocates memory
void linklist :: reverse( )
{
	node *q, *r, *s ;

	q = lp ;
	r = NULL ;

	// traverse the entire linked list
	while ( q != NULL )
	{
		s = r ;
		r = q ;
		q = q ->nextptr ;
		r ->nextptr = s ;
	}

	lp = r ;
}
// adds node to an ascending order linked list
void linklist :: add ( int num )
{
	node *r, *temp ;
	temp = lp ;

	r = new node ;
	r -> data = num ;

	// if list is empty or if new node is to be
	// inserted before the first node
	if ( lp == NULL || lp -> data > num )
	{
		lp = r ;
		lp -> nextptr = temp ;
	}
	else
	{
		// traverse the entire linked list to search
		// the position to insert the new node
		while ( temp != NULL )
		{
			if ( temp -> data < num && ( temp -> nextptr -> data > num ||
				temp -> nextptr == NULL ))
			{
				r -> nextptr = temp -> nextptr ;
				temp -> nextptr = r ;
				return ;
			}

			//go to next node
			temp = temp -> nextptr ;
		}

		r -> nextptr = NULL ;
		temp -> nextptr = r ;
	}
}
void linklist :: merge ( linklist &l1, linklist&l2 )
{
	node *z ;

	z = NULL ;

	// if both lists are empty
	if ( l1.lp == NULL && l2.lp == NULL )
		return ;

	// traverse both linked lists till the end.
	// If end of any one list is reached loop is terminated
	while ( l1.lp != NULL && l2.lp != NULL )
	{
		// if node being added is the first node
		if ( lp == NULL )
		{
			lp = new node ;
			z = lp ;
		}
		else
		{
			z -> nextptr = new node ;
			z = z -> nextptr ;
		}

		if ( l1.lp -> data < l2.lp -> data )
		{
			z -> data = l1.lp -> data ;
			l1.lp = l1.lp -> nextptr ;
		}
		else
		{
			if ( l2.lp -> data < l1.lp -> data )
			{
				z -> data = l2.lp -> data ;
				l2.lp = l2.lp -> nextptr ;
			}
			else
			{
				if ( l1.lp -> data == l2.lp -> data )
				{
					z -> data = l2.lp -> data ;
					l1.lp = l1.lp -> nextptr ;
					l2.lp = l2.lp -> nextptr ;
				}
			}
		}
	}
}
// sorts list using selection sort
void linklist :: selection_sort ( int n )
{
	int temp ;
	node *q, *r ;

	q = lp ;
	for ( int i = 0 ; i < n - 1 ; i++ )
	{
		r = q -> nextptr ;

		for ( int j = i + 1 ; j < n ; j++ )
		{
			if ( q -> data > r -> data )
			{
				temp = q -> data ;
				q -> data = r -> data ;
				r -> data = temp ;
			}
			r = r -> nextptr ;
		}
		q = q -> nextptr ;
	}
}

// sort list using bubble sort
void linklist :: bubble_sort ( int n )
{
	int k, temp ;
	node *q, *r ;

	k = n ;
	for ( int i = 0 ; i < n - 1 ; i++, k-- )
	{
		q = lp ;
		r = q -> nextptr ;

		for ( int j = 1 ; j < k ; j++ )
		{
			if ( q -> data > r -> data )
			{
				temp = q -> data ;
				q -> data = r -> data ;
				r -> data = temp ;
			}
			q = q -> nextptr ;
			r = r -> nextptr ;
		}
	}
}// call copy to copy a linked list into another



// copies a linked list into another
/*void linklist :: copy ( linklist& l)
{node* ptr1=lp;
node** ptr2=&(l.lp);
	if ( ptr1 != NULL )
	{
		*ptr2 = new node ;

		(*ptr2) -> data = ptr1 -> data ;
		(*ptr2) -> nextptr = NULL ;
		l=lp->nextptr;

		copy (l) ;
	}
}*/
void linklist::printListInReverse(node* head){
if (head != NULL) {
    printListInReverse(head->nextptr);
	std::cout << head->data <<" ";
  }
}

void linklist::printLast3rdNode( )
{
	node* current=lp;
	node* thirdCurrent=lp->nextptr->nextptr;
	while(thirdCurrent->nextptr != NULL )
	{   current=current->nextptr;
		thirdCurrent=thirdCurrent->nextptr;}
	std::cout << "\n" << std::endl;
	std::cout << current->data << std::endl;
}
int linklist::GetNth(int index)
{
    struct node* current = lp;
    int count = 0; /* the index of the node we're currently
                  looking at */
    while (current != NULL)
    {
       if (count == index)
	   {
		   std::cout << "\n" << current->data << std::endl;
	       return(current->data);
	   }
       count++;
       current = current->nextptr;
    }
   
    /* if we get to this line, the caller was asking
       for a non-existent element so we assert fail */
    //assert(0);            
}
void linklist::getMiddleNode(){
node* ptr1=lp;
node* ptr2=lp->nextptr;
	while(ptr2){
		ptr1=ptr1->nextptr;
		ptr2=(ptr2->nextptr)? ptr2->nextptr->nextptr : 0;
        	}
	//return ptr1;
std::cout << "\n" << ptr1-> data << std::endl;
}

void intersectTwoLists(linklist& l1,linklist& l2,int pos){
	linklist::node* ptr1=l1.lp;
	linklist::node* ptr2=l2.lp;
	while(--pos && ptr1->nextptr != NULL ){
		ptr1=ptr1->nextptr;
	}
	while(ptr2->nextptr != NULL ){
		ptr2=ptr2->nextptr;
	}

	ptr2->nextptr=ptr1;
}
void checkLinkedListIsMergedOrNot(linklist& l1, linklist& l2){
	linklist::node* ptr1=l1.lp;
	linklist::node* ptr2=l2.lp;

	while(ptr1->nextptr !=NULL) ptr1=ptr1->nextptr;
	while(ptr2->nextptr !=NULL) ptr2=ptr2->nextptr;
	if(ptr1 == ptr2)
		std::cout <<"\n Intersect is true\n" << std::endl;
	else
		std::cout<<"\n Intersect is false\n" << std::endl;
}
void getCrossPoint(linklist& l1,linklist& l2){
	linklist::node* tmp1=l1.lp;
	linklist::node* tmp2=l2.lp;
	int diff=abs(l1.count()-l2.count());
	
		while(diff--){
			if(l1.count() > l2.count()){
			tmp1=tmp1->nextptr;
			}
			else{
				tmp2=tmp2->nextptr;
				}
		}
		std::cout <<" temp1->data "<< " " << tmp1->data << " temp2->data " << " " << tmp2->data << std::endl;
		while(tmp1 != tmp2){
			tmp1=tmp1->nextptr;
			tmp2=tmp2->nextptr;
		}
		std::cout << " temp1->data == tmp2->data " << tmp1->data << std::endl;
}
void detectloop(linklist& l)
{
	linklist::node  *slow_p = l.lp, *fast_p = l.lp;
 
  while(slow_p && fast_p &&
          fast_p->nextptr )
  {
    slow_p = slow_p->nextptr;
    fast_p  = fast_p->nextptr->nextptr;
    if (slow_p == fast_p)
    {
       printf("Found Loop");
       //return 1;
    }
  }
  //return 0;
}
int main()
{    linklist l ;

	l.append ( 14 ) ;
	l.append ( 30 ) ;
	l.append ( 25 ) ;
	l.append ( 42 ) ;
	l.append ( 17 ) ;

    cout << "\nElements in the linked list: " ;
	l.display( ) ;

	l.addatbeg ( 999 ) ;
	l.addatbeg ( 888 ) ;
	l.addatbeg ( 777 ) ;
	l.addatbeg(333);
	l.addatbeg(44);

    cout << "\n\nElements in the linked list after addition at the beginning: " ;
	l.display( ) ;

	l.addafter ( 7, 0 ) ;
	l.addafter ( 2, 1 ) ;
	l.addafter ( 5, 99 ) ;

    cout << "\n\nElements in the linked list after addition at given position: " ;
	l.display( ) ;
	cout << "\nNo. of elements in the linked list " << l.count( ) ;

	l.del ( 99 ) ;
	l.del ( 1 ) ;
	//l.del ( 10 ) ;

    cout << "\n\nElements in the linked list after deletion: " ;
	l.display( ) ;
	cout << "\nNo. of elements in the linked list: " << l.count( ) ;
	l.reverse();
	l.display();
	std::cout << "\n" << std::endl;
	l.printListInReverse(l.lp);
	l.printLast3rdNode();
	l.GetNth(4);
	l.getMiddleNode();

	linklist l1 ;

	l1.append ( 14 ) ;
	l1.append ( 15 ) ;
	l1.append ( 16 ) ;
	l1.append ( 17 ) ;
	l1.append ( 18 ) ;
	l1.append ( 19 ) ;
	l1.append ( 20) ;

	l1.display();

	linklist l2;
	l2.append(101);
	l2.append(102);
	l2.append(103);
	l2.append(104);
	l2.append(105);
	l2.append(106);
	l2.append(107);
	l2.display();
checkLinkedListIsMergedOrNot(l1,l2);
	intersectTwoLists(l1,l2,4);
	 l1.display();
	 l2.display();
	checkLinkedListIsMergedOrNot(l1,l2);
	getCrossPoint(l1,l2);
	return 0;
}

