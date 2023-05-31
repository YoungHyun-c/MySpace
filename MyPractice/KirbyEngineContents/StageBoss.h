#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>

// Ό³Έν :
class StageBoss : public GameEngineLevel
{
public:
	// constructer destructer
	StageBoss();
	~StageBoss();

	// delete Function
	StageBoss(const StageBoss& _Other) = delete;
	StageBoss(StageBoss&& _Other) noexcept = delete;
	StageBoss& operator = (const StageBoss& _Other) = delete;
	StageBoss& operator = (StageBoss&& _Other) noexcept = delete;

protected:
	void LevelStart(GameEngineLevel *_PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	void Start() override;
	void Update(float _Delta) override;
	void Release() override;

	class BackGround* BackGroundPtr;
	class Player* LevelPlayer = nullptr;

	GameEngineSoundPlayer BGMPlayer;
};

