#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>

// Ό³Έν :
class StageItem : public GameEngineLevel
{
public:
	// constructer destructer
	StageItem();
	~StageItem();

	// delete Function
	StageItem(const StageItem& _Other) = delete;
	StageItem(StageItem&& _Other) noexcept = delete;
	StageItem& operator = (const StageItem& _Other) = delete;
	StageItem& operator = (StageItem&& _Other) noexcept = delete;

protected:
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	void Start() override;
	void Update(float _Delta);
	void Release() override;

	class BackGround* BackGroundPtr;
	class Player* LevelPlayer = nullptr;

	GameEngineSoundPlayer BGMPlayer;
};

