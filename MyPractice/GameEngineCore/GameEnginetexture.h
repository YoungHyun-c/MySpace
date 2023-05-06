#pragma once

// Ό³Έν :
class GameEnginetexture
{
public:
	// constructer destructer
	GameEnginetexture();
	~GameEnginetexture();

	// delete Function
	GameEnginetexture(const GameEnginetexture& _Other) = delete;
	GameEnginetexture(GameEnginetexture&& _Other) noexcept = delete;
	GameEnginetexture& operator = (const GameEnginetexture& _Other) = delete;
	GameEnginetexture& operator = (GameEnginetexture&& _Other) noexcept = delete;

protected:

private:

};

