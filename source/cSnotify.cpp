#include "cSnotify.h"

void bubbleSort(cSong*& pLibraryArray, unsigned int& sizeOfLibary, bool byTitle);
void bubbleSort(cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray, std::string option);

cSnotify::cSnotify()
{
}

cSnotify::~cSnotify()
{
}

bool cSnotify::AddUser(cPerson* pPerson, std::string& errorString)
{
	myLink<cPerson>::Node* node = user.getHead();
	while (node != nullptr)
	{
		if (node->data.getSnotifyUniqueUserID() == pPerson->getSnotifyUniqueUserID())
		{
			errorString = "User already exist";
			return false;
		}
		node = node->next;
	}
	user.insertEnd(*pPerson);
	Library* ulib = new Library();
	ulib->uID = pPerson->getSnotifyUniqueUserID();
	library.insertEnd(*ulib);

	//if (user.size() != 0)
	//{
	//	for (int i = 0; i < user.size(); i++)
	//	{
	//		if (user.getIndex(i)->data.getSnotifyUniqueUserID() == pPerson->getSnotifyUniqueUserID())
	//		{
	//			errorString = "User already exist";
	//			return false;
	//		}
	//		if (user.getIndex(i)->data.getSnotifyUniqueUserID() < pPerson->getSnotifyUniqueUserID())
	//		{
	//			continue;
	//		}
	//		else
	//		{
	//			user.insertAfter(user.getIndex(i)->prev, *pPerson);
	//			Library* ulib = new Library();
	//			ulib->uID = pPerson->getSnotifyUniqueUserID();
	//			library.insertAfter(library.getIndex(i)->prev, *ulib);
	//			return true;
	//		}
	//	}
	//	user.insertEnd(*pPerson);
	//	Library* ulib = new Library();
	//	ulib->uID = pPerson->getSnotifyUniqueUserID();
	//	library.insertEnd( *ulib);
	//}
	//else
	//{
	//	user.insertEnd(*pPerson);
	//	Library* ulib = new Library();
	//	ulib->uID = pPerson->getSnotifyUniqueUserID();
	//	library.insertEnd( *ulib);
	//}

	return true;
}

bool cSnotify::UpdateUser(cPerson* pPerson, std::string& errorString)
{
	myLink<cPerson>::Node* node = user.getHead();
	while (node != nullptr)
	{
		if ((node->data.getSnotifyUniqueUserID() == pPerson->getSnotifyUniqueUserID()) && (node->data.SIN == pPerson->SIN))
		{
			node->data.first = pPerson->first;
			node->data.middle = pPerson->middle;
			node->data.last = pPerson->last;

			node->data.gender = pPerson->gender;
			node->data.age = pPerson->age;

			node->data.streetNumber = pPerson->streetNumber;
			node->data.streetName = pPerson->streetName;
			node->data.streetType = pPerson->streetType;
			node->data.streetDirection = pPerson->streetDirection;

			node->data.city = pPerson->city;
			node->data.province = pPerson->province;
			for (int j = 0; j < 6; j++)
			{
				node->data.postalCode[j] = pPerson->postalCode[j];
			}
			return true;
		}
		node = node->next;
	}
	//for (int i = 0; i < user.size(); i++)
	//{
	//	if ((user.getIndex(i)->data.getSnotifyUniqueUserID() == pPerson->getSnotifyUniqueUserID()) && (user.getIndex(i)->data.SIN == pPerson->SIN))
	//	{
	//		//(user.getIndex(i)->data) = *pPerson;
	//		user.getIndex(i)->data.first = pPerson->first;
	//		user.getIndex(i)->data.middle = pPerson->middle;
	//		user.getIndex(i)->data.last = pPerson->last;

	//		user.getIndex(i)->data.gender = pPerson->gender;
	//		user.getIndex(i)->data.age = pPerson->age;
	//		
	//		user.getIndex(i)->data.streetNumber = pPerson->streetNumber;
	//		user.getIndex(i)->data.streetName = pPerson->streetName;
	//		user.getIndex(i)->data.streetType = pPerson->streetType;
	//		user.getIndex(i)->data.streetDirection = pPerson->streetDirection;

	//		user.getIndex(i)->data.city = pPerson->city;
	//		user.getIndex(i)->data.province = pPerson->province;
	//		for (int j = 0; j < 6; j++)
	//		{
	//			user.getIndex(i)->data.postalCode[j] = pPerson->postalCode[j];
	//		}
	//		return true;
	//	}
	//}
	errorString = "Cannot find user, Cannot update";
	return false;
}

bool cSnotify::DeleteUser(unsigned int SnotifyUserID, std::string& errorString)
{
	myLink<cPerson>::Node* node = user.getHead();
	while (node != nullptr)
	{
		if (node->data.getSnotifyUniqueUserID() == SnotifyUserID)
		{
			user.deleteNode(node);
			myLink<Library>::Node* libNode = library.getHead();
			while (libNode != nullptr)
			{
				if (libNode->data.uID == SnotifyUserID)
				{
					library.deleteNode(libNode);
					break;
				}
				libNode = libNode->next;
			}
			return true;
		}
		node = node->next;
	}

	//for (int i = 0; i < user.size(); i++)
	//{
	//	if (user.getIndex(i)->data.getSnotifyUniqueUserID() == SnotifyUserID)
	//	{
	//		user.deleteNode(user.getIndex(i));
	//		return true;
	//	}
	//}
	errorString = "Cannot find SnotifyID";
	return false;
}

bool cSnotify::AddSong(cSong* pSong, std::string& errorString)
{
	myLink<cSong>::Node* node = song.getHead();
	while (node != nullptr)
	{
		if (node->data.getUniqueID() == pSong->getUniqueID())
		{
			errorString = "Song already exist";
			return false;
		}
		node = node->next;
	}
	song.insertEnd(*pSong);

	//if (song.size() != 0)
	//{
	//	for (int i = 0; i < song.size(); i++)
	//	{
	//		if (song.getIndex(i)->data.getUniqueID() == pSong->getUniqueID())
	//		{
	//			errorString = "Song already exist";
	//			return false;
	//		}
	//		if (song.getIndex(i)->data.getUniqueID() < pSong->getUniqueID())
	//		{
	//			continue;
	//		}
	//		else
	//		{
	//			song.insertAfter(song.getIndex(i)->prev, *pSong);
	//			return true;
	//		}
	//	}
	//	song.insertEnd(*pSong);
	//}
	//else
	//{
	//	song.insertEnd(*pSong);
	//}

	return true;
}

bool cSnotify::UpdateSong(cSong* pSong, std::string& errorString)
{
	myLink<cSong>::Node* node = song.getHead();
	while (node != nullptr)
	{
		if (node->data.getUniqueID() == pSong->getUniqueID())
		{
			node->data.artist;
			node->data.name = pSong->name;
			node->data.artist = pSong->artist;
			node->data.rating = pSong->rating;
			node->data.numberOfTimesPlayed = pSong->numberOfTimesPlayed;

			return true;
		}
		node = node->next;
	}
	errorString = "Cannot find song to update";
	return false;
}

bool cSnotify::DeleteSong(unsigned int UniqueSongID, std::string& errorString)
{
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr)
	{
		RemoveSongFromUserLibrary(UniqueSongID, node->data.uID, errorString);
		node = node->next;
	}
	myLink<cSong>::Node* songNode = song.getHead();
	while (songNode!=nullptr)
	{
		if (songNode->data.getUniqueID() == UniqueSongID)
		{
			song.deleteNode(songNode);
			return true;
		}
		songNode = songNode->next;
	}

	errorString = "Cannot find song to delete";
	return false;
}

bool cSnotify::AddSongToUserLibrary(unsigned int snotifyUserID, cSong* pNewSong, std::string& errorString)
{
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr)
	{
		if (node->data.uID == snotifyUserID)
		{
			myLink<cSong>::Node* songNode = node->data.song.getHead();
			while (songNode != nullptr)
			{
				if (songNode->data.getUniqueID() == pNewSong->getUniqueID())
				{
					errorString = "Already exist in the library";
					return false;
				}
				songNode = songNode->next;
			}
			node->data.song.insertEnd(*pNewSong);
			return true;
		}
		node = node->next;
	}

	errorString = "Cannot find user ID";
	return false;
}

bool cSnotify::RemoveSongFromUserLibrary(unsigned int snotifyUserID, unsigned int SnotifySongID, std::string& errorString)
{
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr)
	{
		if (node->data.uID == snotifyUserID)
		{
			myLink<cSong>::Node* songNode = node->data.song.getHead();
			while (songNode != nullptr)
			{
				if (songNode->data.getUniqueID() == SnotifySongID)
				{
					node->data.song.deleteNode(songNode);
					return true;
				}
				songNode = songNode->next;
			}
		}
		node = node->next;
	}

	errorString = "Cannot find user ID";
	return false;
}

bool cSnotify::UpdateRatingOnSong(unsigned int SnotifyUserID, unsigned int songUniqueID, unsigned int newRating)
{
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr) 
	{
		if (node->data.uID == SnotifyUserID)
		{
			myLink<cSong>::Node* songNode = node->data.song.getHead();
			while (songNode != nullptr)
			{
				if (songNode->data.getUniqueID() == songUniqueID)
				{
					songNode->data.rating = newRating;
					return true;
				}
				songNode = songNode->next;
			}
		}
		node = node->next;
	}
	return false;
}

cSong* cSnotify::GetSong(unsigned int SnotifyUserID, unsigned int songUniqueID, std::string& errorString)
{
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr)
	{
		if (node->data.uID == SnotifyUserID)
		{
			myLink<cSong>::Node* songNode = node->data.song.getHead();
			while (songNode != nullptr)
			{
				if (songNode->data.getUniqueID() == songUniqueID)
				{
					songNode->data.numberOfTimesPlayed++;
					return &songNode->data;
				}
				songNode = songNode->next;
			}
			errorString = "cannot find song in this user's library";
			return nullptr;
		}
		node = node->next;
	}
	errorString = "cannot find userID";
	return nullptr;
}

bool cSnotify::GetCurrentSongRating(unsigned int snotifyUserID, unsigned int songUniqueID, unsigned int& songRating)
{
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr)
	{
		if (node->data.uID == snotifyUserID)
		{
			myLink<cSong>::Node* songNode = node->data.song.getHead();
			while (songNode != nullptr)
			{
				if (songNode->data.getUniqueID() == songUniqueID)
				{
					songRating = songNode->data.rating;
					return true;
				}
				songNode = songNode->next;
			}
			return false;
		}
		node = node->next;
	}
	return false;
}

bool cSnotify::GetCurrentSongNumberOfPlays(unsigned int snotifyUserID, unsigned int songUniqueID, unsigned int& numberOfPlays)
{
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr)
	{
		if (node->data.uID == snotifyUserID)
		{
			myLink<cSong>::Node* songNode = node->data.song.getHead();
			while (songNode != nullptr)
			{
				if (songNode->data.getUniqueID() == songUniqueID)
				{
					numberOfPlays = songNode->data.numberOfTimesPlayed;
					return true;
				}
				songNode = songNode->next;
			}
			return false;
		}
		node = node->next;
	}
	return false;
}

cPerson* cSnotify::FindUserBySIN(unsigned int SIN)
{
	myLink<cPerson>::Node* node = user.getHead();
	while (node != nullptr)
	{
		if (node->data.SIN == SIN)
		{
			return &node->data;
		}
		node = node->next;
	}
	return nullptr;
}

cPerson* cSnotify::FindUserBySnotifyID(unsigned int SnotifyID)
{
	myLink<cPerson>::Node* node = user.getHead();
	while (node != nullptr)
	{
		if (node->data.getSnotifyUniqueUserID() == SnotifyID)
		{
			return &node->data;
		}
		node = node->next;
	}
	return nullptr;
}

//finding the song which already added into snotify. this fn is not search the whole song DB
cSong* cSnotify::FindSong(std::string title, std::string artist)
{
	myLink<cSong>::Node* node = song.getHead();
	while (node != nullptr)
	{
		if ((node->data.name.c_str() == title.c_str()) && node->data.artist.c_str() == artist.c_str())
		{
			return &node->data;
		}
		node = node->next;
	}
	return nullptr;
}

cSong* cSnotify::FindSong(unsigned int uniqueID)
{
	myLink<cSong>::Node* node = song.getHead();
	while (node != nullptr)
	{
		if (node->data.getUniqueID() == uniqueID)
		{
			return &node->data;
		}
		node = node->next;
	}
	return nullptr;
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
	myLink<Library>::Node* node = library.getHead();
	while (node != nullptr)
	{
		if (node->data.uID == snotifyUserID)
		{
			sizeOfLibary = node->data.song.size();
			pLibraryArray = new cSong[sizeOfLibary];
			for (int i = 0; i < sizeOfLibary; i++)
			{
				pLibraryArray[i] = node->data.song.getIndex(i)->data;
			}
			return true;
		}
		node = node->next;
	}

	return false;
}

bool cSnotify::GetUsersSongLibraryAscendingByTitle(unsigned int snotifyUserID, cSong*& pLibraryArray, unsigned int& sizeOfLibary)
{
	bool result = GetUsersSongLibrary(snotifyUserID, pLibraryArray, sizeOfLibary);
	if (result)
	{
		bubbleSort(pLibraryArray, sizeOfLibary, true);
		return true;
	}

	return false;
}

bool cSnotify::GetUsersSongLibraryAscendingByArtist(unsigned int snotifyUserID, cSong*& pLibraryArray, unsigned int& sizeOfLibary)
{
	bool result = GetUsersSongLibrary(snotifyUserID, pLibraryArray, sizeOfLibary);
	if (result)
	{
		bubbleSort(pLibraryArray, sizeOfLibary, false);
	}
	return false;
}

bool cSnotify::GetUsers(cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	//myLink<cPerson>::Node* node = user.getHead();
	sizeOfUserArray = user.size();
	pAllTheUsers = new cPerson[sizeOfUserArray];

	if (sizeOfUserArray > 0) 
	{
		for (int i = 0; i < sizeOfUserArray; i++)
		{
			pAllTheUsers[i] = user.getIndex(i)->data;
		}

		return true;
	}

	return false;
}

bool cSnotify::GetUsersByID(cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	bool result = GetUsers(pAllTheUsers, sizeOfUserArray);
	if (result)
	{
		bubbleSort(pAllTheUsers, sizeOfUserArray,"byID");
		return true;
	}
	return false;
}

bool cSnotify::FindUsersFirstName(std::string firstName, cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	myLink<cPerson>::Node* node = user.getHead();
	myLink<cPerson> foundUser;
	while (node != nullptr)
	{
		if (node->data.first == firstName)
		{
			foundUser.insertEnd(node->data);
		}
		node = node->next;
	}
	sizeOfUserArray = foundUser.size();
	if (sizeOfUserArray > 0)
	{
		pAllTheUsers = new cPerson[sizeOfUserArray];

		for (int i = 0; i < sizeOfUserArray; i++)
		{
			pAllTheUsers[i] = foundUser.getIndex(i)->data;
		}

		//sort
		bubbleSort(pAllTheUsers, sizeOfUserArray, "byFirstname");
		return true;
	}
	return false;
}

bool cSnotify::FindUsersLastName(std::string lastName, cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	myLink<cPerson>::Node* node = user.getHead();
	myLink<cPerson> foundUser;
	while (node != nullptr)
	{
		if (node->data.last == lastName)
		{
			foundUser.insertEnd(node->data);
		}
		node = node->next;
	}
	sizeOfUserArray = foundUser.size();
	if (sizeOfUserArray > 0)
	{
		pAllTheUsers = new cPerson[sizeOfUserArray];

		for (int i = 0; i < sizeOfUserArray; i++)
		{
			pAllTheUsers[i] = foundUser.getIndex(i)->data;
		}

		//sort
		bubbleSort(pAllTheUsers, sizeOfUserArray, "byLastname");
		return true;
	}
	return false;
}

bool cSnotify::FindUsersFirstLastNames(std::string firstName, std::string lastName, cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	myLink<cPerson>::Node* node = user.getHead();
	myLink<cPerson> foundUser;
	while (node != nullptr)
	{
		if ((node->data.first == firstName) && (node->data.last == lastName))
		{
			foundUser.insertEnd(node->data);
		}
		node = node->next;
	}
	sizeOfUserArray = foundUser.size();
	if (sizeOfUserArray > 0)
	{
		pAllTheUsers = new cPerson[sizeOfUserArray];

		for (int i = 0; i < sizeOfUserArray; i++)
		{
			pAllTheUsers[i] = foundUser.getIndex(i)->data;
		}

		//sort
		bubbleSort(pAllTheUsers, sizeOfUserArray, "byLastNFirst");
		return true;
	}
	return false;
}

void bubbleSort(cSong*& pLibraryArray, unsigned int& sizeOfLibary, bool byTitle)
{
	for (int i = 0; i < sizeOfLibary; i++)
	{
		for (int j = i + 1; j < sizeOfLibary; j++)
		{
			int cmpResult = 0;
			if (byTitle)
			{
				cmpResult = std::strcmp(pLibraryArray[j].name.c_str(), pLibraryArray[i].name.c_str());
			}
			else
			{
				cmpResult = std::strcmp(pLibraryArray[j].artist.c_str(), pLibraryArray[i].artist.c_str());
			}
			if (cmpResult < 0)
			{
				cSong tmp = pLibraryArray[i];
				pLibraryArray[i] = pLibraryArray[j];
				pLibraryArray[j] = tmp;
			}
		}
	}
}

void bubbleSort(cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray,std::string option)
{
	for (int i = 0; i < sizeOfUserArray; i++)
	{
		for (int j = i + 1; j < sizeOfUserArray; j++)
		{
			int cmpResult = 0;
			if (option == "byID")
			{
				cmpResult = (pAllTheUsers[j].getSnotifyUniqueUserID() < pAllTheUsers[j].getSnotifyUniqueUserID()) ? -1 : 1;
			}
			if (option == "byFirstname")
			{
				cmpResult = std::strcmp(pAllTheUsers[j].first.c_str(), pAllTheUsers[i].first.c_str());
			}
			if (option == "byLastname")
			{
				cmpResult = std::strcmp(pAllTheUsers[j].last.c_str(), pAllTheUsers[i].last.c_str());
			}
			if (option == "byLastNFirst")
			{
				cmpResult = std::strcmp(pAllTheUsers[j].last.c_str(), pAllTheUsers[i].last.c_str());
				if (cmpResult == 0)
				{
					cmpResult = std::strcmp(pAllTheUsers[j].first.c_str(), pAllTheUsers[i].first.c_str());
				}
			}

			if (cmpResult < 0)
			{
				cPerson tmp = pAllTheUsers[i];
				pAllTheUsers[i] = pAllTheUsers[j];
				pAllTheUsers[j] = tmp;
			}
		}
	}
}
