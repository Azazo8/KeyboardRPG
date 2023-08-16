#pragma once
 
#include"Game.h"

class Fight
{
private:

	short int w1 = 70;
	short int w2 = 25;
	short int w3 = 40;

	short int choice;

public:

	void setup(Goblin goblin, Player player);
	void input();
};