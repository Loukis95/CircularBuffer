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
		std::cout << "Fill buffer" << std::endl;
		for(auto i = 0; i < 5; ++i) {
			buffer.push_back('a' + i);
		}
		print_buffer(buffer);

		{
			std::cout << "Check if iterator is a forward iterator: ";
			auto it = buffer.rbegin();
			auto end = buffer.rend();
			assert(it != end);
			assert(*it++ == 'e');
			assert(*it++ == 'd');
			assert(*it++ == 'c');
			assert(*it++ == 'b');
			assert(*it == 'a');
			assert(++it == end);
			std::cout << "True" << std::endl;
		}

		{
			std::cout << "Check if iterator is a biderectional iterator: ";
			auto it = buffer.rbegin();
			auto end = buffer.rend();
			assert(*it++ == 'e');
			assert(*it++ == 'd');
			assert(*it++ == 'c');
			assert(*it++ == 'b');
			assert(*it++ == 'a');
			assert(it-- == end);
			assert(*it-- == 'a');
			assert(*it-- == 'b');
			assert(*it-- == 'c');
			assert(*it == 'd');
			assert(--it == buffer.rbegin());
			assert(*it == 'e');
			std::cout << "True" << std::endl;
		}
		
		{
			std::cout << "Check if iterator is a random access iterator: ";
			auto it = buffer.rbegin();
			auto end = buffer.rend();
			assert(it < end);
			assert(it <= end);
			assert(end >= it);
			assert(end - it == 5);
			assert(end - 5 == it);
			assert(it + 5 == end);
			assert(5 + it == end);
			assert(it[0] == 'e');
			assert(it[1] == 'd');
			assert(it[2] == 'c');
			assert(it[3] == 'b');
			assert(it[4] == 'a');
			assert((end+=-3) == (it+=2));
			std::cout << "True" << std::endl;
		}
		
		{
			std::cout << "Can be reversed: ";
			auto it = std::make_reverse_iterator(buffer.rbegin());
			auto end = std::make_reverse_iterator(buffer.rend());
			assert(it[0] == 'a');
			assert(it[1] == 'b');
			assert(it[2] == 'c');
			assert(it[3] == 'd');
			assert(it[4] == 'e');
			std::cout << "True" << std::endl;
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
