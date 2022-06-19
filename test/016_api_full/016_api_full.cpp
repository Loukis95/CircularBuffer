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

		for(auto i = 0; i < 5; ++i) {
			std::cout << "Checking if buffer is full: ";
			bool is_full = buffer.full();
			assert(!is_full);
			std::cout << "False" << std::endl;
		
			push(buffer, 'a');
		}

		std::cout << "Checking if buffer is full now: ";
		bool is_full = buffer.full();
		assert(is_full);
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
