#include "deque.h"
#include <iomanip>
#include <iostream>

using namespace std;

bool deque::is_empty()
//is list empty
{
	return deque::first_ == nullptr;
}

void deque::rand_fill(int size) // generate one random element
{
	srand(time(nullptr));
	for(int i =0;i<size;i++)
	{
	push_back(rand()%101);
	}
}

void  deque::push_back(const int new_data) // adds element to the end of list
{
	const auto new_elem = new node(new_data); // element init
	if (is_empty()) // is list empty
	{
		deque::first_ = new_elem; // adding element
		deque::last_ = new_elem;
		first_->next=first_;
		return;
	}
	deque::last_->next = new_elem; //if list not empty
	deque::last_ = new_elem;  //then we point that new element is after last element in list
	last_->next=first_;
}

void deque::push_front(const int new_data)
{
	const auto new_elem = new node(new_data); // element init
	node* second = first_;
	if (is_empty()) // is list empty
	{
		deque::first_ = new_elem; // adding element
		deque::last_ = new_elem;
		first_->next=first_;
		return;
	}
	first_ = new_elem;
	new_elem->next=second;
	last_->next=first_;
}

void deque::pop_back()
{
	std::cout<<last_->val;
	delete last_;
}

void deque::pop_front()
{
	std::cout<<first_->val;
	delete first_;
}

void deque::clear()
{
	do
	{
		node* temp = deque::first_; 
		deque::first_ = deque::first_->next; //delete first element and assign first second element
		last_->next = first_->next;
		delete temp; //delete element
	}while(deque::first_!= last_);
	delete first_;
	first_=nullptr;
	  //while there are an element avalaible
}

void deque::delete_element(const int key)
{
	node* del_el = find(key);
	if(del_el==nullptr)
	{
		cout<<"Element does not exist.\n";
		return;
	}
	node* next_el= del_el->next; //remember which element stands after deleted
	node* node1 = deque::first_;
	node* second = deque::first_->next;

	do
	 { //while there are an element 
		if(node1->next==del_el) //find element before deleted element
		{
			if(node1->next==last_)
			{
				node1->next=next_el; // rechain list without that element
				last_=node1;
				delete del_el; //deleting element
				return;
			}
			node1->next=next_el; // rechain list without that element
			delete del_el; //deleting element
			return;
		}
		node1 = node1->next;
	}while (node1!=last_);
	if(node1->next==del_el) //find element before deleted element
		{
			node1->next=second; // rechain list without that element
			delete del_el; //deleting element
		}
}

node* deque::find(int key)
{
	
	node* node1 = deque::first_;
	do
	{ //while there are an element 
		if(key == node1->val)
		{
		return node1;	
		}
		node1 = node1->next;
	}while (node1!=last_) ;
	if(key == node1->val)
	{
		return node1;	
	}
	return nullptr; // if element not found
}

void deque::show() 
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
	node* node1 = deque::first_;
	
	do
	{ //while there are an element 
		cout <<static_cast<char>(186)<<setw(10)<< node1->val<<right <<static_cast<char>(186)<<left<< endl;
		node1 = node1->next;
	}while (node1!=last_);
	cout <<static_cast<char>(186)<<setw(10)<< node1->val <<right <<static_cast<char>(186)<<left<< endl;
		node1 = node1->next;
	cout<<static_cast<char>(200);
		for(int i=0;i<10;i++)
	{
		cout<<static_cast<char>(205);
	}
	cout<<static_cast<char>(188)<<endl;
}
