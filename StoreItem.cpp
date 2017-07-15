
/*
Programmer: John Zavisa
Description: This program implements polymorphism in order to allow traversal through list of movies and books
and also reads in the data originally from a given text file. The user can check out books and movies, return books and movies,
list them and inquire about them.
*/

#include <string>
#include <iostream>
#include "StoreItem.h"
using namespace std;

//This is the definition for the default constructor
StoreItem::StoreItem(string barcode, double price, int copy, int demand)
	: m_barcode(barcode), m_price(price), m_copy(copy), m_demand(demand)
{

}
//Function 'getter' for accessing object barcode
string StoreItem::getBarcode() const
{
	return m_barcode;
}
//Function 'getter' for accessing object price
double StoreItem::getPrice() const
{
	return m_price;
}
//Function 'getter' for accessing object copy
int StoreItem::getCopy() const
{
	return m_copy;
}
//Function 'getter' for accessing object demand
int StoreItem::getDemand() const
{
	return m_demand;
}
//Function for increasing the copy data of object
void StoreItem::increaseCopy()
{
	if (m_copy >= 0)
	{
		m_copy++;
	}
}
//Function for decreasing the copy data of object.
void StoreItem::decreaseCopy()
{
	if (m_copy > 0)
	{
		m_copy--;
	}
}
//Function for increasing demand data of the object
void StoreItem::increaseDemand()
{
	if (m_copy == 0)
	{
		m_demand++;
	}
}
//Function for decreasing demand data of object
void StoreItem::decreaseDemand()
{
	if (m_copy > 0)
	{
		m_demand--;
	}
}
//Overloaded comparison == operator for finding object of barcode
bool StoreItem::operator == (const StoreItem& rhs) const
{
	if (m_barcode == rhs.m_barcode)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Overloaded less-than operator for comparing barcodes
bool StoreItem::operator < (const StoreItem& rhs) const
{
	if (m_barcode < rhs.m_barcode)
	{
		return true;
	}
	else
	{
		return false;
	}
}


