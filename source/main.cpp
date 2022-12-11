#include "cPersonGenerator.h"
#include "cMusicGenerator.h"
#include <iostream>


#define NAME_FILE "data/Names/yob1984.txt"
#define LASTNAME_FILE "data/Surnames/Names_2010Census.csv"
#define ADDR_FILE "data/Street_Names/Street_Names.csv"
#define BILLBOARD "data/billboard/hot_stuff_2.csv"

void main()
{
	cPersonGenerator* pPersonGen = new cPersonGenerator();
	std::string error;
	pPersonGen->LoadCensusFiles(NAME_FILE, LASTNAME_FILE, ADDR_FILE, error);
	pPersonGen->generateRandomPerson();
	cMusicGenerator* pMusicGen = new cMusicGenerator();
	pMusicGen->LoadMusicInformation(BILLBOARD, error);
	pMusicGen->getRandomSong();
	std::cout << error << std::endl;
}