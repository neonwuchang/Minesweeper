#include "Board.h"
#include <iostream>
using namespace std;
int main()
{
	Board b;
	b.disp_board();
	b.create_mines();
	int x, y; char c;
	cout << "Enter coord (x-cord->Enter->y-coord->Enter): " << endl;
	cin >> x;
	cin >> y;
	bool cont = b.move(x, y);
	while (cont)
	{
		cout << "Enter 'F' to mark as flag/ Enter 'O' to flip tile: " << endl;
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
		case 'O': case 'o':
			cont = b.move(x, y);
			break;
		case 'F': case 'f':
			b.flag(x, y);
			break;
		default:
			cout << "Invalid Choice";
			break;
		}
	}
}