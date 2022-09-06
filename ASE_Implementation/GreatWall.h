#pragma once

#include <unordered_map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class GreatWall
{
public:
	const std::string DELIM = ",";

	std::unordered_map<std::string, std::string> bricks;
	std::unordered_map<std::string, std::string> bricksR;
	std::list<std::string> sequence;

	void loadBricks(std::ifstream& file);
	void buildSequence();
	void outputSequence();
};