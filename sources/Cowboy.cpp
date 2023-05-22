#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
using namespace ariel;

namespace ariel
{
	Cowboy::Cowboy(const string& name , const Point& place) :Character(name , place , 110)
	{}
	

	bool Cowboy::hasboolets()
	{
		if (_bullets > 0)
		{
			return true;
		}
		
		return false;
	}

	void Cowboy::loosBullet()
	{
		_bullets--;
	}
	
	void Cowboy::attack(Character * enemy)
	{
		if(!isAlive() || enemy == nullptr || !enemy->isAlive() || this == enemy) 
		{
			throw runtime_error("Can't do this operation in cowboy");	
		}
		else if (_bullets > 0)
		{
			shoot(enemy);
			
		}
		else if (_bullets == 0)
		{
			reload();
		}
	}
	
	void Cowboy::shoot(Character* enemy)
	{
		if(!isAlive() || enemy == nullptr || !enemy->isAlive() || this == enemy) 
		{
			throw runtime_error("Can't do this operation in cowboy");	
		}
		else if (_bullets > 0)
		{
			enemy->hit(10);
			loosBullet();
			
		}

	}

	void Cowboy::reload()
	{

		if(isAlive()) {_bullets = 6;}
		else throw runtime_error("The cowboy is dead");
	}

	string Cowboy::print() 
	{
		string printstate = "C( " + getName() + " )\n";
        if (isAlive())
        {
            printstate += "live: " + to_string(isAlive()) + "\nHit: " + to_string(getHit()) + "\nLocation :" + " " + this->getLocation().print() + "\n";
        }
        else
        {
            printstate += "live: " + to_string(isAlive()) + "\nLocation :" + this->getLocation().print() + "\n";
        }

        cout << printstate; 

        return printstate;
	}
}
