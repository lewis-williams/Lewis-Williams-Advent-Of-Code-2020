// Day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


struct password_details
{
	int minimum_value = 0;
	int maximum_value = 0;
	char character_to_find = -1;
	std::string password = "";
};

void get_input(std::vector<password_details>& passwords)
{
	std::ifstream f("input.txt");
	std::string temp = "";
	password_details new_password;

	if (f.is_open())
	{
		while (std::getline(f, temp))
		{
			//get each individual setting and set it to the new_password.
			std::string temp_min, temp_max, temp_char, temp_password;
			std::stringstream temp_stream(temp);
			std::getline(temp_stream, temp_min, '-');
			std::getline(temp_stream, temp_max, ' ');
			std::getline(temp_stream, temp_char, ':');
			std::getline(temp_stream, temp_password, '\n');


			new_password.minimum_value = std::stoi(temp_min);
			new_password.maximum_value = std::stoi(temp_max);
			new_password.character_to_find = temp_char.front();
			new_password.password = temp_password;

			passwords.push_back(new_password);

		}

		f.close();

	}

}

//part 1
int find_valid_password_count(std::vector<password_details> passwords)
{
	int valid_passwords = 0;

	for (size_t i = 0; i < passwords.size(); ++i)
	{
		int found_value = 0;
		for (size_t j = 0; j < passwords[i].password.size(); ++j)
		{

			if (passwords[i].password[j] == passwords[i].character_to_find)
			{
				++found_value;
			}

			if (found_value > passwords[i].maximum_value)
			{
				break;
			}


		}

		if (found_value >= passwords[i].minimum_value && found_value <= passwords[i].maximum_value)
		{
			++valid_passwords;
		}

	}

	return valid_passwords;
}

//part 2
int find_valid_password_positions(std::vector<password_details> passwords)
{
	int valid_passwords = 0;

	for (auto password_value : passwords)
	{
		bool found_in_position = false;

		if (password_value.password[password_value.minimum_value] == password_value.character_to_find)
		{
			found_in_position = true;
		}

		if (password_value.password[password_value.maximum_value] == password_value.character_to_find)
		{
			if (!found_in_position)
			{
				found_in_position = true;
			}

			else
			{
				found_in_position = false;
			}
		}

		if (found_in_position)
		{
			++valid_passwords;
		}

	}

	return valid_passwords;
}

int main()
{

	std::vector<password_details> passwords;
	get_input(passwords);


	std::cout << "Number of Valid Passwords: " << find_valid_password_count(passwords) << std::endl;
	std::cout << "Number of Valid Passwords: " << find_valid_password_positions(passwords) << std::endl;

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
