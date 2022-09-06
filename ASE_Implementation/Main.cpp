// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "GreatWall.h"

int main(int argc, char* argv[])
{
	//Check that file has been given in command line arguments
	if (argc != 2)
	{
		std::cout << "Error, please provide file location" << std::endl;
	}
	else
	{
		//Check that file exists
		std::ifstream file(argv[1]);
		if (!file.is_open())
		{
			std::cout << "Error, could not open the file" << std::endl;
		}
		else
		{
			GreatWall greatWall;

			greatWall.loadBricks(file);
			greatWall.buildSequence();
			greatWall.outputSequence();
		}
	}

	return 0;
}