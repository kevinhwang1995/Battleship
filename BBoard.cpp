/***************************************************************************************************************************
** Name:		Kevin Hwang
** Date:        June 7th, 2018
** Description: An implementation for a class called BBoard that represents a game board for playing Battleship. It has
**				the following member functions:
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
#include "Ship.hpp"
#include "BBoard.hpp"
#include <iostream>

/*********************************************************************************
									BBoard()
					
**Description: A constructor that initializes each element of the bool array to 
**			   false and each element of the Ship-pointer array to nullptr.
*********************************************************************************/
BBoard::BBoard()
{
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 10; col++)
		{
			attackedSquare[row][col] = false;														//Initializes entire bool array to false.
			shipLocation[row][col] = nullptr;														//Initializes entire Ship* array to nullptr.
		}
	}
	unsunkShips = 0;																				//Initializes unsunkShips to 0.
}

/*********************************************************************************
					getAttacksArrayElement(int row, int col)
					
**Description: A method called getAttacksArrayElement that takes a row and column 
**			   and returns the element at that position in the bool array.
*********************************************************************************/
bool BBoard::getAttacksArrayElement(int row, int col)
{
	return attackedSquare[row][col];
}

/*********************************************************************************
					getShipsArrayElement(int row, int col)
					
**Description: A method called getShipsArrayElement that takes a row and column 
**			   and returns the element at that position in the Ship-pointer array.
*********************************************************************************/
Ship* BBoard::getShipsArrayElement(int row, int col)
{
	return shipLocation[row][col];
}

/*********************************************************************************
							getNumShipsRemaining()
					
**Description: A method called getNumShipsRemaining that returns how many ships 
**			   are unsunk.
*********************************************************************************/
int BBoard::getNumShipsRemaining()
{
	return unsunkShips;
}

/*********************************************************************************
			placeShip(Ship* ship, int row, int col, char orient)
					
**Description: A method called placeShip that takes as parameters the address of 
**			   the Ship object, the row and column of the square of the Ship that 
**			   is closest to (0,0), and the Ship's orientation (R for row and C 
**			   for column). This method attempts to place a ship onto the board.
*********************************************************************************/
bool BBoard::placeShip(Ship* ship, int row, int col, char orient)
{
	if (orient == 'R')																				//If orientation is in the same row.
	{
		bool canBePlaced = true;
		
		for (int index = 0; index < ship->getLength(); index++)										//If the ship does not entirely fit on the board or any of
		{																							//the needed spaces are already taken, canBePlaced = false.
			if ((ship->getLength() + col - 1) > 9 || shipLocation[row][col + index] != nullptr)
			{
				canBePlaced = false;
				break;
			}
		}
		
		if (canBePlaced == false)																	//If canBePlaced = false, return false.
			return false;
		else																						//If canBePlaced = true, place the ship.
		{
			for (int index = 0; index < ship->getLength(); index++)
			{
				shipLocation[row][col + index] = ship;
			}
			
			unsunkShips++;																			//Increment number of unsunk ships.
			return true;																			//Return true.
		}
	}
	else																							//If orientation is in the same column.
	{
		bool canBePlaced = true;
		
		for (int index = 0; index < ship->getLength(); index++)										//If the ship does not entirely fit on the board or any of
		{																							//the needed spaces are already taken, canBePlaced = false.
			if ((ship->getLength() + row - 1) > 9 || shipLocation[row + index][col] != nullptr)
			{
				canBePlaced = false;
				break;
			}
		}
		
		if (canBePlaced == false)																	//If canBePlaced = false, return false.
			return false;
		else																						//If canBePlaced = true, place the ship.
		{
			for (int index = 0; index < ship->getLength(); index++)
			{
				shipLocation[row + index][col] = ship;
			}
			
			unsunkShips++;																			//Increment number of unsunk ships.
			return true;																			//Return true.
		}
	}
}

/*********************************************************************************
							attack(int row, int col)
					
**Description: A method called attack that takes as parameters the row and column 
**			   of the attack.
*********************************************************************************/
bool BBoard::attack(int row, int col)
{
	if (shipLocation[row][col] != nullptr)															//If the attack hits a ship.
	{
		if (attackedSquare[row][col] == false)														//If the square has never been attacked.
		{
			shipLocation[row][col]->takeHit();														//Increase damage on the ship.
			
			if (shipLocation[row][col]->getLength() == shipLocation[row][col]->getDamage())			//If each square of the ship has been hit.
			{
				std::cout << "They sank " << shipLocation[row][col]->getName() << "!" << std::endl; //Print message that ship has been sunk.
				unsunkShips--;																		//Decrement the number of ships left.
			}
			attackedSquare[row][col] = true;														//Change attackedSquare element to true.
		}
		return true;																				//Return true.
	}
	else																							//If the attack misses any ship.
	{
		attackedSquare[row][col] = true;															//Change attackedSquare element to true.
		return false;																				//Return false.
	}
}

/*********************************************************************************
								allShipsSunk()
					
**Description: A method called allShipsSunk that returns true if all ships on the
**			   board are sunk, and false if otherwise.
*********************************************************************************/
bool BBoard::allShipsSunk()
{
	if (unsunkShips == 0)																			//If unsunkShips is 0, return true.
		return true;
	else
		return false;																				//If unsunkShips is non-0, return false.
}
		