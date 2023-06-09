#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class Monster : public GameEngineActor
{
private:
	static std::list<Monster*> AllMonster;

public:
	static void AllMonsterDeath();

public:
	// constructer destructer
	Monster();
	~Monster();

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator = (const Monster& _Other) = delete;
	Monster& operator = (Monster&& _Other) noexcept = delete;

protected:

private:
	void Start() override;

	void Update(float _Delta) override;

};

