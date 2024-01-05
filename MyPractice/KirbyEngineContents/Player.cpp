#include "Player.h"
#pragma region Headers

#include "ContentsEnum.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCore.h>
#include "Bullet.h"
#include "Monster.h"
#include "PlayUIManager.h"
#include <GameEnginePlatform/GameEngineInput.h>

#pragma endregion

Player* Player::MainPlayer = nullptr;

Player::Player()
{

}

Player::~Player()
{

}

void Player::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("KirbyRightNormal.Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("Resource");

		GameEnginePath FolderPath = FilePath;

		FilePath.MoveChild("Resource\\Kirby\\");

		ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("KirbyRightNormal.bmp"), 5, 25);
		ResourcesManager::GetInst().CreateSpriteSheet(FilePath.PlusFilePath("KirbyLeftNormal.bmp"), 5, 25);
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("HPBar.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Star.bmp"));
	}

	{
		MainRenderer = CreateRenderer(RenderOrder::Play);


		//MainRenderer->SetRenderScale({ 200, 200 });

		MainRenderer->CreateAnimation("Left_Idle", "KirbyLeftNormal.bmp", 0, 1, 1.0f, true);
		MainRenderer->CreateAnimation("Right_Idle", "KirbyRightNormal.bmp", 0, 1, 1.0f, true);

		MainRenderer->CreateAnimation("Left_Run", "KirbyLeftNormal.bmp", 0, 13, 0.1f, true);
		MainRenderer->CreateAnimation("Right_Run", "KirbyRightNormal.bmp", 0, 13, 0.1f, true);
		//MainRenderer->ChangeAnimation("Idle");
		MainRenderer->ChangeAnimation("Right_Idle");
		MainRenderer->SetRenderScale({ 400, 400 });
		//MainRenderer->SetRenderScaleToTexture();

		/*GameEngineRenderer* Ptr = CreateRenderer("Test.Bmp", RenderOrder::Play);
*
*
		Ptr->SetRenderScale({ 50, 50 });
		Ptr->SetTexture("Test.Bmp");*/

	}

	{
		GameEngineRenderer* Ptr = CreateRenderer("HPbar.Bmp", RenderOrder::Play);
		Ptr->SetRenderPos({ -400, -270 });
		Ptr->SetRenderScale({ 200, 10 });
		//Ptr->SetTexture("HPBar.Bmp");
	}

	{
		//BodyCollision = CreateCollision(CollisionOrder::PlayerBody);
		//BodyCollision->SetCollisionScale({ 100, 100 });
		//BodyCollision->SetCollisionType(CollisionType::CirCle);
	}

	{
		AttackLeftCollision = CreateCollision(CollisionOrder::PlayerAttackSize);
		//AttackCollision->SetCollisionPos({ 100.0f, -25.0f });
		AttackLeftCollision->SetCollisionPos(LeftCheck);
		AttackLeftCollision->SetCollisionScale({ 180, 80 });
		AttackLeftCollision->SetCollisionType(CollisionType::Rect);
	}

	{
		AttackRightCollision = CreateCollision(CollisionOrder::PlayerAttackSize);
		AttackRightCollision->SetCollisionPos(RightCheck);
		AttackRightCollision->SetCollisionScale({ 180, 80 });
		AttackRightCollision->SetCollisionType(CollisionType::Rect);
	}

	ChangeState(PlayerState::Idle);
	Dir = PlayerDir::Right;
}

void Player::Update(float _Delta)
{
	//std::vector<GameEngineCollision*> _Col;
	//if (true == BodyCollision->Collision(CollisionOrder::MonsterBody, _Col
	//	, CollisionType::Rect
	//	, CollisionType::Rect
	//))
	//{
	//	for (size_t i = 0; i < _Col.size(); i++)
	//	{
	//		GameEngineCollision* Collision = _Col[i];

	//		GameEngineActor* Actor = Collision->GetActor();

	//		Actor->Death();
	//	}
	//	// 나는 몬스터랑 충돌한거야.
	//}

	//std::vector<GameEngineCollision*> _Col;
	//if (true == AttackCollision->Collision(CollisionOrder::MonsterBody, _Col
	//	, CollisionType::Rect
	//	, CollisionType::Rect
	//))
	//{
	//	for (size_t i = 0; i < _Col.size(); i++)
	//	{
	//		GameEngineCollision* Collision = _Col[i];

	//		GameEngineActor* Actor = Collision->GetActor();

	//		Actor->Death();
	//	}
	//	// 나는 몬스터랑 충돌한거야.
	//}


	if (true == GameEngineInput::IsDown('L'))
	{
		Monster::AllMonsterDeath();
	}

	if (true == GameEngineInput::IsDown('Y'))
	{
		//MainRenderer->SetOrder(100);
		GameEngineLevel::CollisionDebugRenderSwitch();
		//GravityOff();
	}

	if (true == GameEngineInput::IsPress('N'))
	{
		GameEngineWindow::MainWindow.AddDoubleBufferingCopyScaleRatio(-1.0f * _Delta);
	}

	if (true == GameEngineInput::IsPress('M'))
	{
		GameEngineWindow::MainWindow.AddDoubleBufferingCopyScaleRatio(1.0f * _Delta);
	}

	//if (true == GameEngineInput::IsDown(VK_LBUTTON))
	//{
	//	std::vector<GameEngineCollision*> _Col;
	//	if (true == AttackRightCollision->Collision(CollisionOrder::MonsterBody, _Col
	//		, CollisionType::Rect, CollisionType::Rect))
	//	{
	//		for (size_t i = 0; i < _Col.size(); i++)
	//		{
	//			GameEngineCollision* Collision = _Col[i];

	//			GameEngineActor* Actor = Collision->GetActor();

	//			Actor->Death();
	//		}
	//		// 나는 몬스터랑 충돌한거야.
	//	}
	//}

	StateUpdate(_Delta);

	CameraFocus();


	// Test중
}

void Player::StateUpdate(float _Delta)
{
	switch (State)

	{
	case PlayerState::Idle:
		return IdleUpdate(_Delta);
	case PlayerState::Run:
		return RunUpdate(_Delta);
	default:
		break;
	}
}

void Player::ChangeState(PlayerState _State)
{
	if (_State != State)
	{
		switch (_State)

		{
		case PlayerState::Idle:
			IdleStart();
			break;
		case PlayerState::Run:
			RunStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Player::DirCheck()
{
	PlayerDir CheckDir = PlayerDir::Max;

	if (true == GameEngineInput::IsDown('A'))
	{
		CheckDir = PlayerDir::Left;
	}
	else if (true == GameEngineInput::IsDown('D'))
	{
		CheckDir = PlayerDir::Right;
	}

	bool ChangeDir = false;

	if (CheckDir != PlayerDir::Max)
	{
		Dir = CheckDir;
		ChangeDir = true;
	}

	if (CheckDir != PlayerDir::Max && true == ChangeDir)
	{
		ChangeAnimationState(CurState);
	}
}

void Player::ChangeAnimationState(const std::string& _StateName)
{
	// "Idle"
	// _StateName

	std::string AnimationName;

	switch (Dir)
	{
	case PlayerDir::Right:
		AnimationName = "Right_";
		break;
	case PlayerDir::Left:
		AnimationName = "Left_";
		break;
	default:
		break;
	}
	AnimationName += _StateName;

	CurState = _StateName;

	MainRenderer->ChangeAnimation(AnimationName);
}

void Player::LevelStart()
{
	MainPlayer = this;
}

void Player::Render(float _Delta)
{
	std::string Text = "";

	Text += "플레이어 테스트 값 : ";
	Text += std::to_string(1.0f / _Delta);
	HDC dc = GameEngineWindow::MainWindow.GetBackBuffer()->GetImageDC();
	TextOutA(dc, 800, 3, Text.c_str(), static_cast<int>(Text.size()));

	CollisionData Data;

	Data.Pos = ActorCameraPos();
	Data.Scale = { 180, 80 };
	//Rectangle(dc, Data.iLeft(), Data.iTop(), Data.iRight(), Data.iBot());

	// 커피가 공격할 범위
	//Data.Pos = ActorCameraPos() + LeftCheck;
	//Rectangle(dc, Data.iLeft(), Data.iTop(), Data.iRight(), Data.iBot());

	//Data.Pos = ActorCameraPos() + RightCheck;
	//Rectangle(dc, Data.iLeft(), Data.iTop(), Data.iRight(), Data.iBot());
}