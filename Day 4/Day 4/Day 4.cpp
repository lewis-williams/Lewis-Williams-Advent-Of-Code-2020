// Day 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>

constexpr auto YOB_KEY = "byr";
constexpr auto ISSUE_KEY = "iyr";
constexpr auto EXPIRE_KEY = "eyr";
constexpr auto HEIGHT_KEY = "hgt";
constexpr auto HAIR_KEY = "hcl";
constexpr auto EYE_KEY = "ecl";
constexpr auto ID_KEY = "pid";
constexpr auto COUNTRY_KEY = "cid";

constexpr auto HEIGHT_CHECK_CM = "cm";
constexpr auto HEIGHT_CHECK_INCH = "in";

struct PASSPORT
{
	std::string Year_of_Birth;
	std::string issue_year;
	std::string expiration_date;
	std::string height;
	std::string hair_color;
	std::string eye_color;
	std::string country_id;
	std::string passport_id;
	size_t maximum_digits = 4;

	bool check_yob() { return Year_of_Birth.size() == maximum_digits && std::stoi( Year_of_Birth ) >= 1920 && std::stoi( Year_of_Birth ) <= 2002; }

	bool check_issue() { return issue_year.size() == maximum_digits && std::stoi( issue_year ) >= 2010 && std::stoi( issue_year ) <= 2020; }

	bool check_expiry() { return expiration_date.size() == maximum_digits && std::stoi( expiration_date ) >= 2020 && std::stoi( expiration_date ) <= 2030; }




	bool check_height()
	{

		if ( height.find( HEIGHT_CHECK_CM ) != std::string::npos )
		{
			return (std::stoi( height ) >= 150 && std::stoi( height ) <= 193);
		}

		else if ( height.find( HEIGHT_CHECK_INCH ) != std::string::npos )
		{

			return (std::stoi( height ) >= 59 && std::stoi( height ) <= 76);

		}


		return false;

	}


	bool check_hair_colour()
	{
		if ( hair_color.size() == 7 && hair_color[0] == '#' )
		{
			std::string splt_str = hair_color.substr( 1, hair_color.size() );
			return splt_str.find_first_not_of( "0123456789abcdef" ) == std::string::npos;
		}
		return false;
	}

	bool check_eye_colour() { return eye_color == "amb" || eye_color == "blu" || eye_color == "brn" || eye_color == "gry" || eye_color == "grn" || eye_color == "hzl" || eye_color == "oth"; }

	bool check_passport_id() { return passport_id.size() == 9 && passport_id.find_first_not_of( "0123456789" ) == std::string::npos; };
};

PASSPORT parse_passports( std::string& passport_string )
{
	PASSPORT new_passport;
	std::stringstream temp_stream( passport_string );
	std::string word;
	std::string key;
	std::string value;

	while ( temp_stream >> word )
	{
		std::stringstream value_str( word );
		std::getline( value_str, key, ':' );
		std::getline( value_str, value, ' ' );

		if ( key == YOB_KEY )
		{
			new_passport.Year_of_Birth = value;
		}
		if ( key == ISSUE_KEY )
		{
			new_passport.issue_year = value;

		}
		if ( key == EXPIRE_KEY )
		{
			new_passport.expiration_date = value;
		}
		if ( key == HEIGHT_KEY )
		{
			new_passport.height = value;
		}
		if ( key == EYE_KEY )
		{
			new_passport.eye_color = value;
		}
		if ( key == HAIR_KEY )
		{
			new_passport.hair_color = value;
		}
		if ( key == ID_KEY )
		{
			new_passport.passport_id = value;
		}
		if ( key == COUNTRY_KEY )
		{
			new_passport.country_id = value;
		}

	}

	passport_string.clear();
	return new_passport;



}


int main()
{
	std::ifstream f( "input.txt" );
	std::string temp = "";

	std::vector<PASSPORT> passport_array;
	if ( f.is_open() )
	{
		std::string full_passport_string;
		while ( std::getline( f, temp ) )
		{
			//shamelessly had issues wondering how to seperate the line, used Matt While's Day 4 as a platform for this


			if ( !temp.empty() )
			{
				full_passport_string = full_passport_string + temp + " ";
			}
			else
			{
				passport_array.push_back( parse_passports( full_passport_string ) );
			}
		}

		if ( !full_passport_string.empty() )
		{
			passport_array.push_back( parse_passports( full_passport_string ) );
		}
	}


	size_t passports_checked = 0;
	size_t part1_passports_valid = 0;
	size_t part2_passports_valid = 0;

	while ( passports_checked < passport_array.size() )
	{

		for ( auto Passport : passport_array )
		{
			++passports_checked;
			if ( !Passport.Year_of_Birth.empty() && !Passport.issue_year.empty() && !Passport.expiration_date.empty() && !Passport.eye_color.empty() && !Passport.hair_color.empty() && !Passport.height.empty() && !Passport.passport_id.empty() )
			{
				++part1_passports_valid;
			}

			if ( Passport.check_yob() && Passport.check_issue() && Passport.check_expiry() && Passport.check_height() && Passport.check_hair_colour() && Passport.check_eye_colour() && Passport.check_expiry() && Passport.check_passport_id() )
			{
				++part2_passports_valid;
			}
		}

	}


	std::cout << "Valid Passports: " << part1_passports_valid << std::endl;
	std::cout << "Valid Passports: " << part2_passports_valid << std::endl;
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
