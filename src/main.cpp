#include <iostream>
#include "CircularBuffer.hpp"

int main(int argc, char** argv)
{
	lfr::CircularBuffer<char, 5> buffer;

	std::cout << buffer << std::endl;
	std::cout << std::endl;

	std::cout << "Push 'a'" << std::endl;
	buffer.push_back('a');
	std::cout << buffer << std::endl;
	std::cout << std::endl;

	std::cout << "Push 'b'" << std::endl;
	buffer.push_back('b');
	std::cout << buffer << std::endl;
	std::cout << std::endl;

	std::cout << "Push 'c'" << std::endl;
	buffer.push_back('c');
	std::cout << buffer << std::endl;
	std::cout << std::endl;

	std::cout << "Push 'd'" << std::endl;
	buffer.push_back('d');
	std::cout << buffer << std::endl;
	std::cout << std::endl;

	std::cout << "Push 'e'" << std::endl;
	buffer.push_back('e');
	std::cout << buffer << std::endl;
	std::cout << std::endl;
	
	std::cout << "Pop" << std::endl;
	buffer.pop_front();
	std::cout << buffer << std::endl;
	std::cout << std::endl;
	
	std::cout << "Push 'f'" << std::endl;
	buffer.push_back('f');
	std::cout << buffer << std::endl;
	std::cout << std::endl;

	while(!buffer.empty()) {
		std::cout << "Pop" << std::endl;
		buffer.pop_front();
		std::cout << buffer << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Buffer is empty !" << std::endl;

	return 0;
}
