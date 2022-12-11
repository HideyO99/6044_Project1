#pragma once

#include "myLink.h"
#include "cSong.h"

class Library
{
public:
	Library();
	~Library();
	unsigned int uID;
	myLink<cSong> song;
};