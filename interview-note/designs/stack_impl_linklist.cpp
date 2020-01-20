#include <iostream>

// A linked list node
struct node
{
	int data;	
	node* next;
};
struct mystack
{
	node* head;
	mystack():head(nullptr){}
	~mystack()
	{
		node* temp=nullptr;
		while(head != nullptr)
		{
			temp=head;
			head=head->next;
			delete temp;
		}
	}

	void push(int x);
	void pop();
	int top()
	{
		if(head != nullptr)
		{
			return head->data;
		}
		else
		{
			return 0;
		}
	}
	bool empty()
	{
		return head == nullptr;
	}
};

void mystack::push(int x) 
{
	node* tmp = new node();
	tmp->data = x;
	if(head==nullptr)
	{
		head=tmp;
		tmp->next=nullptr;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
}

// Utility function to pop top element from the stack
void mystack::pop()
{
	node* temp=new node();
	if (head == nullptr)
	{
		std::cout<<"Stack Underflow" << std::endl;
		return;
	}
	temp = head;
	head = head->next;
	delete temp;
}

// main function
int main()
{
	mystack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	std::cout << s.top() << '\n';
}
