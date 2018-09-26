/***************************************************************************************************************************
** Name:		Kevin Hwang
** Date:        June 7th, 2018
** Description: A declaration for a class called BBoard that represents a game board for playing Battleship. It has
**				the following member variables:
**				-A 10x10 array of bools for keeping track of attacked squares.
**				-A 10x10 array of Ship-pointers for keeping track of ship locations.
**				-An int variable for keeping track of number of unsunk ships.
**				
**				The class has the following member functions:
**				-A constructor that initializes each element of the bool array to false and each element of the Ship-pointer
**				array to nullptr.
**				-A method called getAttacksArrayElement that takes a row and column and returns the element at that position
**				in the bool array.
**				-A method called getShipsArrayElement that takes a row and column and returns the element at that position
**				in the Ship-pointer array.
**				-A method called getNumShipsRemaining that returns how many ships are unsunk.
**				-A method called placeShip that takes as parameters the address of the Ship object, the row and column of
**				the square of the Ship that is closest to (0,0), and the Ship's orientation (R for row and C for column).
**				-A method called attack that takes as parameters the row and column of the attack.
**				-A method called allShipsSunk that returns true if all ships on the board are sunk, and false if otherwise.
***************************************************************************************************************************/
#ifndef BBOARD_HPP
#define BBOARD_HPP

#include "Ship.hpp"

class BBoard
{
	private:
		bool attackedSquare[10][10];
		Ship* shipLocation[10][10];
		int unsunkShips;
	public:
		BBoard();
		bool getAttacksArrayElement(int row, int col);
		Ship* getShipsArrayElement(int row, int col);
		int getNumShipsRemaining();
		bool placeShip(Ship* ship, int row, int col, char orient);
		bool attack(int row, int col);
		bool allShipsSunk();
};
#endif