#include "Goblin.h"

//Setters
void Goblin::SetGoblin()
{
	name = "Malicious goblin";
	strength = 7;
	endurance = 6;
	agility = 7;
	hp = endurance * 20;
	dodge = agility * 3;
}

void Goblin::SetDamage()
{
	damage = (strength * 2 - 5) + (rand() % 9);
}

void Goblin::ResetGoblin()
{
	name = "Enemy";
	strength = 0;
	endurance = 0;
	agility = 0;
	hp = endurance * 20;
	dodge = agility * 3;
}

//Getters
int Goblin::GetHp()
{
	return hp;
}