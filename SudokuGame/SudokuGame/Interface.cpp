#include "Interface.h"
void Interface::login()
{
	std::cout << "Witaj w grze Sudoku!\nAby rozpoczac wprowadz swoj adres email:\n";
	std::cin >> entry_username;
	while (!game.userLogin(entry_username))
	{
		std::cout << "Zly format maila, wprowadz ponownie:\n";
		std::cin >> entry_username;
	}
	system("cls");
}

void Interface::newSudoku()
{
	game.loadThread();
	std::cout << "Uzytkownik: " << entry_username << "\nWynik: 0" << "\nNajwyzszy wynik: " << game.getHighestScore() << "\n" << std::endl;
	game.newGame();
	std::cout << "1 - Dodaj liczbe, 2 - Nowa gra, 3 - Koniec gry" << std::endl;
}

void Interface::addNumber()
{
	int entry, column, row = 10;
	std::cout << "Row: ";
	std::cin >> row;
	while ((8 < row) or (0>row))
	{
		std::cout << "WPROWADZ POPRAWNA LICZBE Z ZAKRESU 0-8: ";
		std::cin >> row;
	}

	std::cout << "Column: ";
	std::cin >> column;
	while ((8 < column) or (0 > column))
	{
		std::cout << "WPROWADZ POPRAWNA LICZBE Z ZAKRESU 0-8: ";
		std::cin >> column;
	}

	std::cout << "Number: ";
	std::cin >> entry;
	while ((9 < entry) or (1 > entry))
	{
		std::cout << "WPROWADZ POPRAWNA LICZBE Z ZAKRESU 1-9: ";
		std::cin >> entry;
	}
	system("cls");


	std::cout << "Uzytkownik: " << entry_username << "\nWynik: "<<game.getCurrentScore() << "\nNajwyzszy wynik: " << game.getHighestScore() << std::endl;
	if (!game.addNumber(row, column, entry))
		std::cout << "Niepoprawna liczba nie zostala wpisana\n\n";
	std::cout << "1 - Dodaj liczbe, 2 - Nowa gra, 3 - Koniec gry" << std::endl;

}

bool Interface::isComplete()
{
	return game.isComplete();
}

void Interface::reloadSudoku()
{
	system("cls");
	game.loadThread();
	std::cout << "Uzytkownik: " << entry_username << "\nWynik: 0" << "\nNajwyzszy wynik: " << game.getHighestScore() << "\n" << std::endl;
	game.reloadGame();
	std::cout << "1 - Dodaj liczbe, 2 - Nowa gra, 3 - Koniec gry" << std::endl;
}

void Interface::endSudoku()
{
	game.saveScore();
	std::cout << "Zegnaj " << entry_username << std::endl;
}

void Interface::winSudoku()
{
	system("cls");
	std::cout << "Uzytkownik: " << entry_username << "\nWynik: " << game.getCurrentScore() << "\nNajwyzszy wynik: " << game.getHighestScore() << std::endl;
	game.printBoard();
	game.saveScore();
	std::cout << "Gratulacje!! Wynik zostal zapisany w folderze gracza" << std::endl;
	std::cout << "1 - Nowa gra, Inne - Koniec gry" << std::endl;
}

void Interface::cheat()
{
	system("cls");
	std::cout << "Uzytkownik: " << entry_username << "\nWynik: " << game.getCurrentScore() << "\nNajwyzszy wynik: " << game.getHighestScore() << std::endl;
	game.cheat();
	std::cout << "1 - Dodaj liczbe, 2 - Nowa gra, 3 - Koniec gry" << std::endl;
}