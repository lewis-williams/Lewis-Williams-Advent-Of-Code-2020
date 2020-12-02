// Advent of Code 2020 Day 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <numeric>

constexpr int SUM_TO_FIND = 2020;

void get_input(std::vector<int>& module_list)
{
	std::ifstream f("input.txt");
	std::string temp = "";

	if (f.is_open())
	{
		while (std::getline(f, temp))
		{
			//std::cout << temp << " saved to vector";
			const int& value = std::stoi(temp);
			module_list.push_back(value);
		}

		f.close();

	}

}

//part 1
int find_sum(std::vector<int> expenses)
{
	for (auto recordA : expenses)
	{
		for (auto recordB : expenses)
		{
			if( recordA + recordB == SUM_TO_FIND)
			{
				return recordA * recordB;
			}
		}
	}

	return 0;
}

int find_product(std::vector<int> expenses)
{
	for (auto recordA : expenses)
	{
		for (auto recordB : expenses)
		{
			for (auto recordC : expenses)
			{
				if (recordA + recordB + recordC == SUM_TO_FIND)
				{
					return (recordA * recordB) * recordC;
				}
			}
		}
	}

	return 0;
}
int main()
{
	std::vector<int> expense_entries;
	get_input(expense_entries);

	//part 1
	int final_sum = find_sum(expense_entries);

	std::cout << "Final Sum: " << final_sum << std::endl;

//part 2

	int final_product = find_product(expense_entries);

	std::cout << "Product: " << final_product << std::endl;
}

