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
	int strength = 5;
	int endurance = 5;
	int agility = 5;
	int w1 = 77;
	int w2 = 50;
	int pointsRemaining = 10;
	char choice;

public:

	//Getters
	std::string const GetName();

	//Methods
	void Setup();
	void Input();
	void ManagePoints();
	void Summary();
	void Reset();

	//Declared friendships
	friend class Player;
};