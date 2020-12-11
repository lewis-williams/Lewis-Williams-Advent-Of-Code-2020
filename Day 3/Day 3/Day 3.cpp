// Day 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <fstream> 
#include <regex>
#include <utility>
#include <time.h>
#include <stdlib.h>
#include <map>


constexpr char tree = '#';


int trees_hit( uint8_t x, uint8_t y, std::vector<std::string> map_lines )
{
	int trees = 0;
	int x_distance = 0;
	int y_distance = 0;
	size_t map_length = map_lines[0].length();

	while ( y_distance < map_lines.size() )
	{
		if ( map_lines.at( y_distance ).at( x_distance % map_length ) == tree )
		{
			++trees;
			
		}

		x_distance += x;
		y_distance += y;
	}

	return trees;

}

int main()
{

	std::ifstream file( "input.txt" );

	if ( !file )
	{
		std::cout << "Failed to load input file";
		return false;
	}

	std::vector<std::string> map_lines;
	std::string lines;

	while ( std::getline( file, lines ) )
	{
		map_lines.push_back( lines );
	}

	//<----PART 1----->	

	auto P1A = trees_hit( 3, 1, map_lines );
	std::cout << "part 1: Trees Hit on Slope 3, 1" << P1A << std::endl;

	//<<------PART 2------->

	auto P2A = trees_hit( 1, 1, map_lines );
	auto P2B = P1A;
	auto P2C = trees_hit( 5, 1, map_lines );
	auto P2D = trees_hit( 7, 1, map_lines );
	auto P2E = trees_hit( 1, 2, map_lines );

	std::cout << "Trees Multiplied together: " << P2A * P2B * P2C * P2D * P2E << std::endl;

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
