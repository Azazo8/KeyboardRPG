#include"Menu.h"
#include"Game.h"

int main()
{
	//Seed for random values
	srand(time(nullptr));

	//Creating objects
	Menu menu;
	CharacterCreator charcreator;
	Player player;
	Game game;
	Goblin goblin;

	//Loop repeating whole game process after success or defeat
	do
	{
		game.SetGameOver(0);
		//Loop controlling main menu
		while (menu.GetChoice() != 1 && menu.GetChoice() != 3)
		{
			menu.Setup();
			menu.Input();
			menu.Options();
		}

		//Loop controlling character creator
		while (charcreator.GetName().length() == 0)
		{
			charcreator.Setup();
			charcreator.Input();
			charcreator.ManagePoints();
		}

		//Summary and assigning stats to player
		charcreator.Summary();
		player.SetPlayer(charcreator);

		//Introduction to story
		system("cls");
		std::cout << "************************************************************************************************************************\n";
		std::cout << "Trapped inside a sinister dungeon, your heart races with fear and uncertainty. The heavy door slams shut, leaving you\n";
		std::cout << "with no choice but to find a way out. Armed with only your instincts and a glimmer of hope, you begin your\n";
		std::cout << "desperate quest for escape. The darkness surrounds you as you set forth, determined to overcome whatever obstacles\n"; 
		std::cout << "lie ahead.Your fight for freedom starts now.\n";
		std::cout << "************************************************************************************************************************\n\n";
		std::cout << "Press any key to start the game...\n";
		_getch();
		system("cls");

		//Loop controlling game flow
		goblin.ResetGoblin();
		while (game.GetGameOver() == 0)
		{
			game.Setup(player, goblin);
			game.Input();
			game.CheckInput(player, goblin);

			if (game.GetFight() == true)
			{
				//Loop controlling fight
				goblin.SetGoblin();
				while (goblin.GetHp() > 0)
				{
					player.SetDamage();
					player.ResetDodge();
					goblin.SetDamage();

					game.Setup(player, goblin);
					game.FightInput(player, goblin);
					game.FightCheckInput(player, goblin);
					game.CheckIfFightEnds(player, goblin);
					game.Setup(player, goblin);

					if (goblin.GetHp() <= 0)
						break;
					game.GoblinAttack(player, goblin);
					game.CheckIfFightEnds(player, goblin);

				}
			}
			system("cls");
		}

		//Winning condition
		if (game.GetGameOver() == 2)
		{
			system("cls");
			std::cout << "************************************************************************************************************************\n";
			std::cout << "With a final leap of courage, you break free from the dungeon's darkness. The sunlight greets you as you step into\n";
			std::cout << "freedom, victorious and ready for more adventures ahead.\n";
			std::cout << "************************************************************************************************************************\n\n";
			std::cout << "Press any key to go back to main menu...\n";
			_getch();
		}

		//Losing condition
		if (game.GetGameOver() == 1)
		{
			system("cls");
			std::cout << "************************************************************************************************************************\n";
			std::cout << "Lost and drained, you succumb to the dungeon's grasp, forever trapped in its dark embrace. No escape in sight, your fate\n";
			std::cout << "is sealed within its depths.\n";
			std::cout << "************************************************************************************************************************\n\n";
			std::cout << "Press any key to go back to main menu...\n";
			_getch();
		}

		//Reseting data after the game so we can start over
		game.ResetPosition();
		menu.SetChoice(0);
		charcreator.Reset();
		system("cls");

	} while (game.GetGameOver() == 1 || game.GetGameOver() == 2);

	return 0;
}