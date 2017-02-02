/*
Christopher Clarizio CSE 20312 1-31-2017 C4Board.cpp
implementation for the class C4Board which abstracts a board for connect four
*/

#include <iostream>
#include <cstdlib>
#include "C4Board.h"
#include "C4Col.h"

C4Board::C4Board()
{
	numCol = 7;   //sets the number of columns to 7
	cols = new C4Col[numCol];   //allocates memory for the array of columns
}
C4Board::~C4Board()
{
	delete[] cols;   //releases the memory allocated for the array of columns
}

void C4Board::display()   //displays the current state of the board
{

	for( int y = cols[0].getMaxDiscs()-1; y>=0; y-- )   //iterates through the rows of the board starting with the top row
	{
		std::cout<<"|";   //prints a separator at the beggining
		for( int x=0; x<numCol; x++ )   //iterates through the columns of the board starting with the left most
		{
			std::cout<<cols[x].getDisc(y)<<"|";   //prints the contents of a single place with a sperator
		}
		std::cout<<std::endl;   //prints a new line
	}
	for( int i = 1; i < 8; i++ )   //iterates throught the columns
	{
		std::cout<<" "<<i;   //prints out column labels
	}
	std::cout<<std::endl;   //prints a return

}
void C4Board::play()   //plays out a two player game of connect four
{

	int gameOver = 0;   //tracks whether the game has been won by either player
	int turn = 0;   //tracks the number of turns that have passed (hence start at 0)
	int colChoice;   //tracks the player's choice of which column to add a piece to

	while( gameOver != 1 )   //while the game has not been won by either player
	{
		display();   //display the board
		if( turn%2+1==1 )
		{
			std::cout<<"Player please enter the column to add your piece to:"<<std::endl;   //prompts the player
			std::cin>>colChoice;   //reads in their choice of column
			cols[colChoice-1].addDisc('X');   //adds an 'X' to the column that they chose
		}
		else
		{
			colChoice = rand()%6+1;   //primitive computer player that randomly chooses a column to place its piece
			cols[colChoice-1].addDisc('O');   //add an 'O' to the column that they chose
		}
		gameOver = isGameOver();   //checks whether the game is over
		turn++;   //increment the number of turns that have passed
	}
	display();   //displays the final board condition

}

int C4Board::isGameOver()
{

	if( check( 1, 1, 0, 0, 3, 2 ) == 1 ){ return 1; }   //checks NE/SW lines  12
	if( check( 1, -1, 0, 3, 3, 5 ) == 1 ){ return 1; }   //checks NW/SE lines  12
	if( check( 1, 0, 0, 0, 3, 5 ) == 1 ){ return 1; }   //checks E/W lines 18
	if( check( 0, 1, 0, 0, 6, 2 ) == 1 ){ return 1; }   //checks N/S lines 21

}

int C4Board::check( int dx, int dy, int x0, int y0, int x1, int y1 )
{

	char piece;   //stores teh value of the piece at the "origin"

	for( int x = x0; x <= x1; x++ )   //iterate through a 4x3 rectangle in the bottom left corner
	{
		for( int y = y0; y <= y1; y++ )
		{
			int count = 1;   //number of pieces of the same color in a row
			piece = cols[x].getDisc(y);   //piece at "origin"
			if( piece == 'X' || piece == 'O' )   //if the piece is a player's piece
			{
				for( int i = 1; i <= 3; i++ )   //check along a line 4 long
				{
					if( cols[x+i*dx].getDisc(y+i*dy) == piece )   //if a piece along the line is the same as the piece at he "origin"
					{
						count++;   //add one to the number of same pieces in a row
					}
					if( count >= 4 )   //if there are four or more pieces of the same type in a row
					{
						return 1;
					}
				}
			}
		}
	}

	return 0;

}
