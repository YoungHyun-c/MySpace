#include <iostream>
#include <GameEngineCore/GameEngineCore.h>
#include <KirbyEngineContents/ContentCore.h>
#include <GameEngineBase/GameEngineMath.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	GameEngineCore::EngineStart<ContentCore>("MyWindow", hInstance);
	return 0;
}