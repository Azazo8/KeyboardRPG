#pragma once

#include"Player.h"
#include"Goblin.h"
#include<windows.h>
#include<ctime>

class Game
{
private:

	//Game map
	char map[8][14]
	{
		{"#############"},
		{"#           #"},
		{"#       %%%F#"},
		{"#   %   %   #"},
		{"#   %%%%%   #"},
		{"#     %     #"},
		{"#     %     #"},
		{"#############"}
	};

	//Player position
	short int x = 6;
	short int y = 6;
	char playerposition = map[x][y] = 'O';

	//Goblins positions
	char goblin1position = map[4][6] = 'G';
	char goblin2position = map[3][4] = 'G';
	char goblin3position = map[2][8] = 'G';

	//Variables defining Game class
	short int GameOver = 0;
	short int w1 = 70;
	short int w2 = 20;
	short int w3 = 30;
	short int choice = 0;

	//Variable telling if the fight should happen
	bool fight = false;

public:

	//setters
	void SetGameOver(short int value);

	//Getters
	short int GetGameOver();
	bool Getfight();

	//Methods
	void drawmap();
	void setup(Player player, Goblin goblin);
	void input();
	void checkinput(Player &player, Goblin goblin);
	void goblinattack(Player &player, Goblin goblin);
	void chechififghtends(Player player, Goblin &goblin);
	void fightinput(Player player, Goblin goblin);
	void fightcheckinput(Player &player, Goblin &goblin);
	void resetposition();
};