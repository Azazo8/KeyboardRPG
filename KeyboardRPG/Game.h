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
	int x = 6;
	int y = 6;
	char playerposition = map[x][y] = 'O';

	//Goblins positions
	char goblin1position = map[4][6] = 'G';
	char goblin2position = map[3][4] = 'G';
	char goblin3position = map[2][8] = 'G';

	//Variables defining Game class
	int GameOver = 0;
	int w1 = 70;
	int w2 = 20;
	int w3 = 30;
	int choice = 0;

	//Variable telling if the fight should happen
	bool fight = false;

public:

	//setters
	void SetGameOver(short int value);

	//Getters
	int GetGameOver();
	bool GetFight();

	//Methods
	void DrawMap();
	void Setup(Player player, Goblin goblin);
	void Input();
	void CheckInput(Player &player, Goblin goblin);
	void GoblinAttack(Player &player, Goblin goblin);
	void CheckIfFightEnds(Player player, Goblin &goblin);
	void FightInput(Player player, Goblin goblin);
	void FightCheckInput(Player &player, Goblin &goblin);
	void ResetPosition();
};