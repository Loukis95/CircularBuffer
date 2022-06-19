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
		push(buffer, 'a');
		void* fisrt = &buffer.back();
		c = pop(buffer);
		assert(c == 'a');

		for(auto i = 0; i < 4; ++i) {
			push(buffer, 'a');
			c = pop(buffer);
			assert(c == 'a');
		}

		push(buffer, 'b');
		void* second = &buffer.back();
		c = pop(buffer);
		assert(c == 'b');

		assert(fisrt == second);

		std::cout << "Head can wrap around the circular buffer." << std::endl;
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
