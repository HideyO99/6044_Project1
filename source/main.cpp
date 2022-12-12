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
	cPerson* person = new cPerson[10];
	for (int i = 0; i < 10; i++)
	{
		person[i] = *pPersonGen->generateRandomPerson();
		printf("UniqueUserID: %d, Gender: %s, Name: %s %s, SIN: %d, Street: %s\n",
			person[i].getSnotifyUniqueUserID(),
			person[i].getGenderAsString().c_str(),
			person[i].first.c_str(),
			person[i].last.c_str(),
			person[i].SIN,
			person[i].streetName.c_str());
	}
	//pPersonGen->generateRandomPerson();


	cMusicGenerator* pMusicGen = new cMusicGenerator();
	pMusicGen->LoadMusicInformation(BILLBOARD, error);
	cSong* song = new cSong[10];
	for (int i = 0; i < 10; i++)
	{
		song[i] = *pMusicGen->getRandomSong();
		printf("getUniqueID: %d, Name: %s, Artist: %s\n",
			song[i].getUniqueID(),
			song[i].name.c_str(),
			song[i].artist.c_str());
	}
	
	std::cout << error << std::endl;
}