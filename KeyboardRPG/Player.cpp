#include "Player.h"

//Setters
void Player::SetPlayer(CharacterCreator charcreator)
{
	name = charcreator.name;
	strength = charcreator.strength;
	endurance = charcreator.endurance;
	agility = charcreator.agility;
	hp = endurance * 20;
	dodge = agility * 3;
}

void Player::SetDamage()
{
	damage = (strength * 2 - 5) + (rand() % 9);
}

void Player::ResetDodge()
{
	dodge = agility * 3;
}