

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

bool IsPlay = true;

//void PlayerMove(int* PlayerY, int* PlayerX, int _Y, int _X)
//{
//	*PlayerY += _Y;
//	*PlayerX += _X;
//}

int* PlayerMove(int* PlayerY, int* PlayerX, int _Y, int _X)
{
	*PlayerY += _Y;
	*PlayerX += _X;

	return PlayerY, PlayerX;
}

int main()
{
	const int ScreenXSize = 10;
	const int ScreenYSize = 5;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t Y = 0; Y < ScreenYSize; Y++)
	{
		for (size_t X = 0; X < ScreenXSize; X++)
		{
			Arr[Y][X] = 'a';
			printf_s("%c", Arr[Y][X]);
		}
		printf_s("\n");
	}

	int PlayerX = ScreenXSize / 2;
	int PlayerY = ScreenYSize / 2;

	while (IsPlay)
	{
		system("cls");

		//Arr[PlayerY][PlayerX] = '*';

		for (size_t Y = 0; Y < ScreenYSize; Y++)
		{
			for (size_t X = 0; X < ScreenXSize; X++)
			{
				if (PlayerY == Y && PlayerX == X)
				{
					printf_s("*");
				}
				else
				{
					printf_s("%c", Arr[Y][X]);
				}
			}
			printf_s("\n");
		}

		if (0 == _kbhit())
		{
			Sleep(200);
			continue;
		}

		char ch = _getch();

		switch (ch)
		{
		case 'a':
		case 'A':
			//PlayerX -= 1;
			//Arr[PlayerY][PlayerX + 1] = 'a';
			PlayerMove(&PlayerY, &PlayerX, 0, -1);
			break;
		case 'd':
		case 'D':
			PlayerX += 1;
			//Arr[PlayerY][PlayerX - 1] = 'a';
			break;
		case 'w':
		case 'W':
			PlayerY -= 1;
			//Arr[PlayerY + 1][PlayerX] = 'a';
			break;
		case 's':
		case 'S':
			PlayerY += 1;
			//Arr[PlayerY - 1][PlayerX] = 'a';
			break;
		case 'q':
		case 'Q':
			IsPlay = false;
			return 1;
		default:
			break;
		}
		Sleep(200);
	}
}