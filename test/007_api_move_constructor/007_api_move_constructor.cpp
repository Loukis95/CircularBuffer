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
		for(auto i = 0; i < 5; ++i) {
			push(buffer, 'a' + i);
		}

		std::cout << "Calling the move constructor" << std::endl;
		lfr::CircularBuffer<char, 5> other(std::move(buffer));

		assert(other.size() == 5);
		assert(other[0] == 'a');
		assert(other[1] == 'b');
		assert(other[2] == 'c');
		assert(other[3] == 'd');
		assert(other[4] == 'e');
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
