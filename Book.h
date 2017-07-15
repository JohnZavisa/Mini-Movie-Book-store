
/*
Programmer: John Zavisa
Description: This program implements polymorphism in order to allow traversal through list of movies and books
and also reads in the data originally from a given text file. The user can check out books and movies, return books and movies,
list them and inquire about them.
*/

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "StoreItem.h"

using namespace std;

class Book : public StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	Book(string title = "", string author = "",
		string barcode = "", string date = "", double price = 0, int copy = 0, int demand = 0);

	string getTitle() const;

	string getAuthor() const;

	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info is of the line format specificed in
	//inventory.txt
	Book* createFromString(const string info) override;

	//Print current item to the screen
	void printItem() override;

	Book::~Book() override;

private:
	string m_title;        // movie title
	string m_author;     // movie directors
	string m_date;
};
#endif
