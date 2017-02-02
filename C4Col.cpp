/*
Christopher Clarizio C4Col.cpp
implementation for the calss C4Col which abstracts a column in a connect four board
*/

#include <iostream>
#include <cstdlib>
#include "C4Col.h"

C4Col::C4Col()   //defualt constructor
{

	dis = new char[7];   //allocates memory for the array
	for( int i = 0; i < 6; i++ )   //iterates through the rows of the column
	{
		dis[i] = ' ';   //sets the character array's element at index i to ' '
	}
	numDis = 0;   //sets the number of discs currently in the column to 0
	maxDis = 6;   //sets the maximum number of discs that the column can store to 6

}
C4Col::~C4Col()
{

	delete[] dis;   //release memory allocated

}

int C4Col::isFull()   //returns an int signaling whether or not the column is full (0=false)
{

	int isFull = 1;   //assumes that the column is full

	for( int i = 0; i < 6; i++ )   //iterates through the rows of the column
	{
		if( getDisc(i) == ' ' )   //if any of the rows are empty (i.e. element contains ' ')
		{
			isFull = 0;   //sets the column to not full
			return isFull;   //returns that the column is not full
		}
	}

	return isFull;   //returns the value of isFull

}
char C4Col::getDisc( int index )   //returns the character in the index-th element of the column
{

	if( index>=0 && index<=5 )   //if the parameter is a valid index
	{
		return dis[index];   //returns the character in the column at that index
	}
	else   //otherwise
	{
		std::cout<<"INVALID INDEX"<<std::endl;   //displays an error message
	}

}
int C4Col::getMaxDiscs(){ return maxDis; }   //returns the maximum number of discs that the column can store
void C4Col::addDisc( char c )   //adds a disc to the column i.e. adds the character c to the next open row in the column
{

	int added = 0;   //assumes that disc has not been added

	for( int i = 0; i < 6; i++ )   //iterates through the rows of the column
	{
		if( getDisc(i) == ' ' )   //if a row is open (i.e. contains ' ')
		{
			dis[i] = c;   //that element of the arary is  set to c
			added = 1;   //added is set to true
			break;   //breaks out of the for loop
		}
	}

	if( added != 1 )   //if the disc has not been added after iterating through all the rows
	{
		std::cout<<"COLUMN FULL"<<std::endl;   //display an error message
	}

}
