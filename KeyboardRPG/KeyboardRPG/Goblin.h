#pragma once

#include<iostream>
#include<string>

class Goblin
{	
private:
	//Variables defining goblin class
	std::string name;
	short int strength;
	short int endurance;
	short int agility;
	short int hp;
	short int dodge;
	short int damage;

public:
	//Setters
	void Setgoblin();
	void Setdamage();
	void Resetgoblin();

	//Getters
	short int Gethp();

	//Declared friendships
	friend class Game;
	friend class Fight;
};