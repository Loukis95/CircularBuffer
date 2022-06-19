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
	char c;
	lfr::CircularBuffer<char, 5> buffer;

	try
	{
		try
		{
			std::cout << "Attempting to retrieve the back element when the buffer is empty" << std::endl;
			c = buffer.back();
			std::cerr << "Calling back() on an empty buffer shall fail" << std::endl;
			return 1;
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "Expected exception: ";
			std::cout << e.what() << std::endl;
		}

		push(buffer, 'a');

		std::cout << "Attempting to retrieve the back element" << std::endl;
		c = buffer.back();
		assert(c == 'a');
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
