
/*
* Author: Zhijiang Dong & John Zavisa
* Date: Jan 15, 2007
* File: Movie.h
* As a part of the 3110 assignment, this file
* defines a class Movie, which will be sold in
* a store
*/


/*
* No methods are provided to modify movie information.
* Movie information should be stable, whch means whenever
* you get a movie object, you are not supposed to
* change movie information such as title, and director.
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
	//The string info must be of the line format specificed in
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
