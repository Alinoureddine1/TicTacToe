
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
using namespace std;

char grid[10] = { '0','1','2','3','4','5','6','7','8','9' };

//game status

int status() {

	if(grid[1]== grid[2] && grid[2] == grid[3])
	{
		return 1;
	}
	else if (grid[4] == grid[5] && grid[5] == grid[6])
	{
		return 1;
	}
	else if (grid[7] == grid[8] && grid[8] == grid[9])
	{
		return 1;
	}
	else if (grid[1] == grid[4] && grid[4] == grid[7])
	{
		return 1;
	}
	else if (grid[2] == grid[5] && grid[5] == grid[8])
	{
		return 1;
	}
	else if (grid[3] == grid[6] && grid[6] == grid[9])
	{
		return 1;
	}
	else if (grid[1] == grid[5] && grid[5] == grid[9])
	{
		return 1;
	}
	else if (grid[3] == grid[5] && grid[5] == grid[7])
	{
		return 1;
	}
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' && grid[4] != '4' && grid[5] != '5' && grid[6] != '6' && grid[7] != '7' && grid[8] != '8' && grid[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}

}


void brainplay() {

	while (true) {
		int choice = (rand() % 9) + 1;
		if (grid[choice] == 'X' || grid[choice] == 'O')
		{
			continue;
		}
		else
		{
			grid[choice] = 'O';
			break;
		}
	}
}


void Grid() {

	//header
	system("cls");
	
	//drawing the Grid
	cout << "     |     |     \n";
	cout << "  " << grid[1] << "  |  " << grid[2] << "  |  " << grid[3] << endl;
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << grid[4] << "  |  " << grid[5] << "  |  " << grid[6] << endl;
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << grid[7] << "  |  " << grid[8] << "  |  " << grid[9] << endl;
	cout << "     |     |     \n";
}


int singleplayer() {
	cout << "Game mode: Single Player\n";
	cout << "You are playing as X\n";
	cout << "Difficulty: Easy\n";
	cout << "LOADING.";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(3000);

	int choice = 0;
	int res = -1;
	do {
		Grid();
		cout << "\nChoose a spot: ";
		cin >> choice;
		if (grid[choice] != 'X' && grid[choice] != 'O' && choice <=9) {
			grid[choice] = 'X';
			res = status();
			if (res == 1) {
				Grid();
				cout << "\n\aYOU Win!" << endl;
				
				return 0;
			}
			brainplay();
			res = status();
			if (res == 1) {
				Grid();
				cout << "\n\aComputer wins" << endl;
				return 0;
			}

		}
		else {
			cout << "INVALID MOVE! PRESS ENTER TO CONTINUE";
			cin.ignore();
			cin.get();
		}
		
	} while (res == -1);
	Grid();
	cin.ignore();
	cin.get();
	cout << "It is a tie" << endl;
	return -1;
}

int versus(){
	cout << "Game mode: Versus\n";
	cout << "Player 1 is X \t PLayer 2 is O\n" << endl;
	cout << "LOADING.";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(3000);
	int player = 1;
	int choice = 0;
	int res = 0;
	char mark; 

		do {
			Grid();
			player = (player % 2) ? 1 : 2;
			cout << "\nplayer " << player << "'s turn, choose one of the availabe spots: ";
			cin >> choice;
			mark = (player == 1) ? 'X' : 'O';
			if (grid[choice] != 'X' && grid[choice] != 'O') {
				grid[choice] = mark;
			}
			else {
				cout << "INVALID MOVE! PRESS ENTER";
				player--;
				cin.ignore();
				cin.get();
			}
			res = status();
			player++;

		} while (res == -1);
		Grid();
		if (res == 1) {
			cout << "\a Player " << --player << " Wins!" << endl;
		}
		else {
			cout << "\aIt is a TIE" << endl;
		}
		cin.ignore();
		cin.get();
		return 0;

}




int main() {
	cout << "\nTic Tac Toe \n\n";
	char mode =' ';
	while (mode != 'T') {
	cout << "Choose your game mode:\n";
	cout << "[A]single player \n[B] Versus\n";
	cin >> mode;
	if (mode == 'A' || mode == 'a') {
		mode = 'T';
		system("cls");
		singleplayer();
	}
	else if (mode == 'B' || mode == 'b') {
		system("cls");
		mode = 'T';
		versus();
	}


}
	
		
	return 0;
		
}
