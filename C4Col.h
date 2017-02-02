/*
Christopher Clarizio CSE 20312 1-25-2017 C4Col.h
header for the C4Col class which abstracts a column in a connect four board
*/

#ifndef C4COL_H
#define C4COL_H

class C4Col
{
	public:
		C4Col();   //default constructor
		~C4Col();   //destructor
		int isFull();   //determines if the column is full
		char getDisc(int);   //returns the requested element of the pricate character array
		int getMaxDiscs();   //returns the maximum number of discs
		void addDisc(char);   //adds the character representing a disc to the next open slot
	private:
		int numDis;   //number of discs in the column
		int maxDis;   //maximum number of discs allowed
		char* dis;   //character array storing discs
};

#endif
