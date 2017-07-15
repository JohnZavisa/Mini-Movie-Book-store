
/*
Programmer: John Zavisa
Assignment: Open Lab 4
Class: CSCI3110
Course Instructor: Dr. Dong
Due Date: 4:00AM, Monday, 3/20/17
Description: This program implements polymorphism in order to allow traversal through list of movies and books
and also reads in the data originally from a given text file. The user can check out books and movies, return books and movies,
list them and inquire about them.
*/

#include <string>
#include "StoreItem.h"
#include "Movie.h"
#include <sstream>
#include <fstream>
using namespace std;


//Definition of Movie constructor
Movie::Movie(string title, string director, string barcode,
	double price, int copy, int demand)
	: StoreItem(barcode, price, copy, demand), m_title(title), m_director(director)
{

}
//Definition of getTitle(), returns the title of movie object.
string Movie::getTitle() const
{	
	return m_title;
}
//Defition of getDirector(), returns the director of the movie object.
string Movie::getDirector() const
{
	return m_director;
}

//Definition of createFromString(), stores data of objects from file using stringstream.
Movie* Movie::createFromString(const string info)
{
	//Create variables for storing data from file.
	string title;
	string director;
	string tempTitle;
	string tempDirector;
	string tempBarcode;
	string trash;
	float tempPrice;
	int   tempCopy;
	int   tempDemand;

	//stringstream function call with 'info' passed as argument.
	stringstream ss(info);

	//Store info between the delimiters
	getline(ss, trash, DELIMITER);
	getline(ss, trash, DELIMITER);
	getline(ss, tempBarcode, DELIMITER);
	getline(ss, title, DELIMITER);
	getline(ss, director, DELIMITER);
	ss >> tempPrice;
	getline(ss, trash, DELIMITER);
	ss >> tempCopy;
	getline(ss, trash, DELIMITER);
	ss >> tempDemand;
	getline(ss, trash, DELIMITER);
	getline(ss, tempTitle, DELIMITER);
	Movie* moviePtr = new Movie(title, director, tempBarcode, tempPrice, tempCopy, tempDemand);
	
	//Return movie pointer
	return moviePtr;
}
//Function definition for printItem(), this formats and displays the book object.
void Movie::printItem()
{
	cout << "************ Movie with barcode " << m_barcode << "************" << endl;
	cout << "Title:     " << m_title << endl;
	cout << "Director:   " << m_director << endl;
	cout << "Price: " << m_price << endl;
	cout << "# of copy: " << m_copy << endl;
	cout << "# of demand: " << m_demand << endl;
}

Movie::~Movie()
{

}