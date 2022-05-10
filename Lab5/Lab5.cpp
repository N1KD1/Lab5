#include <iostream>
#include "deque.h"

int main()
{
	deque new_deque;
	
	new_deque.rand_fill(20);
	new_deque.show();

	std::cout<<new_deque.size;
}

