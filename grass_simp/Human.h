#pragma once
#include "GlobalT.h"
#include "GameComponent.h"

class Human: public GameComponent
{
public:
	// Constructor											
	
	inline gl::vec2i get_pos() { return pos_person; }			
	inline void set_pos( gl::vec2i pos ) { pos_person = pos; }		
	// Other member functions...									
																	
protected:															
	int health, sleep;
	bool sex;
	float speed;									
	gl::vec2i pos_person;
			
								
protected:	
	virtual void move();
};

