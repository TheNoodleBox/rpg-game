#pragma once
#include <iostream>
#include <fstream>

class MapLoader
{
	std::ofstream fileStream;

public:
	void Load(std::string filename);
};