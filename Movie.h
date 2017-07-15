
/*
* Author: John Zavisa
* 
* This file
* defines a class Movie, which will be sold in
* a store
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "StoreItem.h"

using namespace std;

class Movie : public StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	Movie(string title = "", string director = "",
		string barcode = "", double price = 0, int copy = 0, int demand = 0);

	string getTitle() const;

	string getDirector() const;

	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info is be of the line format specificed in
	//inventory.txt
	Movie* createFromString(const string info) override;

	//Print current item to the screen
	void printItem() override;
	~Movie() override;

private:
	string m_title;        // movie title
	string m_director;     // movie directors
};
#endif
