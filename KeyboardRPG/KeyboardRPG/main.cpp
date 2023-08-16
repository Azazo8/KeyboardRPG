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
		while (menu.Getchoice() < 1 || menu.Getchoice() > 3 || menu.Getchoice() == 2)
		{
			menu.setup();
			menu.input();
			menu.options();
		}

		//Loop controlling character creator
		while (charcreator.Getname().length() == 0)
		{
			charcreator.setup();
			charcreator.input();
			charcreator.managePoints();
		}

		//Summary and assigning stats to player
		charcreator.summary();
		player.Setplayer(charcreator);

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
		goblin.Resetgoblin();
		while (game.GetGameOver() == 0)
		{
			game.setup(player, goblin);
			game.input();
			game.checkinput(player, goblin);

			if (game.Getfight() == true)
			{
				//Loop controlling fight
				goblin.Setgoblin();
				while (goblin.Gethp() > 0)
				{
					player.Setdamage();
					player.Resetdodge();
					goblin.Setdamage();

					game.setup(player, goblin);
					game.fightinput(player, goblin);
					game.fightcheckinput(player, goblin);
					game.chechififghtends(player, goblin);
					game.setup(player, goblin);

					if (goblin.Gethp() <= 0)
						break;
					game.goblinattack(player, goblin);
					game.chechififghtends(player, goblin);

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
		game.resetposition();
		menu.Setchoice(0);
		charcreator.reset();
		system("cls");

	} while (game.GetGameOver() == 1 || game.GetGameOver() == 2);

	return 0;
}