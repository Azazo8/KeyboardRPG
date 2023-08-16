#pragma once

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>

class Menu
{
private:

	//Variables defining Menu class
	short int w1 = 70;
	short int w2 = 25;
	short int choice = 0;

public:
	//Setters
	void Setchoice(short int value);

	//Getters
	short int Getchoice();

	//Methods
	void setup();
	void input();
	void options();
};