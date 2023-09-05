#include "Board.h"
#include <iostream>
using namespace std;
int main()
{
	Board b;
	b.disp_board();
	b.create_mines();
	int x, y; char c = 'O';
	cout << "Enter coord (x-cord->Enter->y-coord->Enter): " << endl;
	cin >> x;
	cin >> y;
	bool cont = b.move(x, y);
	while (cont)
	{
		cout << "Enter 'F' to mark as flag (else enter any random char): " << endl;
		cin >> c;
		cout << "Enter coord (x-cord->Enter->y-coord->Enter): " << endl;
		cin >> x;
		cin >> y;
		if (x < 0 || x>8 || y < 0 || y>8)
		{
			cout << "Invalid! Please make a different choice!" << endl;
			continue;
		}
		switch (c)
		{
		case 'F': case 'f':
			b.flag(x, y);
			break;
		default:
			cont = b.move(x, y);
			break;
		}
	}
}
