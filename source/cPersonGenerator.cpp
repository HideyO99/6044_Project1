#include "cPersonGenerator.h"

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

#include <iostream>
#include <fstream>
#include <sstream>		// String Stream
#include <string>


cPersonGenerator::cPersonGenerator()
{
	name_file_line = 0;
	surname_file_line = 0;
	addr_file_line = 0;
	srand(time(NULL));
}

cPersonGenerator::~cPersonGenerator()
{
}

bool cPersonGenerator::LoadCensusFiles(
	std::string babyNameFile,
	std::string surnameFile,
	std::string streetNameFile,
	std::string& errorString)
{
	// TODO: Put YOUR amazing code here!
	std::ifstream name_file(babyNameFile);
	if (!name_file.is_open())
	{
		errorString = "Cannot load file" + babyNameFile;
		return false;
	}
	else
	{
		std::string line;
		while (std::getline(name_file, line))
		{
			nameData.insert(line.c_str());
			++name_file_line;
		}
		name_file.close();
	}

	std::ifstream surname_file(surnameFile);
	if (!surname_file.is_open())
	{
		errorString = "Cannot load file" + surnameFile;
		return false;
	}
	else
	{
		std::string line;
		while (std::getline(surname_file, line))
		{
			surnameData.insert(line.c_str());
			++surname_file_line;
		}
		surname_file.close();
		surname_file_line -= 2; //exclude header and footer
	}

	std::ifstream addr_file(streetNameFile);
	if (!addr_file.is_open())
	{
		errorString = "Cannot load file" + surnameFile;
		return false;
	}
	else
	{
		std::string line;
		while (std::getline(addr_file, line))
		{
			addrData.insert(line.c_str());
			++addr_file_line;
		}
		addr_file.close();
		addr_file_line -= 1; //exclude header
	}
	return true;
}

unsigned int cPersonGenerator::getNumberOfNamesLoaded(void)
{
	return name_file_line;
}

unsigned int cPersonGenerator::getNumberOfSurnamesLoaded(void)
{
	return surname_file_line;
}

unsigned int cPersonGenerator::getNumberOfStreetsLoaded(void)
{
	return addr_file_line;
}

cPerson* cPersonGenerator::generateRandomPerson(void)
{
	cPerson* newPerson = new cPerson();
	//First name
	std::string randName = nameData.find(rand()% name_file_line);
	newPerson->first = randName.substr(0,randName.find(','));

	//gender
	std::string gender = randName.substr(randName.find(',') + 1, 1);
	if (gender == "M" || gender == "m")
	{
		newPerson->gender = cPerson::MALE;
	}
	else if (gender == "F" || gender == "f")
	{
		newPerson->gender = cPerson::FEMALE;
	}
	else
	{
		newPerson->gender = cPerson::NON_BINARY;
	}

	//middle name
	randName = nameData.find(rand() % name_file_line);
	newPerson->middle = randName.substr(0, randName.find(','));

	//Last name
	randName = surnameData.find((rand() % surname_file_line)+1);
	newPerson->last = randName.substr(0, randName.find(','));

	//age
	newPerson->age = rand() % 100;

	//address
	std::string randAddr = addrData.find((rand() % addr_file_line) + 1); //discard the first column (full address)
	randAddr = randAddr.substr(randAddr.find(',')+1); 
	newPerson->streetName = randAddr.substr(0, randAddr.find(','));
	randAddr = randAddr.substr(randAddr.find(',') + 1);
	newPerson->streetType = randAddr.substr(0, randAddr.find(','));
	randAddr = randAddr.substr(randAddr.find(',') + 1);
	if (randAddr.find(',') != std::string::npos)
	{
		newPerson->streetDirection = randAddr.substr(0, randAddr.find(','));
	}
	newPerson->streetNumber = rand() % 1500;
	
	//post code
	
	//SIN
	return newPerson;
}


//
//// Here's a simple way to load the comma delimited files:
//bool readCSVFile(void)
//{
//	// Open the file
//	std::ifstream namesFile("Names_2010Census.csv");
//	if (!namesFile.is_open())
//	{
//		std::cout << "Didn't open file" << std::endl;
//		return false;
//	}
//
//	// name,rank,count,prop100k,cum_prop100k,pctwhite,pctblack,pctapi,pctaian,pct2prace,pcthispanic
//	// SMITH,1,2442977,828.19,828.19,70.9,23.11,0.5,0.89,2.19,2.4
//	//
//	// - rank is how popular the last name is, like 1st, 2nd, etc.
//	// - count is how many people have that last name, so 2,442,977 people have last name "Smith"
//	// - prop100k is the ratio per 100,000 people. Smith is 828.19, 
//	//            meaning that there's a 828.19 out of 100,000 chance (0.82819% chance)
//	//            that someone is named "Smith"
//
//	std::string theLine;
//
//	unsigned int lineCount = 0;
//	while (std::getline(namesFile, theLine))
//	{
//		lineCount++;
//		std::stringstream ssLine(theLine);
//
//		std::string token;
//		unsigned int tokenCount = 0;
//		while (std::getline(ssLine, token, ','))
//		{
//			if (tokenCount == 0)
//			{
//				std::cout << token << std::endl;
//			}
//			// Ignore the other parts of the line
//			tokenCount++;
//		}
//	}
//
//	std::cout << "Lines read = " << lineCount << std::endl;
//
//	return true;
//}
