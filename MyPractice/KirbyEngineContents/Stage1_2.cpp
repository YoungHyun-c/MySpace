#include "Stage1_2.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include "PlayUIManager.h"

// Contetns
#include "Player.h"
#include "Monster.h"
#include "BackGround.h"


Stage1_2::Stage1_2()
{

}

Stage1_2::~Stage1_2()
{

}

void Stage1_2::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("StageTest1_2.Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\BackGround\\");
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Stage1_2.Bmp"));
	}

	GameEngineSound::SetGlobalVolume(0.5f);

	BackGroundPtr = CreateActor<BackGround>();
	BackGroundPtr->Init("StageTest1_2.Bmp", "Stage1_2.bmp");

	LevelPlayer = CreateActor<Player>();
	LevelPlayer->SetGroundTexture("Stage1_2.bmp");

	//CreateActor<PlayUIManager>();

}

void Stage1_2::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown('0'))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}
	if (true == GameEngineInput::IsDown('1'))
	{
		GameEngineCore::ChangeLevel("Stage1_1");
	}
	if (true == GameEngineInput::IsDown('2'))
	{
		GameEngineCore::ChangeLevel("Stage1_2");
	}
	if (true == GameEngineInput::IsDown('3'))
	{
		GameEngineCore::ChangeLevel("StageItem");
	}
	if (true == GameEngineInput::IsDown('4'))
	{
		GameEngineCore::ChangeLevel("StageBoss");
	}
	if (true == GameEngineInput::IsDown('5'))
	{
		GameEngineCore::ChangeLevel("EndingLevel");
	}

	if (true == GameEngineInput::IsDown('J'))
	{
		BackGroundPtr->SwitchRender();
	}
}

void Stage1_2::Release()
{

}

void Stage1_2::LevelStart(GameEngineLevel* _PrevLevel)
{
	if (nullptr == LevelPlayer)
	{
		MsgBoxAssert("플레이어를 세팅해주지 않았습니다.");
	}

	LevelPlayer->SetGroundTexture("Stage1_2.bmp");
}


void Stage1_2::LevelEnd(GameEngineLevel* _NextLevel)
{

}