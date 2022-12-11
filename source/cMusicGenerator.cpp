#include "cMusicGenerator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

cMusicGenerator::cMusicGenerator()
{
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
				if (songlist.size() == 0)
				{
					songlist.insertFront(*newSong);
				}
				else
				{
					int cmpResult = std::strcmp(songlist.getTail()->data.name.c_str(), newSong->name.c_str());
					if (cmpResult < 0)
					{
						songlist.insertEnd(*newSong);
					}
					if (cmpResult == 0)
					{

					}
					if (cmpResult > 0)
					{
						
					}
				}
				songlist.insertEnd(*newSong);
				delete newSong;
			}
			linecount++;
		}
		song_file.close();
	}

    return false;
}

cSong* cMusicGenerator::getRandomSong(void)
{
    return nullptr;
}

cSong* cMusicGenerator::findSong(std::string songName, std::string artist)
{
    return nullptr;
}
