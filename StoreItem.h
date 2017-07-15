
/*
Programmer: John Zavisa & Dr. Dong
Assignment: Open Lab 4
Class: CSCI3110
Course Instructor: Dr. Dong
Due Date: 4:00AM, Monday, 3/20/17
Description: This program implements polymorphism in order to allow traversal through list of movies and books
and also reads in the data originally from a given text file. The user can check out books and movies, return books and movies,
list them and inquire about them.
*/

#ifndef STOREITEM_H
#define STOREITEM_H

#include <string>
#include <iostream>

using namespace std;

// assume the delimiter never appears in the book information
const char DELIMITER = '|';

class StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	StoreItem(string barcode = "", double price = 0, int copy = 0, int demand = 0);

	//for debug purpose
	virtual ~StoreItem()
	{
		//cout << "Destructor called" << endl;
	}

	//Get movie title
	string getBarcode() const;

	//Get price
	double getPrice() const;

	//Get number of copies in the store
	int getCopy() const;

	//Get number of copies to be ordered
	int getDemand() const;

	//Increase # of copies by 1
	//precondition: m_copy >= 0
	void increaseCopy();

	//Decrease # of copies by 1
	//precondition: m_copy > 0
	void decreaseCopy();

	//Increase # of copies to be ordered by 1
	//precondition: m_copy == 0
	void increaseDemand();

	//Decrease # of copies to be ordered by 1
	//precondition: m_demand > 0
	void decreaseDemand();

	//Compare two store items. Return true if they have the same barcode,
	//otherwise false.
	bool operator == (const StoreItem& rhs) const;

	//Compare two store items by barcode
	bool operator < (const StoreItem& rhs) const;

	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info must be of the line format specificed in
	//inventory.txt
	virtual StoreItem* createFromString(const string info) = 0;

	//Print current item to the screen
	virtual void printItem() = 0;

protected:
	string m_barcode;  // barcode
	float       m_price;    //the retail price of the item
	int         m_copy;     //# of copies available in the store.
	int         m_demand;   //# of copies to be ordered.
};
#endif