#pragma once

struct Coordinate 
{
private:
	int xco;
	int yco;

public:
	Coordinate(int, int);
	void display();
	static bool isEqual(Coordinate, Coordinate);
};