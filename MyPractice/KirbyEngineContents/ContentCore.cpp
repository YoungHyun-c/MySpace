#include "ContentCore.h"
#include "TitleLevel.h"
//#include "PlayLevel.h"
#include "Stage1_1.h"
#include "Stage1_2.h"
#include "EndingLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>

ContentCore::ContentCore()
{

}

ContentCore::~ContentCore()
{

}

void ContentCore::Start()
{
	GameEngineWindow::MainWindow.SetPosAndScale({ 100, 100 }, { 1024, 576 });
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	//GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::CreateLevel<Stage1_1>("Stage1_1");
	GameEngineCore::CreateLevel<Stage1_2>("Stage1_2");
	GameEngineCore::CreateLevel<EndingLevel>("EndingLevel");

	// 이 레벨이 화면에 보여라.
	GameEngineCore::ChangeLevel("Stage1_1");
}

// 행동하고
void ContentCore::Update(float _Delta)
{

}

// 그려지고
void ContentCore::Render(float _Delta)
{

}

// 정리된다.
void ContentCore::Release()
{

}
