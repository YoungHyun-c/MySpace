#include "EndingLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

EndingLevel::EndingLevel()
{

}

EndingLevel::~EndingLevel()
{

}

void EndingLevel::Update(float _Delta)
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