#include "cPersonGenerator.h"
#include "cMusicGenerator.h"
#include "cSnotify.h"
#include <iostream>


#define NAME_FILE "data/Names/yob1984.txt"
#define LASTNAME_FILE "data/Surnames/Names_2010Census.csv"
#define ADDR_FILE "data/Street_Names/Street_Names.csv"
#define BILLBOARD "data/billboard/hot_stuff_2.csv"

void test() {
	std::string error;
	bool result;

	std::cout << "--------loading data-------" << std::endl;
	// Load Census files
	cPersonGenerator* personGen = new cPersonGenerator();
	result = personGen->LoadCensusFiles(NAME_FILE, LASTNAME_FILE, ADDR_FILE, error);
	if (!result)
	{
		std::cout << error << std::endl;
	}
	else
	{
		std::cout << "loading person data done." << std::endl;
	}
	error.clear();
	cMusicGenerator* musicGenerator = new cMusicGenerator();
	result = musicGenerator->LoadMusicInformation(BILLBOARD, error);
	if (!result) 
	{
		std::cout << error << std::endl;
	}
	else
	{
		std::cout<<"loading music done."<<std::endl;
	}

	cPerson* person = new cPerson[10];
	for (int i = 0; i < 10; i++) {
		person[i] = *personGen->generateRandomPerson();
		std::cout << "uID: "<< person[i].getSnotifyUniqueUserID() << " Name: " << person[i].first.c_str() << "-" << person[i].middle.c_str() << "-" << person[i].last.c_str()
			<<" gender: " << person[i].getGenderAsString().c_str() <<" sin: "<< person[i].SIN
			<< " addr: " << person[i].streetNumber <<" "<< person[i].streetName<<" "<< person[i].streetType<<" "<< person[i].streetDirection << std::endl;
	}

	std::cout <<std::endl<< "test findSong() : expect found song" << std::endl;
	// Find song.
	cSong* findSong;
	findSong = musicGenerator->findSong("Change The World", "Eric Clapton");
	if (findSong) {
		std::cout << "uID: " << findSong->getUniqueID() << " Name: " << findSong->name.c_str() << "-" << findSong->artist.c_str() << std::endl;
	}
	
	std::cout<< "test findSong done" << std::endl;

	cSong* song = new cSong[10];
	std::cout << std::endl << "test getRandomSong()" << std::endl;
	for (int i = 0; i < 10; i++) {
		song[i] = *musicGenerator->getRandomSong();
		std::cout << "uID: " << song[i].getUniqueID() << " Name: " << song[i].name.c_str() << "-" << song[i].artist.c_str() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "test snotify.AddUser()" << std::endl;
	
	cSnotify* snotify = new cSnotify();
	error.clear();
	for (size_t i = 0; i < 10; i++)
	{
		result = snotify->AddUser(&person[i], error);

		if (!result)
		{
			std::cout << error << std::endl;
		}
	}
	std::cout << "test snotify.AddUser() done" << std::endl;
	std::cout << std::endl;
	std::cout << "test snotify.AddUser() : same data expect fail" << std::endl;
	error.clear();
	// Try to add the same user again!
	result = snotify->AddUser(&person[4], error);
	if (!result) 
	{
		std::cout << error << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "test snotify.UpdateUser()" << std::endl;

	person[0].first = "yo";
	person[0].last = "yoyo";
	error.clear();
	result = snotify->UpdateUser(person, error);
	if (!result) {
		std::cout << error << std::endl;
	}
	else {
		std::cout << "update success" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "test snotify.DeleteUser()" << std::endl;
	error.clear();
	result = snotify->DeleteUser(person[1].getSnotifyUniqueUserID(), error);
	if (!result) {
		std::cout << error << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "test snotify.AddSong()" << std::endl;
	error.clear();
	for (size_t i = 0; i < 10; i++)
	{
		result = snotify->AddSong(&song[i], error);

		if (!result) {
			std::cout << error << std::endl;
		}
		else
		{
			std::cout << "add song success" << std::endl;
		}
	}
}

int main(int argc, char** argv) {
	test();
	return 0;
}