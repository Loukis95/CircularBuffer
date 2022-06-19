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
	lfr::CircularBuffer<char, 5> buffer, other;

	try
	{
		std::cout << "Fill buffer 1" << std::endl;
		for(auto i = 0; i < 5; ++i) {
			buffer.push_back('a' + i);
		}
		print_buffer(buffer);

		std::cout << "Fill buffer 2" << std::endl;
		for(auto i = 0; i < 5; ++i) {
			other.push_back('A' + i);
		}
		print_buffer(other);

		std::cout << "Swaping buffers" << std::endl;
		std::swap(buffer, other);

		std::cout << "Buffer 1" << std::endl;
		print_buffer(buffer);
	
		std::cout << "Buffer 2" << std::endl;
		print_buffer(other);
	
		assert(other.size() == 5);
		assert(other[0] == 'a');
		assert(other[1] == 'b');
		assert(other[2] == 'c');
		assert(other[3] == 'd');
		assert(other[4] == 'e');
		
		assert(buffer.size() == 5);
		assert(buffer[0] == 'A');
		assert(buffer[1] == 'B');
		assert(buffer[2] == 'C');
		assert(buffer[3] == 'D');
		assert(buffer[4] == 'E');

		std::cout << "Swaping buffers again" << std::endl;
		buffer.swap(other);

		std::cout << "Buffer 1" << std::endl;
		print_buffer(buffer);
	
		std::cout << "Buffer 2" << std::endl;
		print_buffer(other);
	
		assert(buffer.size() == 5);
		assert(buffer[0] == 'a');
		assert(buffer[1] == 'b');
		assert(buffer[2] == 'c');
		assert(buffer[3] == 'd');
		assert(buffer[4] == 'e');
		
		assert(other.size() == 5);
		assert(other[0] == 'A');
		assert(other[1] == 'B');
		assert(other[2] == 'C');
		assert(other[3] == 'D');
		assert(other[4] == 'E');
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
