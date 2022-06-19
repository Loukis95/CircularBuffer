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
		print_buffer(buffer);

		std::cout << "Trying to pop when buffer is empty" << std::endl;
		buffer.pop_front();

		while(!buffer.full()) {
			push(buffer, 'a');
		}

		std::cout << "Checking if buffer is full" << std::endl;
		assert(buffer.size() == buffer.max_size());

		while(!buffer.empty()) {
			pop(buffer);
		}

		std::cout << "Checking if buffer is empty" << std::endl;
		assert(buffer.size() == 0);
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
