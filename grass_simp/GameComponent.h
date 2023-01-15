#pragma once
#include <iostream>
#include <vector>

class GameComponent
{
public:
	//GameComponent(std::string);
	virtual void AddObject(GameComponent*);
	virtual void Update();

private:
	std::vector<GameComponent*> gameGbjects;

};

