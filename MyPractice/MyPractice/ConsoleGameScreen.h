#pragma once
#include "Math.h"

// Ό³Έν :
class ConsoleGameScreen
{
public:
	static const int ScreenYSize = 5;
	static const int ScreenXSize = 5;

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}
	

	static int2 GetSCreenSize();

	void ScreenClear();

	void ScreenPrint();

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);


	// delete Function
	ConsoleGameScreen(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _Other) noexcept = delete;
	ConsoleGameScreen& operator = (const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen& operator = (ConsoleGameScreen&& _Other) noexcept = delete;

protected:

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };
	
	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};

