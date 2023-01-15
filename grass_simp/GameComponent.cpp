#include "GameComponent.h" 
  
 
void GameComponent::Update() 
{ 
	for (GameComponent* obj : gameGbjects) 
	{ 
		obj->Update(); 
	} 
} 
 
void GameComponent::AddObject(GameComponent* obj)
{ 
 	gameGbjects.push_back(obj);
}

 
  
   
  
