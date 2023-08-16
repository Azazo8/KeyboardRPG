#include "Fight.h"

void Fight::setup(Goblin goblin, Player player)
{
	system("cls");
	std::cout << std::setw(w1) << "Choose your action.\n\n";
	std::cout << "************************************************************************************************************************\n";
	std::cout << std::setw(w3) << "1. Attack" << std::setw(w2) << "2. Try to dodge" << std::setw(w2 + 5) << "3. Wait an instance\n";
	std::cout << "************************************************************************************************************************\n\n";
	std::cout << player.name << "'s paramaters:" << std::setw(w3) << goblin.name << "'s parameters:\n";
	std::cout << "HP: " << player.hp << std::setw(w3 - 4) << "HP: " << goblin.hp << '\n';
	std::cout << "-----------------------" << std::setw(w3) << "-----------------------\n";
	std::cout << "Strength: " << player.strength << std::setw(w3 - 3) << "Strength: " << goblin.strength << '\n';
	std::cout << "Endurance: " << player.endurance << std::setw(w3 - 2) << "Endurance: " << goblin.endurance << '\n';
	std::cout << "Agility: " << player.agility << std::setw(w3 - 2) << "Agility: " << goblin.agility << '\n';
	std::cout << "-----------------------" << std::setw(w3) << "-----------------------\n";
	std::cout << "What action do you choose: ";
}

void Fight::input()
{
	std::cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3)
	{
		std::cout << "There is no such option.\n";
		system("pause");
	}
	std::cin.clear();
	std::cin.ignore(100, '\n');
}