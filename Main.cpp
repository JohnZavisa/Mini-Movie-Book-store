
/*
Programmer: John Zavisa
Description: This program implements polymorphism in order to allow traversal through list of movies and books
and also reads in the data originally from a given text file. The user can check out books and movies, return books and movies,
list them and inquire about them.
*/


#include <fstream>
#include <string>
#include <iostream>
#include "Movie.h"
#include <list>
#include <cassert>
#include <typeinfo>
#include "Book.h"
#include <algorithm>
using namespace std;

void Menu();		//Function prototype for displaying menu
bool compare(StoreItem*, StoreItem* ); //Function prototype for comparing and sorting

int main()
{
	//Open File
	ifstream myFile;
	myFile.open("inventory.txt");
	assert(myFile);

	//Create list container, iterator, store pointer, and string for storing user input. Also, create 
	//variables of type book and movie.
	list<StoreItem*> itemList;
	list<StoreItem*>::iterator x;
	StoreItem* storePtr;
	string input;
	Book book;
	Movie movie;
	string line;

	bool endFlag = false;		//This is a variable used for breaking from cerain loops under particular conditions.
	while (getline(myFile, line))	//This is a while loop for creating list of objects, both movies and books.
	{
		if (line[1] == 'B')
		{
			storePtr = book.createFromString(line);
			itemList.push_back(storePtr);
		}
		else
		{
			storePtr = movie.createFromString(line);
			itemList.push_back(storePtr);
			
		}
	}

	itemList.sort(compare); //Here, the list is sorted in one line.
	char choice;			//Create variable for storing the user's first input.
	Menu();					//Function call to menu() to display menu.
	cin >> choice;			//Store user input in choice variable.
	getline(cin, input);	
	while (choice != 'Q')		//This line says "While user hasn't entered Q as their choice, continue running program."
	{
		if (choice == 'M')		//If choice is M, prompt user to enter title for serching.
		{
			cout << "Enter the movie title: ";
			getline(cin, input);

			for (x = itemList.begin(); x != itemList.end(); x++)
			{
				endFlag = false;			//Variable for controlling breaks from loops.
				Movie* m = (Movie*)(*x);	//Create moovie pointer
				if (typeid(*(*x)) == typeid(movie))		//If the item type is a movie...
				{
					if (input == m->getTitle()) //If the title from user matches title from list iteration...
					{
						m->printItem();		//Print item in iteration.
						endFlag = true;		//Set endFlag to true and break.
						break;
					}
				}
			}
			if (endFlag == false)		//If endFlag was never set to true (movie was not found), print movie was not found
			{
				cout << "Cannot find the movie title " << input << endl;
			}
		}
		else if (choice == 'B')			//If user input is is B....
		{
			cout << "Enter the name of the author: ";		//Prompt the user for the name of the author for searching
			getline(cin, input);

			for (x = itemList.begin(); x != itemList.end(); ++x)	//Beginning checking through list.
			{
				endFlag = false;			//Set endFlag to false for beginning of loop.
				Book* b = (Book*)(*x);		// Create a book pointer variable.
				if (typeid(*(*x)) == typeid(book))		//If item in list's type is book...
				{
					string str1(b->getAuthor());	//Create string of author name

					string::size_type loc = str1.find(input, 0);	
					if (loc != string::npos)	
					{
						endFlag = true;
					}
					if (endFlag == true)	//If endFlag is set to true, print item in list
					{
						b->printItem();	
						break;
					}
						

				}
			}
			if (endFlag == false && (x == itemList.end()))		//If you reach end of list with endFlag never being set to false...
			{
				cout << "Cannot find a book by the author " << input << endl;		//Print cannot find a book by the author
			}
		}
		else if (choice == 'L')		//If user input is L, then print all items to the screen.
		{
			for (x = itemList.begin(); x != itemList.end(); x++)	//Iterate through list container and print each item and their data
			{
				(*x)->printItem();

			}
		}
		else if (choice == 'R')			//If user input is R ...
		{
			cout << "Enter the item barcode: ";		//Prompt user to enter barcode of Book or Movie to be returned to inventory of store
			getline(cin, input);
			
			for (x = itemList.begin(); x != itemList.end(); ++x)
			{
				endFlag = false;		//Begin loop by setting endFlag variable to false.
				Movie* m = (Movie*)(*x);	//Create pointer variables for movie and book.
				Book* b = (Book*)(*x);
				
				if(typeid(*(*x)) == typeid(movie))		//If item in list is of type movie...
				{
					if (input == m->getBarcode())		//If item in list's barcode matches user input barcode...
					{
						
						if (m->getCopy() >= 0)		   //If there are greater to or equal to 0 copies in inventory already
						{
							m->increaseCopy();		   //Increase copy by one.
							cout << "One more copy has been added to movie " << input << endl; //Print copy add confirmation.
							endFlag = true;				//Set endFlag to true and break.
							break;
						}
					}
					
				}
				else if (typeid(*(*x)) == typeid(book)) //If item in list is of type book...
				{
					if (input == b->getBarcode())		//If the item in list iteration's barcode matches user input barcode...
					{
						if (b->getCopy() >= 0)			//If inventor already has 0 or more copies
						{
							b->increaseCopy();			//Increase number of book copy data by one
							endFlag = true;				//Set endFlag to true
						}
					}
				}
			}
			if (endFlag == false)		//If endFlag was never set to true...
			{
				cout << "Cannot find item with barcode " << input << endl;	
			}
		}
		
		else if (choice == 'C')		//If user input is C...
		{
			cout << "Please enter a barcode: ";			//Prompt user to enter a barcode of item to be checked out
			getline(cin, input);
			for (x = itemList.begin(); x != itemList.end(); x++)
			{
				endFlag = false;				//Set endFlag equal to false
				Movie* m = (Movie*)(*x);		//Create movie and book pointer variables	
				Book* b = (Book*)(*x);
				if (typeid(*(*x)) == typeid(movie))			//If item in list is of type movie...
				{
					if (input == m->getBarcode())			//If item barcode in iteration matches barcode of input from user...
					{
						if (m->getCopy() > 0)				//If there is already one copy in inventory
						{
							m->decreaseCopy();				//Decrease copy by one.
							cout << "The movie " << input << " has been checked out successfully" << endl; //Confirmation print
							endFlag = true;				//Set endFlag to true and break.
							break;
						}
					}

				}
				else if (typeid(*(*x)) == typeid(book))		//If type in list is a book...
				{
					if (input == b->getBarcode())			//If barcode of object in list iteration matches barcode of user input...
					{
						if (b->getCopy() > 0)		//If there is atleast one copy in inventory laready
						{
							b->decreaseCopy();		//Decrease copy by one, print confirmation, set endFlag to true, and break.
							cout << "The book " << input << " has been checked out successfully" << endl;
							endFlag = true;
							break;
						}
					}
				}
			}
			if (endFlag == false)		//If endFlag was never set to true...
			{
				cout << "cannot find item with barcode " << input << endl;
			} 
			
			
			
		}
		system("pause"); //System pause
		system("CLS");  //Clear screen for restart menu
		Menu();			//Call Menu() again to display menu
		cin >> choice;	//Store new choice
		getline(cin, input);
		
	}
	
	return 0;
}

void Menu()	//This function displats the menu interface for user, and prompts user to enter command.
{
	cout << "			MiniMovie Store				" << endl;
	cout << "**************************************************" << endl;
	cout << "* Command Description				 *" << endl;
	cout << "* M		Inquire a movie by title	 *" << endl;
	cout << "* B		Inquire a book by author	 *" << endl;
	cout << "* L		List inventory			 *" << endl;
	cout << "* R		return one movie		 *" << endl;
	cout << "* C		Check out			 *" << endl;
	cout << "* Q		Quit to main menu		 *" << endl;
	cout << "**************************************************" << endl;

	cout << "Please enter your command <M, B, L, R, C, Q>: ";
	return;
}

bool compare(StoreItem* first, StoreItem* second)	//This is a compare function for using within the sort function.
{
	return (*first) < (*second);
}
