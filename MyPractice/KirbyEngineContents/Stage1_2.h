#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>

// Ό³Έν :
class Stage1_2 : public GameEngineLevel
{
public:
	// constructer destructer
	Stage1_2();
	~Stage1_2();

	// delete Function
	Stage1_2(const Stage1_2& _Other) = delete;
	Stage1_2(Stage1_2&& _Other) noexcept = delete;
	Stage1_2& operator = (const Stage1_2& _Other) = delete;
	Stage1_2& operator = (Stage1_2&& _Other) noexcept = delete;

protected:
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevvel) override;

private:
	void Start() override;
	void Update(float _Delta) override;
	void Release() override;

	class BackGround* BackGroundPtr;
	class Player* LevelPlayer = nullptr;

	GameEngineSoundPlayer BGMPlayer;
};

