#pragma once
#include <Windows.h>


// ���� :
class GameEngineTime
{
public:
	// constructer destructer
	GameEngineTime();
	~GameEngineTime();

	// delete Function
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) noexcept = delete;
	GameEngineTime& operator = (const GameEngineTime& _Other) = delete;
	GameEngineTime& operator = (GameEngineTime&& _Other) noexcept = delete;

protected:

private:

};
