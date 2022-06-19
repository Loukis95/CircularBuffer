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
		for(auto i = 0; i < 5; ++i) {
			push(buffer, 'a' + i);
		}

		std::cout << "Attempt to access data at position 0: ";
		c = buffer[0];
		assert(c == 'a');
		std::cout << "Success" << std::endl;
	
		std::cout << "Attempt to access data at position 1: ";
		c = buffer[1];
		assert(c == 'b');
		std::cout << "Success" << std::endl;

		std::cout << "Attempt to access data at position 2: ";
		c = buffer[2];
		assert(c == 'c');
		std::cout << "Success" << std::endl;

		std::cout << "Attempt to access data at position 3: ";
		c = buffer[3];
		assert(c == 'd');
		std::cout << "Success" << std::endl;

		std::cout << "Attempt to access data at position 4: ";
		c = buffer[4];
		assert(c == 'e');
		std::cout << "Success" << std::endl;

		try
		{
			std::cout << "Attempt to access data at position 5: ";
			buffer[5];
			std::cerr << "Buffer access at position 6 shall fail." << std::endl;
        	return 1;
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "Expected exception: ";
			std::cout << e.what() << std::endl;
		}
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
