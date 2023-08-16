#pragma once

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>

class CharacterCreator
{
private:

	//Variables defining CharacterCreator class
	std::string name = "";
	short int strength = 5;
	short int endurance = 5;
	short int agility = 5;
	short int w1 = 77;
	short int w2 = 50;
	short int pointsRemaining = 10;
	char choice;

public:

	//Getters
	std::string Getname();

	//Methods
	void setup();
	void input();
	void managePoints();
	void summary();
	void reset();

	//Declared friendships
	friend class Player;
};