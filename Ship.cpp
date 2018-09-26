/*************************************************************************************************************************
** Name:		Kevin Hwang
** Date:        June 7th, 2018
** Description: An implementation for a class called Ship that represents a game piece for playing Battleship. It has
**				the following member functions:
**				-A constructor that takes the ship's name and length as parameters and uses the information to initialize
**				the values. The damage is initialized to 0.
**				-Get methods for each data member.
**				-A method called takeHit that increments the ship's damage by 1.
*************************************************************************************************************************/
#include "Ship.hpp"
#include <string>

/*********************************************************************************
								Ship(int n, int len)
					
**Description: A constructor that takes the ship's name and length as parameters 
**			   and uses the information to initialize the values. The damage is 
**			   initialized to 0.
*********************************************************************************/
Ship::Ship(std::string n, int len)
{
	name = n;
	length = len;
	damage = 0;
}

/*********************************************************************************
									Get Methods
					
**Description: Get methods for each data member.
*********************************************************************************/
std::string Ship::getName()
{
	return name;
}

int Ship::getLength()
{
	return length;
}

int Ship::getDamage()
{
	return damage;
}

/*********************************************************************************
								takeHit()
					
**Description: A method called takeHit that increments the ship's damage by 1.
*********************************************************************************/
void Ship::takeHit()
{
	damage++;
}