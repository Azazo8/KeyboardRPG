#pragma once

#include<iostream>
#include<string>

class Goblin
{	
private:
	//Variables defining goblin class
	std::string name;
	int strength;
	int endurance;
	int agility;
	int hp;
	int dodge;
	int damage;

public:
	//Setters
	void SetGoblin();
	void SetDamage();
	void ResetGoblin();

	//Getters
	int GetHp();

	//Declared friendships
	friend class Game;
	friend class Fight;
};