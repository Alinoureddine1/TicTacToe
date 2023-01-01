
#include <iostream>
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

void Grid() {

	//header
	system("cls");
	cout << "\n\nTic Tac Toe \n\n";
	cout << "Player 1 is X \t PLayer 2 is O\n" << endl;

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


int main() {
	int player =1;
	int choice = 0;
	int res = 0;
	char mark;

	do {
		Grid();
		player = (player % 2) ? 1 : 2;	
		cout << "player " << player << "`s turn, choose one of the availabe spots: ";
		cin >> choice;
		mark = (player == 1) ? 'X' : 'O';
		if (grid[choice] != 'X' && grid[choice] != 'O') {
			grid[choice] = mark;
		}
		else {
			cout << "INVALID MOVE!";
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
