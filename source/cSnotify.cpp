#include "cSnotify.h"


cSnotify::cSnotify()
{
}

cSnotify::~cSnotify()
{
}

bool cSnotify::AddUser(cPerson* pPerson, std::string& errorString)
{
	if (user.size() != 0)
	{
		for (int i = 0; i < user.size(); i++)
		{
			if (user.getIndex(i)->data.getSnotifyUniqueUserID() == pPerson->getSnotifyUniqueUserID())
			{
				errorString = "User already exist";
				return false;
			}
			if (user.getIndex(i)->data.getSnotifyUniqueUserID() < pPerson->getSnotifyUniqueUserID())
			{
				continue;
			}
			else
			{
				user.insertAfter(user.getIndex(i)->prev, *pPerson);
				return true;
			}
		}
		user.insertEnd(*pPerson);
	}
	else
	{
		user.insertEnd(*pPerson);
	}

	return true;
}

bool cSnotify::UpdateUser(cPerson* pPerson, std::string& errorString)
{
	for (int i = 0; i < user.size(); i++)
	{
		if ((user.getIndex(i)->data.getSnotifyUniqueUserID() == pPerson->getSnotifyUniqueUserID()) && (user.getIndex(i)->data.SIN == pPerson->SIN))
		{
			//(user.getIndex(i)->data) = *pPerson;
			user.getIndex(i)->data.first = pPerson->first;
			user.getIndex(i)->data.middle = pPerson->middle;
			user.getIndex(i)->data.last = pPerson->last;

			user.getIndex(i)->data.gender = pPerson->gender;
			user.getIndex(i)->data.age = pPerson->age;
			
			user.getIndex(i)->data.streetNumber = pPerson->streetNumber;
			user.getIndex(i)->data.streetName = pPerson->streetName;
			user.getIndex(i)->data.streetType = pPerson->streetType;
			user.getIndex(i)->data.streetDirection = pPerson->streetDirection;

			user.getIndex(i)->data.city = pPerson->city;
			user.getIndex(i)->data.province = pPerson->province;
			for (int j = 0; j < 6; j++)
			{
				user.getIndex(i)->data.postalCode[j] = pPerson->postalCode[j];
			}
			return true;
		}
	}
	errorString = "Cannot find user, Cannot update";
	return false;
}

bool cSnotify::DeleteUser(unsigned int SnotifyUserID, std::string& errorString)
{
	for (int i = 0; i < user.size(); i++)
	{
		if (user.getIndex(i)->data.getSnotifyUniqueUserID() == SnotifyUserID)
		{
			user.deleteNode(user.getIndex(i));
			return true;
		}
	}
	errorString = "Cannot find SnotifyID";
	return false;
}

bool cSnotify::AddSong(cSong* pSong, std::string& errorString)
{
	if (song.size() != 0)
	{
		for (int i = 0; i < song.size(); i++)
		{
			if (song.getIndex(i)->data.getUniqueID() == pSong->getUniqueID())
			{
				errorString = "Song already exist";
				return false;
			}
			if (song.getIndex(i)->data.getUniqueID() < pSong->getUniqueID())
			{
				continue;
			}
			else
			{
				song.insertAfter(song.getIndex(i)->prev, *pSong);
				return true;
			}
		}
		song.insertEnd(*pSong);
	}
	else
	{
		song.insertEnd(*pSong);
	}

	return true;
}

bool cSnotify::UpdateSong(cSong* pSong, std::string& errorString)
{
	for (int i = 0; i < song.size(); i++)
	{
		if (song.getIndex(i)->data.getUniqueID() == pSong->getUniqueID())
		{
			song.getIndex(i)->data.name = pSong->name;
			song.getIndex(i)->data.artist = pSong->artist;
			song.getIndex(i)->data.rating = pSong->rating;
			song.getIndex(i)->data.numberOfTimesPlayed = pSong->numberOfTimesPlayed;
			
			return true;
		}
	}
	errorString = "Cannot find song to update";
	return false;
}

// This returns a COPY of the users library, in the form of a regular dynamic array.
bool cSnotify::GetUsersSongLibrary(unsigned int snotifyUserID, cSong*& pLibraryArray, unsigned int& sizeOfLibary)
{
	// The caller would do something like this (assume the user ID = 28472382)
	//
	//	cSong* pTheSongs = 0;
	//	unsigned int arraySize = 0;
	//	GetUsersSongLibrary( 28472382, pTheSongs, arraySize );
	// 
	// Inside this method, you'd do something like this:

	// TODO: Find that user... 

	// Alloate a heap based array to hold all the songs...

//	sizeOfLibary = WhateverYouHaveToDoToGetThisValue();
//	pCopyOfLibrary = new cSong[sizeOfLibary];

	// The array and the size of the array are "returned" by reference to the caller. 

	// TODO: Copy all the songs over

	return true;
}

