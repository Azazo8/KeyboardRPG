#pragma once

#include"CharacterCreator.h"

class Player
{
private:

	//Variables defining Player class
	std::string name;
	short int strength;
	short int endurance;
	short int agility;
	short int damage;
	short int hp;
	short int dodge;

public:

	//Setters
	void Setplayer(CharacterCreator charcreator);
	void Setdamage();
	void Resetdodge();

	//Declared friendship
	friend class Game;
	friend class Fight;
};