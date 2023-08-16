#pragma once

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>

class Menu
{
private:

	//Variables defining Menu class
	int w1 = 70;
	int w2 = 25;
	int choice = 0;

public:
	//Setters
	void SetChoice(short int value);

	//Getters
	int GetChoice();

	//Methods
	void Setup();
	void Input();
	void Options();
};