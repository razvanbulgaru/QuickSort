// Generates a random number array

#include <fstream>
#include <iostream>
#include <cstdlib>

int main()
{
	std::ofstream file;
	file.open("Array.txt");

	for (int i = 0; i < 1000; ++i)
	{
		file << rand() % 10 + 1 << std::endl;
	}
}