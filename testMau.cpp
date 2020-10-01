#include <iostream>
#include <Windows.h>
using namespace std;


void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		textcolor(i);
		cout << "Nho BINH DINH qua di mat <3" << endl;
	}
	
	char a[1024] = "Nho Binh Dinh ghe luon. Anh yeu em rat nhieu...", b[1024], c[40];
	strcpy(b, a);
	strcat(a, b);
	for (int i = 0; i < strlen(a); i++)
	{
		strncpy(c, a + i, 38);
		Sleep(200);
		gotoxy(30, 12);
		cout << c;
		if (i == strlen(b))
			i = 0;
	}
	
	return 0;
}
