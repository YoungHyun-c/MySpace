#pragma once
#include "Math.h"


class Player
{
public:
	// constructer destructer
	Player();
	~Player();

	inline int2 GetPos() const
	{
		return Pos;
	}

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	void Input();


	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator = (const Player& _Other) = delete;
	Player& operator = (Player&& _Other) noexcept = delete;

protected:

private:
	static const int InterFrame = 200;
	int2 Pos = int2(0, 0);
};

