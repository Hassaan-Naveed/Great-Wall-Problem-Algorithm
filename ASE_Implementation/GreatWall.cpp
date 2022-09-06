//Function definitions for GreatWall.h

#include "GreatWall.h"

void GreatWall::loadBricks(std::ifstream& file)
{
	std::string line;

	//Get each line in text file
	while (std::getline(file, line)) //o(n)
	{
		//Split line by "," to seperate north and south names
		std::string northName = line.substr(0, line.find(DELIM));
		std::string southName = line.substr(line.find(DELIM) + 1);

		//Add names to unordered map
		bricks[northName] = southName;
		bricksR[southName] = northName;
	}
}

void GreatWall::buildSequence() 
{
	//Select first item in map to begin sequence
	sequence.push_back(bricks.begin()->first);
	sequence.push_back(bricks.begin()->second);
	
	//Until there is no matching brick found, search for brick with a northern name that matches last name in sequence
	bool noMatchEnd = false;
	while (!noMatchEnd)
	{
		std::string brick = sequence.back();

		if (bricks.find(brick) == bricks.end()) {
			noMatchEnd = true;
		}
		else {
			//Add to end of sequence
			sequence.push_back(bricks[brick]);
		}
	}
	
	//Until there is no matching brick found, search for brick with southern name that matches first name in sequence
	bool noMatchStart = false;
	while (!noMatchStart)
	{
		std::string brick = sequence.front();

		if (bricksR.find(brick) == bricksR.end())
		{
			noMatchStart = true;
		}
		else 
		{
			//Add to end of sequence
			sequence.push_front(bricksR[brick]);
		}
	}
	
}

void GreatWall::outputSequence() 
{
	//Iterate through result sequence and output results
	for (auto v : sequence) 
	{
		std::cout << v << std::endl;
	}
}