#include "Game.h"

//Setters
void Game::SetGameOver(short int value)
{
	GameOver = value;
}

//Getters
int Game::GetGameOver()
{
	return GameOver;
}

bool Game::GetFight()
{
	return fight;
}

//Drawing minimap
void Game::DrawMap()
{
	std::cout << "Minimap:";
	for (int i = 0; i < 8; ++i)
	{
		std::cout << '\n';
		for (int j = 0; j < 14; ++j)
			std::cout << map[i][j];
	}
	std::cout << "\n\n";
}

//Game screen setup
void Game::Setup(Player player, Goblin goblin)
{
	system("cls");
	std::cout << std::setw(w1) << "Choose your action.\n\n";
	std::cout << "************************************************************************************************************************\n";

	if (fight == false)
		std::cout << "1. Move forward" << std::setw(w2 + 5) << "2. Move Backwards" << std::setw(w2) << "3. Move left" << std::setw(w2) << "4. Move right" << std::setw(w2 + 10) << "5. Wait one instance\n";
	else
		std::cout << std::setw(w3 + 10) << "1. Attack" << std::setw(w2 + 5) << "2. Try to dodge" << std::setw(w2 + 10) << "3. Wait an instance\n";

	std::cout << "************************************************************************************************************************\n\n";
	DrawMap();
	std::cout << player.name << "'s paramaters:" << std::setw(w3) << goblin.name << "'s parameters:\n";
	std::cout << "HP: " << player.hp << std::setw(w3 - 4) << "HP: " << goblin.hp << '\n';
	std::cout << "-----------------------" << std::setw(w3) << "-----------------------\n";
	std::cout << "Strength: " << player.strength << std::setw(w3 - 3) << "Strength: " << goblin.strength << '\n';
	std::cout << "Endurance: " << player.endurance << std::setw(w3 - 2) << "Endurance: " << goblin.endurance << '\n';
	std::cout << "Agility: " << player.agility << std::setw(w3 - 2) << "Agility: " << goblin.agility << '\n';
	std::cout << "-----------------------" << std::setw(w3) << "-----------------------\n";
	std::cout << "What action do you choose: ";
}

//Game screen (no-fight) input
void Game::Input()
{
	std::cin >> choice;

	if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
	{
		std::cout << "There is no such option.\n";
		system("pause");
	}

	std::cin.clear();
	std::cin.ignore(100, '\n');
}

//Game screen (fight) input
void Game::FightInput(Player player, Goblin goblin)
{
	choice = 0;

	while (choice != 1 && choice != 2 && choice != 3)
	{
		std::cin >> choice;

		if (choice != 1 && choice != 2 && choice != 3)
		{
			std::cout << "There is no such option, give me a proper value.\n";
			std::cout << "What action do you choose: ";
		}

		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
}

//Options based on input (no-fight)
void Game::CheckInput(Player &player, Goblin goblin)
{
	switch (choice)
	{
	    case 1:
		{
			std::cout << "Walking...\n";
			Sleep(1500);

			if (map[x - 1][y] == '%')
			{
				--x;
				playerposition = map[x][y] = 'O';
				map[x + 1][y] = '%';
				std::cout << "Nothing special has happened you can go forth.\n";
			}
			else if (map[x - 1][y] == 'G')
			{
				fight = true;
				--x;
				playerposition = map[x][y] = 'O';
				map[x + 1][y] = '%';
				std::cout << "You encountered goblin. Prepare to fight!\n";
			}
			else
			{
				std::cout << "You cannot go there choose different direction.\n";
			}
			system("pause");
		} break;

		case 2:
		{
			std::cout << "Walking...\n";
			Sleep(1500);

			if (map[x + 1][y] == '%')
			{
				++x;
				playerposition = map[x][y] = 'O';
				map[x - 1][y] = '%';
				std::cout << "Nothing special has happened you can go forth.\n";
			}
			else if (map[x + 1][y] == 'G')
			{
				fight = true;
				++x;
				playerposition = map[x][y] = 'O';
				map[x - 1][y] = '%';
				std::cout << "You encountered goblin. Prepare to fight!\n";
			}
			else
			{
				std::cout << "You cannot go there choose different direction.\n";
			}
			system("pause");
		} break;

		case 3:
		{
			std::cout << "Walking...\n";
			Sleep(1500);

			if (map[x][y - 1] == '%')
			{
				--y;
				playerposition = map[x][y] = 'O';
				map[x][y + 1] = '%';
				std::cout << "Nothing special has happened you can go forth.\n";
			}
			else if (map[x][y - 1] == 'G')
			{
				fight = true;
				--y;
				playerposition = map[x][y] = 'O';
				map[x][y + 1] = '%';
				std::cout << "You encountered goblin. Prepare to fight!\n";
			}
			else
			{
				std::cout << "You cannot go there choose different direction.\n";
			}
			system("pause");
		} break;

		case 4:
		{
			std::cout << "Walking...\n";
			Sleep(1500);

			if (map[x][y + 1] == '%')
			{
				++y;
				playerposition = map[x][y] = 'O';
				map[x][y - 1] = '%';
				std::cout << "Nothing special has happened you can go forth.\n";
			}
			else if (map[x][y + 1] == 'G')
			{
				fight = true;
				++y;
				playerposition = map[x][y] = 'O';
				map[x][y - 1] = '%';
				std::cout << "You encountered goblin. Prepare to fight!\n";
			}
		    else if (map[x][y + 1] == 'F')
			{
				GameOver = 2;
			}
			else
			{
				std::cout << "You cannot go there choose different direction.\n";
			}
			system("pause");
		} break;

		case 5:
		{
			restore = 10;
			std::cout << "Recovering...\n";
			Sleep(1500);

			if (player.hp < player.endurance * 20)
			{
				if (player.hp > player.endurance * 20 - 10)
					restore = player.endurance * 20 - player.hp;
				player.hp += restore;
				std::cout << "You waited and recovered " << restore <<" HP.\n";
			}
			else
				std::cout << "You have already max HP, you can't recover anymore.\n";
			system("pause");
		} break;
	}
}

//Options based on input (fight)
void Game::FightCheckInput(Player &player, Goblin &goblin)
{
	switch (choice)
	{
	    case 1:
		{
			std::cout << "Attacking...\n";
			Sleep(1500);

			if ((rand() % 100 + 1) > 100 - goblin.dodge)
				std::cout << "Goblin dodged your attack.\n";
			else
			{
				std::cout << "You hit goblin and dealt " << player.damage << " damage\n";
				goblin.hp -= player.damage;
			}
		} break;

		case 2:
		{
			std::cout << "You prepare for goblin attack...\n";
			player.dodge += 25;
			Sleep(1500);
		} break;

		case 3:
		{
			restore = 10;
			std::cout << "Recovering...\n";
			Sleep(1500);

			if (player.hp < player.endurance * 20)
			{
				if (player.hp > player.endurance * 20 - 10)
					restore = player.endurance * 20 - player.hp;
				player.hp += restore;
				std::cout << "You waited and recovered " << restore <<" HP.\n";
			}
			else
				std::cout << "You have already max HP, you can't recover anymore.\n";
		} break;
	}
}

//Goblin turn
void Game::GoblinAttack(Player &player, Goblin goblin)
{
	std::cout << "\nGoblin is attacking...\n";
	Sleep(1500);

	if ((rand() % 100 + 1) > 100 - player.dodge)
		std::cout << "Goblin has missed\n";
	else
	{
		std::cout << "Goblin hits you and deals " << goblin.damage << " damage\n";
		player.hp -= goblin.damage;
	}
}

//Checking if player or enemy died
void Game::CheckIfFightEnds(Player player, Goblin &goblin)
{
	if (goblin.hp <= 0)
	{
		fight = false;
		std::cout << "Goblin has been defeated you can go forth.\n";
		goblin.ResetGoblin();
	}
	else if (player.hp <= 0)
	{
		GameOver = 1;
		fight = false;
		std::cout << "You have been defeated.\n";
	}
	system("pause");
}

//Resetting position after game loop breaks
void Game::ResetPosition()
{
	map[x][y] = '%';
	x = 6;
	y = 6;
	playerposition = map[x][y] = 'O';

	map[4][6] = 'G';
	map[3][4] = 'G';
	map[2][8] = 'G';
}