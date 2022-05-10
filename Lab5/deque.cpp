#include "deque.h"
#include <iomanip>
#include <iostream>

using namespace std;

bool deque::is_empty() const
//is list empty
{
	return deque::first == nullptr;
}

bool deque::is_full() const
{
	return size == max_size;
}

bool deque::is_even(const int number)
{
	return  number % 2 == 0;
}

void deque::rand_fill(const int amount) // generate one random element
{
	srand(time(nullptr));
	for(int i =0;i<amount;i++)
	{
	push_back(rand()%101);
	}
}

void  deque::push_back(const int new_data) // adds element to the end of list
{
	if(is_full())
	{
		return;
	}
	const auto new_elem = new node(new_data); // element init
	++size;
	if (is_empty()) // is list empty
	{
		deque::first = new_elem; // adding element
		deque::last = new_elem;
		first->next=first;
		return;
	}
	deque::last->next = new_elem; //if list not empty
	deque::last = new_elem;  //then we point that new element is after last element in list
	last->next=first;
	if(is_even(new_data) and new_data!=0)
	{
		push_back(0);
	}
}

void deque::push_front(const int new_data)
{
	if(is_full())
	{
		return;
	}
	++size;
	const auto new_elem = new node(new_data); // element init
	node* second = first;
	if (is_empty()) // is list empty
	{
		deque::first = new_elem; // adding element
		deque::last = new_elem;
		first->next=first;
		return;
	}
	first = new_elem;
	new_elem->next=second;
	last->next=first;
	if(is_even(new_data) and new_data!=0)
	{
		push_back(0);
	}
}

void deque::pop_back() const
{
	if(is_empty())
	{
		return;
	}
	std::cout<<last->val;
	delete last;
}

void deque::pop_front() const
{
	if(is_empty())
	{
		return;
	}
	std::cout<<first->val;
	delete first;
	
}

void deque::clear()
{
	if(is_empty())
	{
		return;
	}
	do
	{
		node* temp = deque::first; 
		deque::first = deque::first->next; //delete first element and assign first second element
		last->next = first->next;
		delete temp; //delete element
	}while(deque::first!= last);
	delete first;
	first=nullptr;
	  //while there are an element avalaible
	size=0;
}

void deque::delete_element(const int key)
{
	node* del_el = find(key);
	if(del_el==nullptr)
	{
		cout<<"Element does not exist.\n";
		return;
	}
	--size;
	node* next_el= del_el->next; //remember which element stands after deleted
	node* node1 = deque::first;
	node* second = deque::first->next;
	do
	 { //while there are an element 
		if(node1->next==del_el) //find element before deleted element
		{
			if(node1->next==last)
			{
				node1->next=next_el; // rechain list without that element
				last=node1;
				delete del_el; //deleting element
				return;
			}
			node1->next=next_el; // rechain list without that element
			delete del_el; //deleting element
			return;
		}
		node1 = node1->next;
	}while (node1!=last);
	if(node1->next==del_el) //find element before deleted element
		{
			node1->next=second; // rechain list without that element
			delete del_el; //deleting element
		}
}

node* deque::find(int key) const
{
	
	node* node1 = deque::first;
	do
	{ //while there are an element 
		if(key == node1->val)
		{
		return node1;	
		}
		node1 = node1->next;
	}while (node1!=last) ;
	if(key == node1->val)
	{
		return node1;	
	}
	return nullptr; // if element not found
}

void deque::show() const
{
	if (is_empty()) 
	{
		cout<<"List is empty"<<endl; 
		return;
	}
	cout<<static_cast<char>(201); //fancy stuff
	for(int i=0;i<10;i++)
	{
		cout<<static_cast<char>(205);
	}
	cout<<static_cast<char>(187)<<endl;
	cout<<static_cast<char>(186)<<left<<setw(10)<<"DEQUE"<<static_cast<char>(186)<<endl;
	cout<<static_cast<char>(204);
		for(int i=0;i<10;i++)
	{
		cout<<static_cast<char>(205);
	}

	cout<<static_cast<char>(185)<<endl;
	node* node1 = deque::first;
	
	do
	{ //while there are an element 
		cout <<static_cast<char>(186)<<setw(10)<< node1->val<<right <<static_cast<char>(186)<<left<< endl;
		node1 = node1->next;
	}while (node1!=last);
	cout <<static_cast<char>(186)<<setw(10)<< node1->val <<right <<static_cast<char>(186)<<left<< endl;
		node1 = node1->next;
	cout<<static_cast<char>(200);
		for(int i=0;i<10;i++)
	{
		cout<<static_cast<char>(205);
	}
	cout<<static_cast<char>(188)<<endl;
}
