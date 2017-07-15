
/*
Programmer: John Zavisa
Description: This program implements polymorphism in order to allow traversal through list of movies and books
and also reads in the data originally from a given text file. The user can check out books and movies, return books and movies,
list them and inquire about them.
*/

#include "Book.h"
#include <string>
#include "StoreItem.h"
#include "Movie.h"
#include <sstream>
#include <fstream>
using namespace std;

//Definition of book object constructor.
Book::Book(string title, string author, string barcode, string date,
	double price, int copy, int demand)
	: StoreItem(barcode, price, copy, demand), m_title(title), m_author(author), m_date(date)
{

}
//Definition of getTitle(), returns title of book object.
string Book::getTitle() const
{
	return m_title;
}
//Definition of getAuthor(), returns author of book object.
string Book::getAuthor() const 
{
	return m_author;
}

//Definition of createFromString, reads in data with stringstream from file, and stores data.
Book* Book::createFromString(const string info)
{	
	//Create variables for storing data from file
	string title;
	string author;
	string tempTitle;
	string tempAuthor;
	string tempBarcode;
	string trash;
	string date;
	float tempPrice;
	int   tempCopy;
	int   tempDemand;
	
	//string stream function call with constant string 'info' as argument.
	stringstream ss(info);

	//Store info between the delimiters.
	getline(ss, trash, DELIMITER);
	getline(ss, trash, DELIMITER);
	getline(ss, tempBarcode, DELIMITER);
	getline(ss, title, DELIMITER);
	getline(ss, author, DELIMITER);
	getline(ss, date, DELIMITER);
	ss >> tempPrice;
	getline(ss, trash, DELIMITER);
	ss >> tempCopy;
	getline(ss, trash, DELIMITER);
	ss >> tempDemand;
	getline(ss, trash, DELIMITER);
	getline(ss, tempTitle, DELIMITER);

	Book* bookPtr = new Book(title, author, tempBarcode, date, tempPrice, tempCopy, tempDemand);

	return bookPtr;

}
//Definition of printItem(), this is the formatted display print screen for book objects in the list.
void Book::printItem()
{
	cout << "************ Book with barcode " << m_barcode << "************" << endl;
	cout << "Title:     " << m_title << endl;
	cout << "Author:   " << m_author << endl;
	cout << "Publish Date: " << m_date << endl;
	cout << "Price: " << m_price << endl;
	cout << "# of copy: " << m_copy << endl;
	cout << "# of demand" << m_demand << endl;
}

Book::~Book()
{

}
