#include "cPersonGenerator.h"

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

#include <iostream>
#include <fstream>
#include <sstream>		// String Stream
#include <string>

int genSin();

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
	if ((rand() % 3) == 1)
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
	
	//city
	// province
	//post code
	
	//SIN
	newPerson->SIN = genSin();

	return newPerson;
}


int genSin()
{
	int g1, g2, g3;
	g1 = (rand() % 1000)*1000*1000;
	g2 = (rand() % 1000) * 1000;
	g3 = rand() % 1000;

	return g1+g2+g3;
}
