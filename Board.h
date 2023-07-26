#pragma once
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
//BEGINNER BOARD: 9x9 BOARD with 10 MINES
class Board
{
private:
	int board[9][9];
	string cover[9][9];
	int mines[10][2] = { {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0} };

	// ensures a square is not populated by a mine twice
	// accepts current index where mine is to be put and checks that if it is already a mine; returns t/f accordingly
	bool not_dupe(int a, int b)
	{
		for (int x = 0; x < 10; x++)
			if (mines[x][0] == a && mines[x][1] == b)
				return false;
		return true;
	}

	// to display the board at the end of the game
	void end_board_disp()
	{
		cout << "____________________________\n|";
		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				if (board[x][y] >= 0 && board[x][y] < 10) cout << " ";
				cout << board[x][y] << "|";
			}if (x != 8)
				cout << "\n|";
		}
		cout << "\n----------------------------" << endl;
	}

	// whenever a mine is created, the adjoining squares' value is increased by 1 (if it isn't a mine itself) 
	void populate_board(int x, int y)
	{
		// top rt
		if (x == 0 && y == 0)
		{ 
			 if(board[x][y+1]!=99) board[x][y+1] += 1;
			 if(board[x+1][y]!=99) board[x+1][y] += 1;
			 if (board[x+1][y+1]!=99) board[x+1][y+1] += 1;
			 return;
		}
		// top left
		if (x == 0 && y == 8) 
		{
			if (board[x][y-1] != 99) board[x][y-1] += 1;
			if (board[x+1][y] != 99) board[x+1][y] += 1;
			if (board[x+1][y-1] != 99) board[x+1][y-1] += 1;
			return;
		}
		// top row
		if (x == 0) 
		{
			if (board[x][y+1] != 99) board[x][y+1] += 1;
			if (board[x][y - 1] != 99) board[x][y - 1] += 1;
			if (board[x+1][y] != 99) board[x+1][y] += 1;
			if (board[x+1][y+1] != 99) board[x+1][y+1] += 1;
			if (board[x+1][y - 1] != 99) board[x+1][y - 1] += 1;
			return;
		}
		// bot rt
		if (x == 8 && y == 0)
		{
			if (board[x][y+1] != 99) board[x][y+1] += 1;
			if (board[x-1][y] != 99) board[x-1][y] += 1;
			if (board[x-1][y+1] != 99) board[x-1][y+1] += 1;
			return;
		}
		// bot left
		if (x == 8 && y == 8)
		{
			if (board[x][y-1] != 99) board[x][y-1] += 1;
			if (board[x - 1][y] != 99) board[x - 1][y] += 1;
			if (board[x - 1][y-1] != 99) board[x - 1][y-1] += 1;
			return;
		}
		// bot row
		if (x == 8)
		{
			if (board[x][y + 1] != 99) board[x][y + 1] += 1;
			if (board[x][y - 1] != 99) board[x][y - 1] += 1;
			if (board[x - 1][y] != 99) board[x - 1][y] += 1;
			if (board[x - 1][y + 1] != 99) board[x - 1][y + 1] += 1;
			if (board[x - 1][y - 1] != 99) board[x - 1][y - 1] += 1;
			return;
		}
		// first col
		if (y == 0)
		{
			if (board[x][y + 1] != 99) board[x][y + 1] += 1;
			if (board[x+1][y] != 99) board[x+1][y] += 1;
			if (board[x + 1][y+1] != 99) board[x + 1][y+1] += 1;
			if (board[x - 1][y +1] != 99) board[x - 1][y + 1] += 1;
			if (board[x-1][y] != 99) board[x-1][y] += 1;
			return;
		}
		// last col
		if (y == 8)
		{
			if (board[x][y - 1] != 99) board[x][y - 1] += 1;
			if (board[x + 1][y] != 99) board[x + 1][y] += 1;
			if (board[x + 1][y - 1] != 99) board[x + 1][y - 1] += 1;
			if (board[x - 1][y - 1] != 99) board[x - 1][y - 1] += 1;
			if (board[x - 1][y] != 99) board[x - 1][y] += 1;
			return;
		}
		// all else
		if (board[x][y - 1] != 99) board[x][y - 1] += 1;
		if (board[x][y + 1] != 99) board[x][y + 1] += 1;
		if (board[x + 1][y + 1] != 99) board[x + 1][y + 1] += 1;
		if (board[x + 1][y] != 99) board[x + 1][y] += 1;
		if (board[x + 1][y - 1] != 99) board[x + 1][y - 1] += 1;
		if (board[x - 1][y - 1] != 99) board[x - 1][y - 1] += 1;
		if (board[x - 1][y] != 99) board[x - 1][y] += 1;
		if (board[x - 1][y + 1] != 99) board[x - 1][y + 1] += 1;
		return;
	}

public:
	void disp_board();
	void create_mines();
	bool move(int, int);
	void flag(int, int);
	Board()
	{
		//int c = 1;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				board[i][j] = 0;
				cover[i][j] = " X"; //to_string(c);
				//c++;
			}
		}
	}
};
void Board::disp_board()
{
	cout << "____________________________\n|";
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			string temp = cover[x][y];
			if (temp=="0"||temp=="1"||temp=="2"||temp=="3"|| temp == "4" || temp == "5" 
				|| temp == "6" || temp == "7" || temp == "8" || temp == "9") cout << " ";
			cout << temp << "|";
		}
		if (x != 8)	cout << "\n|";
	}
	cout << "\n----------------------------" << endl;
}

//randomly generate mines
void Board::create_mines()
{
	srand(time(NULL));
	int i = 0;
	while(i < 10) 
	{
		int x = (rand() % 10) ;
		int y = (rand() % 10) ;
		if (x == 9 || y == 9)continue;
		if (not_dupe(x, y))
		{
			board[x][y] = 99;
			mines[i][0] = x;
			mines[i][1] = y;
			populate_board(x, y);
			i++;
		}
	}
	
}

bool Board::move(int x, int y)
{
	if (board[x][y] == 99)
	{
		cout << "GAME OVER!" << endl;
		end_board_disp();
		return false;
	}
	else
	{
		if (cover[x][y] == " X")
		{
			cover[x][y] = to_string(board[x][y]);
			disp_board();
			return true;
		}
		else cout << "Already Flipped...Make a different choice!" << endl;
	}
}

void Board::flag(int x, int y)
{
	if (cover[x][y] == " X")
	{
		cover[x][y] = "Fl";
		disp_board();
	}
	else
		cout << "Invalid! Please make a different choice!" << endl;
}
