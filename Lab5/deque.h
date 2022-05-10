#pragma once

constexpr auto max_size = 10;

struct node {
	int val;
	node* next;
	explicit node(const int val) : val(val), next(nullptr) {}
};

struct deque
{
	node* first;
	node* last;
	int size;
	deque() : first(nullptr), last(nullptr), size(0) {}
	bool is_empty() const;
	bool is_full() const;
	void rand_fill(int amount);
	void show() const;
	void push_back(int new_data);
	void push_front(int new_data);
	void pop_back() const;
	void pop_front() const;
	void clear();
	void delete_element(int key);
	node* find(int key) const;
	private:
	static bool is_even(const int number);
};