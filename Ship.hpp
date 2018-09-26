/*************************************************************************************************************************
** Name:		Kevin Hwang
** Date:        June 7th, 2018
** Description: A declaration for a class called Ship that represents a game piece for playing Battleship. It has
**				the following member variables:
**				-A string variable holding the ship name.
**				-An int variable holding the ship's length.
**				-An int variable holding the damage of the ship.
**				
**				The class has the following member functions:
**				-A constructor that takes the ship's name and length as parameters and uses the information to initialize
**				the values. The damage is initialized to 0.
**				-Get methods for each data member.
**				-A method called takeHit that increments the ship's damage by 1.
*************************************************************************************************************************/
#ifndef SHIP_HPP
#define SHIP_HPP

#include <string>

class Ship
{
	private:
		std::string name;
		int length,
			damage;
			
	public:
		Ship(std::string n, int len);		
		std::string getName();
		int getLength();
		int getDamage();
		void takeHit();
};
#endif