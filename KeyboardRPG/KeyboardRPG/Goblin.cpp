#include "Goblin.h"

//Setters
void Goblin::Setgoblin()
{
	name = "Malicious goblin";
	strength = 7;
	endurance = 6;
	agility = 7;
	hp = endurance * 20;
	dodge = agility * 3;
}

void Goblin::Setdamage()
{
	damage = (strength * 2 - 5) + (rand() % 9);
}

void Goblin::Resetgoblin()
{
	name = "Enemy";
	strength = 0;
	endurance = 0;
	agility = 0;
	hp = endurance * 20;
	dodge = agility * 3;
}

//Getters
short int Goblin::Gethp()
{
	return hp;
}