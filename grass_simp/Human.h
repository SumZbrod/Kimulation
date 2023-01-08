#ifndef HUMAN_H
#define HUMAN_H
#include "GlobalT.h"


class Human
{
public:
	// Constructor
	Human( gl::vec2i );
	inline gl::vec2i get_pos() { return pos_person; }
	inline void set_pos( gl::vec2i pos ) { pos_person = pos; }
	// Other member functions...

protected:
	// ��������� ������� ����� � ����
	int health, sleep;
	bool sex;
	float speed;
	gl::vec2i pos_person;


protected:
	//����� ������� ������� ����� ���������� �� ������ � ������(��� ���)
	virtual void move();
	virtual bool take( gl::vec2i );


};

#endif // HUMAN_H