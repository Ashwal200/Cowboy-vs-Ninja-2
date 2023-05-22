#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP
#include <stdio.h>
#include <string>
#include <vector>
#include "Team.hpp"
#include "Character.hpp"
using namespace std;

const int ten =  10;
namespace ariel{

    class  SmartTeam : public Team{
        public :
                  
                SmartTeam(Character * charac) : Team(charac){}
                        
		void add(Character * new_member) override
	    	{
			if (new_member != nullptr && getSize() < ten && new_member->isAlive() && !new_member->getPartOf() )
			{
		    	    setTeamMembers(new_member);
			    new_member->setPartOf(true);
			    
			}
			else
			{
			throw runtime_error("We have a issue with this operation");	
			}
	    	}


};


}
#endif
