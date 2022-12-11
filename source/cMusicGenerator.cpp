#include "cMusicGenerator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

cMusicGenerator::cMusicGenerator()
{
	srand(time(NULL));
	next_uID = 10000;
}

cMusicGenerator::~cMusicGenerator()
{
}

bool cMusicGenerator::LoadMusicInformation(std::string musicFileName, std::string& errorString)
{
	std::ifstream song_file(musicFileName);
	if (!song_file.is_open())
	{
		errorString = "Cannot load file" + musicFileName;
		return false;
	}
	else
	{
		std::string line;
		unsigned int linecount = 0;
		while (std::getline(song_file, line))
		{
			if (linecount != 0) //skip header
			{
				std::stringstream ssLine(line);
				std::string token;
				unsigned int tokenCount = 0;
				cSong* newSong = new cSong();
				while (std::getline(ssLine, token, ','))
				{
					if (tokenCount == 3)
					{
						newSong->name = token;
					}
					if (tokenCount == 4)
					{
						newSong->artist = token;
						break;
					}
					tokenCount++;
				}
				newSong->setUniqueID(next_uID);
				next_uID += rand() % MAX_ID_INCREEMNT;

				songlink.insertEnd(*newSong);
				//songlist.insert(*newSong);
				delete newSong;
			}
			linecount++;
			//std::cout << linecount << std::endl;
		}
		song_file.close();
	}

    return true;
}

cSong* cMusicGenerator::getRandomSong(void)
{
	int randIndex = rand() % songlink.size();

	cSong* song = new cSong();
	myLink<cSong>::Node* node = songlink.getIndex(randIndex);
	song->name = node->data.name;
	song->artist = node->data.artist;

	return findSong(song->name,song->artist);
}

cSong* cMusicGenerator::findSong(std::string songName, std::string artist)
{
	int i = 0;
	while ((songlink.getIndex(i)->data.name != songName)&&(songlink.getIndex(i)->data.artist != artist))
	{
		i++;
	}

    return &songlink.getIndex(i)->data;
}


