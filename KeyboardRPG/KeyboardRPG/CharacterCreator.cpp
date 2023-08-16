#include "CharacterCreator.h"

//Getters
std::string CharacterCreator::Getname()
{
	return name;
}

//Character creator display
void CharacterCreator::setup()
{
	std::cout << std::setw(w1) << "******************************\n";
	std::cout << std::setw(w1) << "*     Character creation     *\n";
	std::cout << std::setw(w1) << "******************************\n";
	std::cout << "\n\nApply remaining points to statistics: \n";
	std::cout << "(s = +1 to Strength / e = +1 to Endurance / a = +1 to Agility)\n";
	std::cout << "(S = -1 to Strength / E = -1 to Endurance / A = -1 to Agility)\n\n";
	std::cout << "1. Strength impacts your direct damage you will deal the enemy.\n";
	std::cout << "2. Endurance impacts your max health.\n";
	std::cout << "3. Agility impacts your chance to dodge the enemy attack.\n";
	std::cout << "\n\nStrength = " << strength << std::setw(w2) << "Endurance = " << endurance << std::setw(w2) << "Agility = " << agility << "\n";
	std::cout << "Points left: " << pointsRemaining << "\n\n\n";

	if (pointsRemaining > 0)
		std::cout << "What statistic do you want to modify? (s, e, a / S, E, A): ";

	if (pointsRemaining == 0)
		std::cout << "Enter your name: ";
}

//Character creator input
void CharacterCreator::input()
{
	if (pointsRemaining > 0)
	{
		std::cin >> choice;
		std::cin.ignore(100, '\n');

		if (choice != 's' && choice != 'e' && choice != 'a' && choice != 'S' && choice != 'E' && choice != 'A')
		{
			std::cout << "There is no such option.\n";
			system("pause");
		}
	}

	if (pointsRemaining == 0)
		std::cin >> name;
	system("cls");
}

//Managing points based on input
void CharacterCreator::managePoints()
{
	if (pointsRemaining > 0)
	{
		switch (choice)
		    {
		    case 's':
		    {
			    ++strength;
			    --pointsRemaining;
		    } break;

		    case 'e':
		    {
			    ++endurance;
			    --pointsRemaining;
		    } break;

		    case 'a':
		    {
			    ++agility;
			    --pointsRemaining;
		    } break;

		    case 'S':
		    {
			    --strength;
			    ++pointsRemaining;
		    } break;

		    case 'E':
		    {
		    	--endurance;
		    	++pointsRemaining;
		    } break;

		    case 'A':
		    {
			    --agility;
		     	++pointsRemaining;
		    } break;
		}
	}
}

//Displaying character summary
void CharacterCreator::summary()
{
	system("cls");

	std::cout << std::setw(w1) << "**************************\n";
	std::cout << std::setw(w1) << "*   Character creation   *\n";
	std::cout << std::setw(w1) << "**************************\n";
	std::cout << "Summary: \n\n";
	std::cout << "Character name: " << name << '\n';
	std::cout << "Strength: " << strength << '\n';
	std::cout << "Endurance: " << endurance << '\n';
	std::cout << "Agility: " << agility << "\n\n";

	std::cout << "Press any key to start the game...\n";
	_getch();
}

//Resseting character statistics after the game loop is finished
void CharacterCreator::reset()
{
	name = "";
	strength = 5;
	endurance = 5;
	agility = 5;
	choice = 'r';
	pointsRemaining = 10;
}