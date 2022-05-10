#pragma once

struct node {
	int val;
	node* next;
	explicit node(int val) : val(val), next(nullptr) {}
};

struct deque
{
	node* first_;
	node* last_;
	deque() : first_(nullptr), last_(nullptr) {}
	bool is_empty();
	void rand_fill(int size);
	void show();
	void push_back(int new_data);
	void push_front(int new_data);
	void pop_back();
	void pop_front();
	void clear();
	void delete_element(const int key);
	node* find(int key);
};