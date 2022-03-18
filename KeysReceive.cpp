#include<conio.h>
#include<iostream>
#include<stdio.h>
#define ROWS 5
#define COLS 15

using namespace std;
char screen[ROWS][COLS];


#include<windows.h>
void gotoRowCol(int rpos, int cpos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int xpos = cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}


int main()
{
	int d, cr=0, cc =0;
//	char ch;
	while (true)
	{
		if (_kbhit())
		{
			d = _getch();
			
			if (d == 224)
			{
				d = _getch();
				if (d == 72)
				{
					cr--;
				}
				else if (d == 80)
				{
					cr++;
				}
				else if (d == 77)
				{
					cc++;
				}
				else if (d == 75)
				{
					cc--;
				}
			}
			else if (d == 13)
			{
				cr++;
				cc = 0;
			}
			else if (d == 8)
			{
				cc--;
				printf("\b");
				printf(" ");
			}
			else
			{
				cout << char(d);
				cc++;
				
			}

		
			gotoRowCol(cr, cc);

		}
	}

	return 0;
}
