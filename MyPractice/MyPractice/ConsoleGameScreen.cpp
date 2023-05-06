#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;


int2 ConsoleGameScreen::GetSCreenSize()
{
	return int2{ ScreenXSize, ScreenYSize };
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t Y = 0; Y < ScreenYSize; Y++)
	{
		for (size_t X = 0; X < ScreenXSize; X++)
		{
			Arr[Y][X] = 'a';
		}

	}
}

void ConsoleGameScreen::ScreenPrint()
{
	for (size_t Y = 0; Y < ScreenYSize; Y++)
	{
		for (size_t X = 0; X < ScreenXSize; X++)
		{
			printf_s("%c", Arr[Y][X]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}
	if (0 > _Pos.Y)
	{
		return true;
	}
	if (ScreenXSize <= _Pos.X)
	{
		return true;
	}
	if (ScreenYSize <= _Pos.Y)
	{
		return true;
	}
	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}
	Arr[_Pos.Y][_Pos.X] = _Ch;

}

ConsoleGameScreen::ConsoleGameScreen()
{

}