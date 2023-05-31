#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>

// Ό³Έν :
class Stage1_1 : public GameEngineLevel
{
public:
	// constructer destructer
	Stage1_1();
	~Stage1_1();

	// delete Function
	Stage1_1(const Stage1_1& _Other) = delete;
	Stage1_1(Stage1_1&& _Other) noexcept = delete;
	Stage1_1& operator = (const Stage1_1& _Other) = delete;
	Stage1_1& operator = (Stage1_1&& _Other) noexcept = delete;

protected:
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	void Start() override;
	void Update(float _Delta) override;
	void Release() override;
	
	class BackGround* BackGroundPtr;
	class Player* LevelPlayer = nullptr;

	GameEngineSoundPlayer BGMPlayer;
};

