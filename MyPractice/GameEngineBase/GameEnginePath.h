#pragma once

// ���� :
class GameEnginePath
{
public:
	// constructer destructer
	GameEnginePath();
	~GameEnginePath();

	// delete Function
	GameEnginePath(const GameEnginePath& _Other) = delete;
	GameEnginePath(GameEnginePath&& _Other) noexcept = delete;
	GameEnginePath& operator = (const GameEnginePath& _Other) = delete;
	GameEnginePath& operator = (GameEnginePath&& _Other) noexcept = delete;

protected:

private:

};

