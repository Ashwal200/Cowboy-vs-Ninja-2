#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel
{
    
	Ninja::Ninja(const string& name , const Point& place ,int hpl, int speed) : Character(name, place , hpl)
	{
		_speed = speed;
	}

	int Ninja::getSpeed()
	{
		return _speed;
	}

	void Ninja::slash(Character* enemy)
	{
		if(!isAlive() || enemy == nullptr || !enemy->isAlive() || this == enemy) 
		{
			throw runtime_error("Can't do this operation in ninja");	
		}
		if (this->distance(enemy) <= 1.0)
		{
			enemy->hit(40);
		}
		
	}
	
	void Ninja::attack(Character* enemy)
	{
		if(!isAlive() || enemy == nullptr || !enemy->isAlive() || this == enemy) 
		{
			throw runtime_error("Can't do this operation in ninja attack");	
		}
		if (this->distance(enemy) <= 1.0)
		{
			slash(enemy);
			
		}
		else if (this->distance(enemy) > 1.0)
		{
			move(enemy);
		}
	}

	string Ninja::print() 
	{
		string printstate = "N( " + getName() + " )\n";
        if (isAlive())
        {
            printstate += "live: " + to_string(isAlive()) +  "\nHit: " + to_string(getHit()) + "\nLocation :" + " " + this->getLocation().print() + "\n";
        }
        else
        {
            printstate += "live: " + to_string(isAlive()) + "\nLocation :" + this->getLocation().print() + "\n";
        }

        cout << printstate;

        return printstate;
	
	}

	void Ninja::move(Character * enemy)
	{
		if(!isAlive() || enemy == nullptr || !enemy->isAlive() || this == enemy) 
		{
			throw runtime_error("Can't do this operation");	
		}
		setLocation(Point::moveTowards(this->getLocation() , enemy->getLocation() , this->getSpeed()));
	}

}
