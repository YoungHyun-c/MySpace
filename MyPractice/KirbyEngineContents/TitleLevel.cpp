#include "TitleLevel.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineSound.h>

#include "BackGround.h"

TitleLevel::TitleLevel()
{

}

TitleLevel::~TitleLevel()
{

}

void TitleLevel::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("Title.bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");
		FilePath.MoveChild("Resource\\BackGround\\");
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Title.bmp"));
	}

	GameEngineSound::SetGlobalVolume(0.5f);

	BackGroundPtr = CreateActor<BackGround>();
	BackGroundPtr->Init("Title.bmp", "Title.bmp");
}

void TitleLevel::Update(float _DeltaTime)
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
}