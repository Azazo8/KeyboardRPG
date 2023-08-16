#pragma once

#include"CharacterCreator.h"

class Player
{
private:

	//Variables defining Player class
	std::string name;
	int strength;
	int endurance;
	int agility;
	int damage;
	int hp;
	int dodge;

public:

	//Setters
	void SetPlayer(CharacterCreator charcreator);
	void SetDamage();
	void ResetDodge();

	//Declared friendship
	friend class Game;
	friend class Fight;
};