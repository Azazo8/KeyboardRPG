#include "Menu.h"

//Setters
void Menu::Setchoice(short int value)
{
	choice = value;
}

//Getters
short int Menu::Getchoice()
{
	return choice;
}

//Main menu display
void Menu::setup()
{
		std::cout << std::setw(w1) << "*************************\n";
		std::cout << std::setw(w1) << "*      KeyboardRPG      *\n";
		std::cout << std::setw(w1) << "*************************\n";
		std::cout << "\nChoose your option: \n\n";
		std::cout << std::setw(w2) << "1. New Game         \n";
		std::cout << std::setw(w2) << "2. Description      \n";
		std::cout << std::setw(w2) << "3. Exit game        \n";
		std::cout << "\nI choose: ";
}

//Main menu input
void Menu::input()
{
	std::cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3)
	{
		std::cout << "There is no such option.\n";
		system("pause");
	}
	std::cin.clear();
	std::cin.ignore(100, '\n');
	system("cls");
}

//Options based on input
void Menu::options()
{
	switch (choice)
	{
	    case 1:
			break;
		break;

	    case 2:
	    {
		    std::cout << "Title: KeyboardRPG\n";
		    std::cout << "Author: XYZ\n";
		    std::cout << "IDE: Visual Studio 2022\n";
		    std::cout << "Language: C++\n";
			std::cout << "The story fragments of the game were written by ChatGPT. I'm not very good at story writing :(\n\n";
		    std::cout << "Press any key to go back...\n";
		    _getch();
	    } break;

	    case 3:
	    {
		    std::cout << "Thanks for playing!\n";
		    Sleep(2000);
		    exit(0);
	    } break;
	}
	system("cls");
}