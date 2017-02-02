/*
Christopher Clarizio CSE 20312 1-31-2017 C4Board.h
header for the C4Board class which abstracts a board for connect four
*/

#ifndef C4BOARD_H
#define C4BOARD_H

#include "C4Col.h"

class C4Board
{
	public:
		C4Board();   //defauilt constructor
		~C4Board();   //default deconstructor
		void display();   //displays the board via use of text and isotream
		void play();   //plays a two player game of connect four
		int isGameOver();   //returns whether the game is over
		int check( int, int, int, int, int, int );   //checks along a line in a certain direction
	private:
		int numCol;   //the number of columns in the board
		C4Col* cols;   //array of C4Cols 
};

#endif
