#include <cassert>
#include <iostream>
#include "CircularBuffer.hpp"

void print_buffer(const lfr::CircularBuffer<char, 5>& buffer) {
	std::cout << buffer << std::endl;
	std::cout << std::endl;
}

void push(lfr::CircularBuffer<char, 5>& buffer, char c) {
	std::cout << "Push '" << c << "'" << std::endl;
	buffer.push_back(c);
	print_buffer(buffer);
}

char pop(lfr::CircularBuffer<char, 5>& buffer) {
	char c = buffer.front();
	buffer.pop_front();
	std::cout << "Pop '" << c << "'" << std::endl;
	print_buffer(buffer);
	return c;
}

int main(int argc, char** argv)
{
	lfr::CircularBuffer<char, 5> buffer;

	try
	{
		std::size_t size;
 
		for(auto i = 0; i < 5; ++i) {
			std::cout << "Checking if size is " << i << " : ";
			size = buffer.size();
			assert(size == i);
			std::cout << "True" << std::endl;
			push(buffer, 'a');
		}
		std::cout << "Buffer is full, checking if size is 5 : ";
		assert(buffer.size() == 5);
		std::cout << "True" << std::endl;
	
		std::cout << "Checking if max_size is 5 : ";
		size = buffer.max_size();
		assert(size == 5);
		std::cout << "True" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unexpected exception: ";
		std::cerr << e.what() << std::endl;
        return 1;
	}

	std::cout << "Great Success !" << std::endl;
    return 0;
}
