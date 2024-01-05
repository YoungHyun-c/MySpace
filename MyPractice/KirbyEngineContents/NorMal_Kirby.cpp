//#include "Normal_Kirby.h"
//#include <GameEngineBase/GameEngineTime.h>
//#include <GameEnginePlatform/GameEngineWindow.h>
//#include <GameEnginePlatform/GameEngineInput.h>
//#include <GameEnginePlatform/GameEngineSound.h>
//#include <GameEngineCore/ResourcesManager.h>
//#include <GameEngineCore/GameEngineCore.h>  //#include <LevelManager.h>
//#include <GameEngineCore/GameEngineRenderer.h>
//#include <GameEngineCore/GameEngineLevel.h>	//#include <Level.h>
//#include "ContentsEnum.h"
//#include <GameEngineCore/GameEngineCollision.h>
//#include <GameEngineCore/GameEngineObject.h>
////#include <GameEngineImage.h>
////#include "One_One_Back.h"
////#include "WeakMonster.h"
//#include <GameEngineBase/GameEngineFile.h>
//#include "Bullet.h"
////#include "BeamMonster.h"
////#include "CutterMonster.h"
////#include "Boss.h"
////#include "Stage_one_one.h"
//
//int Normal_Kirby::BackGroundSizeforCamX = 0;
//float Normal_Kirby::DamageTime = 0.5f;
//bool Normal_Kirby::DrainMonsterActive = false;
//bool Normal_Kirby::ShootMoveActive = false;
//
//Normal_Kirby::Normal_Kirby()
//	: Speed(400.0f), JumpDir_({ 0,0 }), FlyDir_({ 0,0 }), DebugState_(DebugMode::PLAYMODE), PlayerPivot_({ 0, -30 }), HP(6)
//{
//
//	//GH_SetPos(GH_GameEngineWindow::GH_GetInst().GH_GetSize().GH_halffloat4());
//
//	//GH_SetPos({ 150,100 });
//
//
//	RenderOrder(3);
//	//SetUpdateOrder(10);
//	//SetRenderOrder(3);
//
//}
//
//Normal_Kirby::~Normal_Kirby()
//{
//}
//
//Normal_Kirby::Normal_Kirby(Normal_Kirby&& _Other) noexcept
//{
//}
//
//std::string Normal_Kirby::GetDirString()
//{
//	//���� �������� ���¸� ���ڿ� "R"��,
//	//���� ������ ���¸� ���ڿ� "L"�� �������ִ� �Լ�
//	switch (dirstate_)
//	{
//	case DirectionState::LEFT:
//		return "L";
//		break;
//	case DirectionState::RIGHT:
//		return "R";
//		break;
//	default:
//		//GameEngineDebug::Assert();
//		break;
//	}
//
//	//GameEngineDebug::Assert();
//	return "";
//}
//
//void Normal_Kirby::MakeBreath()
//{
//	Bullet* BulletPtr = Normal_Kirby::GameEngineActor::GetLevel()->CreateActor<Bullet>();
//
//	if (dirstate_ == DirectionState::LEFT)
//	{
//		///BulletPtr->BulletDir_ = BulletDirectionState::LEFT;
//	}
//	else
//	{
//		///BulletPtr->BulletDir_ = BulletDirectionState::RIGHT;
//	}
//	///BulletPtr->ChangeState(BulletState::KirbyBreath);
//	BulletPtr->SetPos(GetPos());
//}
//
//
//void Normal_Kirby::LeftRightCheck()
//{
//	if (ShootMoveActive == true || DrainMonsterActive == true)
//	{
//		//������ ����� ���۵ưų� ���𰡸� �߻��ϴ� �ִϸ��̼��� ���۵����� �¿��Է� üũ�� ���´�
//		return;
//	}
//
//	DirectionState PrevDirectionState = dirstate_;
//	//�� ������ LEFT,RIGHT ���¸� �޴� Prev
//
//	//�¿�üũ�� ��� �ϴ��Ŀ� ���� ���� ��ġ�� �ٸ����̴�
//	if (true == GameEngineInput::IsPress('L'))
//	{
//		dirstate_ = DirectionState::LEFT;
//	}
//	else if (true == GameEngineInput::IsPress('R'))
//	{
//		dirstate_ = DirectionState::RIGHT;
//	}
//
//
//	//Ű�Է��� ���ͼ� ������ �ٲ������ �ִϸ��̼��� �̰����� �ٲ��ش�
//	if (PrevDirectionState != dirstate_)
//	{
//
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//			if (stateType_ == PlayerState::DrainING)
//			{
//				DrainEffectRender_->ChangeAnimation("DrainAfterDrainEffect" + GetDirString());
//			}
//			break;
//		case KirbyAbilityState::DrainAfter:
//			DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//			break;
//		case KirbyAbilityState::Beam:
//			BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//			break;
//		case KirbyAbilityState::Cutter:
//			CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//			break;
//		default:
//			break;
//		}
//
//		//�ִϸ��̼� �̸��� �� �����̸�+ L or R �̹Ƿ�
//		//���� ���ʻ��¸� L���� �ִϸ��̼���,
//		//������ ���¸� R���� �ִϸ��̼��� ������ ���̴�
//	}
//
//}
//
//// ���� �浹�� ����
////void Normal_Kirby::MonsterCollisionCheck()
////{
////	GameEngineCollision* Collision = BodyCheckCollision->CollisionGroupCheckOne(GAMECOLLISIONGROUP::MONSTER);
////
////
////	if (nullptr != Collision) //���� Monster�ȿ� ����ִ°͵� �߿� �浹�� �־������
////	{
////		std::string CheckMonster = Collision->GH_GetActor()->GH_GetName();
////		//���� Ŭ�������� NameBase�� SetName()�� ���༭ �̸��� ������, �� �̸��� �޾ƿ´�
////
////		if (CheckMonster == "WeakMonster")
////		{
////			WeakMonster* WeakMonsterPtr = Collision->GH_GetActorConvert<WeakMonster>();
////			WeakMonsterPtr->GH_ChangeState(GH_MonsterState::Damage);
////		}
////
////
////		if (CheckMonster == "BeamMonster")
////		{
////			BeamMonster* BeamMonsterPtr = Collision->GH_GetActorConvert<BeamMonster>();
////			BeamMonsterPtr->GH_ChangeState(GH_MonsterState::Damage);
////		}
////
////		if (CheckMonster == "CutterMonster")
////		{
////			CutterMonster* CutterMonsterPtr = Collision->GH_GetActorConvert<CutterMonster>();
////			CutterMonsterPtr->GH_ChangeState(GH_MonsterState::Damage);
////		}
////
////		//�������� ������, ������ �븻���·� ���ƿ��� �ȴ�
////		GH_ChangeState(GH_KirbyAbilityState::Normal, GH_PlayerState::DamageUp);
////	}
////
////
////}
//
//void Normal_Kirby::DrainCollisionCheck()
//{
//	GameEngineCollision* Collision = DrainAttackCollision->CollisionGroupCheckOne(CollisionOrder::Monster);
//
//
//	if (nullptr != Collision)
//	{
//
//
//
//		GameEngineCollision* DrainEndCollision = DrainCheckCollision->CollisionGroupCheckOne(CollisionOrder::Monster);
//		std::string CheckMonster = Collision->GetActor()->Get
//
//		if (CheckMonster == "TreeBoss")
//		{
//			return;
//		}
//
//		DrainMonsterActive = true;
//		DrainCheckCollision->SetCollisionScale({ 70, 70 });
//		if (CheckMonster == "WeakMonster")
//		{
//			DrainedMonsterState_ = "WeakMonster";
//			//WeakMonster* WeakMonsterPtr = Collision->GetActorConvert<WeakMonster>();
//
//			//WeakMonsterPtr->ChangeState(MonsterState::GetDrain);
//
//			float4 Distance = GetPos() - WeakMonsterPtr->GetPos();
//
//			if (DirectionState::LEFT == dirstate_)
//			{
//				//�� ��ġ�� ���缭 �������� ���� ������/�����߿��� ����� �����ϵ��� �ߴ�
//				WeakMonsterPtr->SetMove(float4::RIGHT * GameEngineTime::MainTimer.GetDeltaTime() * 300.0f);
//				if (0 < Distance.y)
//				{
//					WeakMonsterPtr->GH_SetMove(float4::DOWN * GameEngineTime::MainTimer.GetDeltaTime() * 200.0f);
//				}
//				else if (0 > Distance.y)
//				{
//					WeakMonsterPtr->SetMove(float4::UP * GameEngineTime::MainTimer.GetDeltaTime() * 300.0f);
//				}
//			}
//			else if (DirectionState::RIGHT == dirstate_)
//			{
//				WeakMonsterPtr->GH_SetMove(float4::LEFT * GameEngineTime::MainTimer.GetDeltaTime() * 300.0f);
//				if (0 < Distance.y)
//				{
//					WeakMonsterPtr->GH_SetMove(float4::DOWN * GameEngineTime::MainTimer.GetDeltaTime() * 200.0f);
//				}
//				else if (0 > Distance.y)
//				{
//					WeakMonsterPtr->GH_SetMove(float4::UP * GameEngineTime::MainTimer.GetDeltaTime() * 300.0f);
//				}
//			}
//
//			if (nullptr != DrainEndCollision)
//			{
//				EffectPlayer->Stop();
//				//EffectPlayer->PlayCountReset(1);
//				HoldingAbilityStarType_ = KirbyAbilityState::Normal;
//				DrainAttackCollision->SetCollisionScale({ 0,0 });
//				DrainCheckCollision->SetCollisionScale({ 0, 0 });
//				ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Stand);
//				DrainMonsterActive = false;
//				WeakMonsterPtr->ChangeState(MonsterState::Dead);
//			}
//		}
//
//
//	//	// ����
//	//	if (CheckMonster == "BeamMonster")
//	//	{
//	//		DrainedMonsterState_ = "BeamMonster";
//	//		BeamMonster* BeamMonsterPtr = Collision->GH_GetActorConvert<BeamMonster>();
//
//	//		BeamMonsterPtr->GH_ChangeState(GH_MonsterState::GetDrain);
//
//	//		GH_float4 Distance = GH_GetPos() - BeamMonsterPtr->GH_GetPos();
//
//	//		if (GH_DirectionState::LEFT == dirstate_)
//	//		{
//	//			//�� ��ġ�� ���缭 �������� ���� ������/�����߿��� ����� �����ϵ��� �ߴ�
//	//			BeamMonsterPtr->GH_SetMove(GH_float4::RIGHT * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			if (0 < Distance.y)
//	//			{
//	//				BeamMonsterPtr->GH_SetMove(GH_float4::DOWN * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			}
//	//			else if (0 > Distance.y)
//	//			{
//	//				BeamMonsterPtr->GH_SetMove(GH_float4::UP * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			}
//	//		}
//	//		else if (GH_DirectionState::RIGHT == dirstate_)
//	//		{
//	//			BeamMonsterPtr->GH_SetMove(GH_float4::LEFT * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			if (0 < Distance.y)
//	//			{
//	//				BeamMonsterPtr->GH_SetMove(GH_float4::DOWN * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 200.0f);
//	//			}
//	//			else if (0 > Distance.y)
//	//			{
//	//				BeamMonsterPtr->GH_SetMove(GH_float4::UP * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			}
//	//		}
//
//	//		if (nullptr != DrainEndCollision)
//	//		{
//	//			EffectPlayer->GH_Stop();
//	//			EffectPlayer->GH_PlayCountReset(1);
//	//			HoldingAbilityStarType_ = GH_KirbyAbilityState::Beam;
//	//			DrainAttackCollision->GH_SetSize({ 0,0 });
//	//			DrainCheckCollision->GH_SetSize({ 0, 0 });
//	//			GH_ChangeState(GH_KirbyAbilityState::DrainAfter, GH_PlayerState::Stand);
//	//			DrainMonsterActive = false;
//	//			BeamMonsterPtr->GH_ChangeState(GH_MonsterState::Dead);
//	//		}
//	//	}
//
//
//	//	if (CheckMonster == "CutterMonster")
//	//	{
//	//		DrainedMonsterState_ = "CutterMonster";
//	//		CutterMonster* CutterMonsterPtr = Collision->GH_GetActorConvert<CutterMonster>();
//
//	//		CutterMonsterPtr->GH_ChangeState(GH_MonsterState::GetDrain);
//
//	//		GH_float4 Distance = GH_GetPos() - CutterMonsterPtr->GH_GetPos();
//
//	//		if (GH_DirectionState::LEFT == dirstate_)
//	//		{
//	//			//�� ��ġ�� ���缭 �������� ���� ������/�����߿��� ����� �����ϵ��� �ߴ�
//	//			CutterMonsterPtr->GH_SetMove(GH_float4::RIGHT * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			if (0 < Distance.y)
//	//			{
//	//				CutterMonsterPtr->GH_SetMove(GH_float4::DOWN * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 200.0f);
//	//			}
//	//			else if (0 > Distance.y)
//	//			{
//	//				CutterMonsterPtr->GH_SetMove(GH_float4::UP * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			}
//	//		}
//	//		else if (GH_DirectionState::RIGHT == dirstate_)
//	//		{
//	//			CutterMonsterPtr->GH_SetMove(GH_float4::LEFT * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			if (0 < Distance.y)
//	//			{
//	//				CutterMonsterPtr->GH_SetMove(GH_float4::DOWN * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 200.0f);
//	//			}
//	//			else if (0 > Distance.y)
//	//			{
//	//				CutterMonsterPtr->GH_SetMove(GH_float4::UP * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			}
//	//		}
//
//	//		if (nullptr != DrainEndCollision)
//	//		{
//	//			EffectPlayer->GH_Stop();
//	//			EffectPlayer->GH_PlayCountReset(1);
//	//			HoldingAbilityStarType_ = GH_KirbyAbilityState::Cutter;
//	//			DrainAttackCollision->GH_SetSize({ 0,0 });
//	//			DrainCheckCollision->GH_SetSize({ 0,0 });
//	//			GH_ChangeState(GH_KirbyAbilityState::DrainAfter, GH_PlayerState::Stand);
//	//			DrainMonsterActive = false;
//	//			CutterMonsterPtr->GH_ChangeState(GH_MonsterState::Dead);
//	//		}
//	//	}
//
//
//	//	if (CheckMonster == "Apple")
//	//	{
//	//		DrainedMonsterState_ = "WeakMonster";
//	//		Bullet* BulletPtr = Collision->GH_GetActorConvert<Bullet>();
//
//	//		BulletPtr->GH_ChangeState(GH_BulletState::GetDrain);
//
//	//		GH_float4 Distance = GH_GetPos() - BulletPtr->GH_GetPos();
//
//	//		if (GH_DirectionState::LEFT == dirstate_)
//	//		{
//	//			//�� ��ġ�� ���缭 �������� ���� ������/�����߿��� ����� �����ϵ��� �ߴ�
//	//			BulletPtr->GH_SetMove(GH_float4::RIGHT * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			if (0 < Distance.y)
//	//			{
//	//				BulletPtr->GH_SetMove(GH_float4::DOWN * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 200.0f);
//	//			}
//	//			else if (0 > Distance.y)
//	//			{
//	//				BulletPtr->GH_SetMove(GH_float4::UP * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			}
//	//		}
//	//		else if (GH_DirectionState::RIGHT == dirstate_)
//	//		{
//	//			BulletPtr->GH_SetMove(GH_float4::LEFT * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			if (0 < Distance.y)
//	//			{
//	//				BulletPtr->GH_SetMove(GH_float4::DOWN * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 200.0f);
//	//			}
//	//			else if (0 > Distance.y)
//	//			{
//	//				BulletPtr->GH_SetMove(GH_float4::UP * GH_GameEngineTime::GH_GetInst().GH_GetDeltaTime() * 300.0f);
//	//			}
//	//		}
//
//	//		if (nullptr != DrainEndCollision)
//	//		{
//	//			EffectPlayer->GH_Stop();
//	//			EffectPlayer->GH_PlayCountReset(1);
//	//			HoldingAbilityStarType_ = GH_KirbyAbilityState::Normal;
//	//			DrainAttackCollision->GH_SetSize({ 0,0 });
//	//			DrainCheckCollision->GH_SetSize({ 0,0 });
//	//			GH_ChangeState(GH_KirbyAbilityState::DrainAfter, GH_PlayerState::Stand);
//	//			DrainMonsterActive = false;
//	//			BulletPtr->GH_ChangeState(GH_BulletState::Dead);
//	//		}
//	//	}
//
//	}
//}
//
//void Normal_Kirby::MonsterAttackCollisionCheck()
//{
//	GameEngineCollision* Collision = BodyCheckCollision->CollisionGroupCheckOne(CollisionOrder::MonsterAttack);
//
//
//	if (nullptr != Collision) //���� Monster�ȿ� ����ִ°͵� �߿� �浹�� �־������
//	{
//		//�������� ������, ������ �븻���·� ���ƿ��� �ȴ�
//
//		ChangeState(KirbyAbilityState::Normal, PlayerState::DamageUp);
//	}
//
//
//}
//
//
//void Normal_Kirby::BeamCollisionCheck()
//{
//	//GameEngineCollision* Collision = BeamAttackCollision->CollisionGroupCheckOne(GAMECOLLISIONGROUP::MONSTER);
//	GameEngineCollision* Collision = BeamAttackCollision->CollisionGroupCheckOne(CollisionOrder::Monster);
//
//	if (nullptr != Collision) //���� Monster�ȿ� ����ִ°͵� �߿� �浹�� �־������
//	{
//		std::string CheckMonster = Collision->GetActor()->GetName();
//		//���� Ŭ�������� NameBase�� SetName()�� ���༭ �̸��� ������, �� �̸��� �޾ƿ´�
//
//		if (CheckMonster == "WeakMonster")
//		{
//			WeakMonster* WeakMonsterPtr = Collision->GetActorConvert<WeakMonster>();
//			WeakMonsterPtr->GH_ChangeState(MonsterState::Damage);
//		}
//
//
//		//if (CheckMonster == "BeamMonster")
//		//{
//		//	BeamMonster* BeamMonsterPtr = Collision->GetActorConvert<BeamMonster>();
//		//	BeamMonsterPtr->GH_ChangeState(MonsterState::Damage);
//		//}
//
//		//if (CheckMonster == "CutterMonster")
//		//{
//		//	CutterMonster* CutterMonsterPtr = Collision->GH_GetActorConvert<CutterMonster>();
//		//	CutterMonsterPtr->GH_ChangeState(GH_MonsterState::Damage);
//		//}
//
//		//if (CheckMonster == "TreeBoss")
//		//{
//		//	TreeBoss* TreeMonsterPtr = Collision->GH_GetActorConvert<TreeBoss>();
//		//	TreeMonsterPtr->GH_ChangeState(GH_MonsterState::Damage);
//		//}
//	}
//
//}
//
//void Normal_Kirby::DoorCollisionCheck()
//{
//	if (true == BodyCheckCollision->CollisionCheck(One_One_Back::DoorCollision))
//	{
//		if (true == GameEngineInput::IsDown('U'))
//		{
//			EffectPlayer->Stop();
//			//EffectPlayer->PlayAlone("KirbyDoorIn.wav");
//			 
//			// ���� ����
//			//GetLevel()->ChangeLevel
//			//GameEngineCore::ChangeLevel();
//		}
//	}
//
//}
//
//void Normal_Kirby::Start()
//{
//	//GameEngineImage* FindImage = ResourcesManager::GH_GetInst().GH_FindGameImage("1-1_big.bmp");
//	// ? �� �޾ƿ���
//
//	//GameEnginePath FilePath;
//	//FilePath.SetCurrentPath();
//	//FilePath.MoveParentToExistsChild("Resource");
//	//FilePath.MoveChild("Resource\\BackGround\\");
//	//FindImage = ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Stage1_1.Bmp"));
//	//GameEngineImage* FindImage = ResourcesManager::GetInst().FindGameImage("1-1_big.bmp");
//	BackGroundSizeforCamX = FindImage->GH_GetSize().ix();
//	//ī�޶� �̵� ������ ���ؼ� ����� ũ�⸦ �޾ƿ�
//
//	if (false == GameEngineInput::GH_GetInst().GH_IsKey("L"))
//	{
//		//VK_ �ø���=> Ű���� ����Ű�Է�
//		//Ű�� ���� �Ҷ��� �빮�ڸ� ���� �� �ִ�
//		GameEngineInput::CreateKey("L", VK_LEFT);
//		GameEngineInput::CreateKey("R", VK_RIGHT);
//		GameEngineInput::CreateKey("U", VK_UP);
//		GameEngineInput::CreateKey("D", VK_DOWN);
//		GameEngineInput::CreateKey("Att", 'X');
//		GameEngineInput::CreateKey("Jump", 'Z');
//		GameEngineInput::CreateKey("ChangeDebugMode", 'R');
//		GameEngineInput::CreateKey("BackToNormal", 'F');
//		GameEngineInput::CreateKey("BeamChange", 'S');
//		GameEngineInput::CreateKey("CutterChange", 'D');
//	}
//
//	//�⺻ Ŀ�� ���� �ڵ�
//	{
//		int SpriteReverse = 160;
//
//		MainRender_ = CreateRenderer("normal_kirby.bmp");
//		MainRender_->CreateAnimation("NormalStandR", "normal_kirby.bmp", 13, 15, true, 0.3f);
//		MainRender_->CreateAnimation("NormalStandL", "normal_kirby.bmp", SpriteReverse + 13, SpriteReverse + 15, true, 0.3f);
//		MainRender_->CreateAnimation("NormalDownR", "normal_kirby.bmp", 88, 88, false);
//		MainRender_->CreateAnimation("NormalDownL", "normal_kirby.bmp", SpriteReverse + 88, SpriteReverse + 88, false);
//		MainRender_->CreateAnimation("NormalDrainReadyR", "normal_kirby.bmp", 110, 111, false, 0.07f);
//		MainRender_->CreateAnimation("NormalDrainReadyL", "normal_kirby.bmp", SpriteReverse + 110, SpriteReverse + 111, true, 0.07f);
//		MainRender_->CreateAnimation("NormalDrainINGR", "normal_kirby.bmp", 112, 113, true, 0.07f);
//		MainRender_->CreateAnimation("NormalDrainINGL", "normal_kirby.bmp", SpriteReverse + 112, SpriteReverse + 113, true, 0.07f);
//		MainRender_->CreateAnimation("NormalWalkR", "normal_kirby.bmp", 52, 61);
//		MainRender_->CreateAnimation("NormalWalkL", "normal_kirby.bmp", SpriteReverse + 52, SpriteReverse + 61);
//		MainRender_->CreateAnimation("NormalJumpUpR", "normal_kirby.bmp", 81, 81, false);
//		MainRender_->CreateAnimation("NormalJumpUpL", "normal_kirby.bmp", SpriteReverse + 81, SpriteReverse + 81, false);
//		MainRender_->CreateAnimation("NormalJumpDownR", "normal_kirby.bmp", 82, 87, false, 0.05f);
//		MainRender_->CreateAnimation("NormalJumpDownL", "normal_kirby.bmp", SpriteReverse + 82, SpriteReverse + 87, false, 0.05f);
//		MainRender_->CreateAnimation("NormalFlyR", "normal_kirby.bmp", 143, 153, false, 0.05f);
//		MainRender_->CreateAnimation("NormalFlyL", "normal_kirby.bmp", SpriteReverse + 143, SpriteReverse + 153, false, 0.05f);
//		MainRender_->CreateAnimation("NormalFlyEndR", "normal_kirby.bmp", 154, 156, false, 0.07f);
//		MainRender_->CreateAnimation("NormalFlyEndL", "normal_kirby.bmp", SpriteReverse + 154, SpriteReverse + 156, false, 0.07f);
//		MainRender_->CreateAnimation("NormalDamageUpR", "normal_kirby.bmp", 137, 137, false);
//		MainRender_->CreateAnimation("NormalDamageUpL", "normal_kirby.bmp", SpriteReverse + 137, SpriteReverse + 137, false);
//		MainRender_->CreateAnimation("NormalDamageDownR", "normal_kirby.bmp", 138, 142, false, 0.05f);
//		MainRender_->CreateAnimation("NormalDamageDownL", "normal_kirby.bmp", SpriteReverse + 138, SpriteReverse + 142, false, 0.05f);
//		MainRender_->CreateAnimation("NormalDead", "normal_kirby.bmp", SpriteReverse * 2 + 0, SpriteReverse * 2 + 0, false, 0.05f);
//		MainRender_->CreateAnimation("NormalSpin", "normal_kirby.bmp", SpriteReverse * 2 + 0, SpriteReverse * 2 + 14, true, 0.02f);
//		//StateName�� ����ϹǷ�, �ִϸ��̼� �̸��� Enum PlayerState�� ��ġ��Ű�°� ����
//		//������ �ٶ󺸴� �ִϸ��̼��� ��� �ǵڿ� L��, �������� �ٶ󺸴� ��� R�� ������
//	}
//
//	//����� Ŀ�� ���� �ڵ�
//	{
//		int SpriteReverse = 160;
//
//		DrainAfterRender_ = CreateRenderer("normal_kirby.bmp");
//		DrainAfterRender_->CreateAnimation("DrainAfterStandR", "normal_kirby.bmp", 43, 45, true, 0.3f);
//		DrainAfterRender_->CreateAnimation("DrainAfterStandL", "normal_kirby.bmp", SpriteReverse + 43, SpriteReverse + 45, true, 0.3f);
//		DrainAfterRender_->CreateAnimation("DrainAfterDownR", "normal_kirby.bmp", 97, 97, false);
//		DrainAfterRender_->CreateAnimation("DrainAfterDownL", "normal_kirby.bmp", SpriteReverse + 97, SpriteReverse + 97, false);
//		DrainAfterRender_->CreateAnimation("DrainAfterWalkR", "normal_kirby.bmp", 71, 80, true);
//		DrainAfterRender_->CreateAnimation("DrainAfterWalkL", "normal_kirby.bmp", SpriteReverse + 71, SpriteReverse + 80, true);
//		DrainAfterRender_->CreateAnimation("DrainAfterJumpUpR", "normal_kirby.bmp", 92, 93, false, 0.15f);
//		DrainAfterRender_->CreateAnimation("DrainAfterJumpUpL", "normal_kirby.bmp", SpriteReverse + 92, SpriteReverse + 93, false, 0.15f);
//		DrainAfterRender_->CreateAnimation("DrainAfterJumpDownR", "normal_kirby.bmp", 94, 96, false);
//		DrainAfterRender_->CreateAnimation("DrainAfterJumpDownL", "normal_kirby.bmp", SpriteReverse + 94, SpriteReverse + 96, false);
//		DrainAfterRender_->CreateAnimation("DrainAfterAttackR", "normal_kirby.bmp", 154, 156, false, 0.05f);
//		DrainAfterRender_->CreateAnimation("DrainAfterAttackL", "normal_kirby.bmp", SpriteReverse + 154, SpriteReverse + 156, false, 0.05f);
//		DrainAfterRender_->CreateAnimation("DrainAfterEatR", "normal_kirby.bmp", 123, 126, false, 0.05f);
//		DrainAfterRender_->CreateAnimation("DrainAfterEatL", "normal_kirby.bmp", SpriteReverse + 123, SpriteReverse + 126, false, 0.05f);
//	}
//
//	//Ŀ�� Ŀ�� ���� �ڵ�
//	{
//		int SpriteReverse = 50;
//		CutterRender_ = CreateRenderer("cutter_kirby.bmp");
//		CutterRender_->CreateAnimation("CutterStandR", "cutter_kirby.bmp", 0, 2, true, 0.3f);
//		CutterRender_->CreateAnimation("CutterStandL", "cutter_kirby.bmp", SpriteReverse + 0, SpriteReverse + 2, true, 0.3f);
//		CutterRender_->CreateAnimation("CutterDownR", "cutter_kirby.bmp", 30, 30, false);
//		CutterRender_->CreateAnimation("CutterDownL", "cutter_kirby.bmp", SpriteReverse + 30, SpriteReverse + 30);
//		CutterRender_->CreateAnimation("CutterWalkR", "cutter_kirby.bmp", 3, 12, true);
//		CutterRender_->CreateAnimation("CutterWalkL", "cutter_kirby.bmp", SpriteReverse + 3, SpriteReverse + 12, true);
//		CutterRender_->CreateAnimation("CutterJumpUpR", "cutter_kirby.bmp", 22, 22, false);
//		CutterRender_->CreateAnimation("CutterJumpUpL", "cutter_kirby.bmp", SpriteReverse + 22, SpriteReverse + 22, false);
//		CutterRender_->CreateAnimation("CutterJumpDownR", "cutter_kirby.bmp", 23, 28, false, 0.05f);
//		CutterRender_->CreateAnimation("CutterJumpDownL", "cutter_kirby.bmp", SpriteReverse + 23, SpriteReverse + 28, false, 0.05f);
//		CutterRender_->CreateAnimation("CutterFlyR", "cutter_kirby.bmp", 31, 41, false, 0.05f);
//		CutterRender_->CreateAnimation("CutterFlyL", "cutter_kirby.bmp", SpriteReverse + 31, SpriteReverse + 41, false, 0.05f);
//		CutterRender_->CreateAnimation("CutterFlyEndR", "cutter_kirby.bmp", 42, 44, false, 0.07f);
//		CutterRender_->CreateAnimation("CutterFlyEndL", "cutter_kirby.bmp", SpriteReverse + 42, SpriteReverse + 44, true, 0.07f);
//		CutterRender_->CreateAnimation("CutterAttackR", "cutter_kirby.bmp", 45, 49, false, 0.04f);
//		CutterRender_->CreateAnimation("CutterAttackL", "cutter_kirby.bmp", SpriteReverse + 45, SpriteReverse + 49, false, 0.04f);
//	}
//
//	//��Ŀ�� ���� �ڵ�
//	{
//		int SpriteReverse = 60;
//		BeamRender_ = CreateRenderer("beam_kirby.bmp");
//		BeamRender_->CreateAnimation("BeamStandR", "beam_kirby.bmp", 0, 2, true, 0.3f);
//		BeamRender_->CreateAnimation("BeamStandL", "beam_kirby.bmp", SpriteReverse + 0, SpriteReverse + 2, true, 0.3f);
//		BeamRender_->CreateAnimation("BeamDownR", "beam_kirby.bmp", 33, 33, false);
//		BeamRender_->CreateAnimation("BeamDownL", "beam_kirby.bmp", SpriteReverse + 33, SpriteReverse + 33, false);
//		BeamRender_->CreateAnimation("BeamWalkR", "beam_kirby.bmp", 3, 14, true);
//		BeamRender_->CreateAnimation("BeamWalkL", "beam_kirby.bmp", SpriteReverse + 3, SpriteReverse + 14);
//		BeamRender_->CreateAnimation("BeamJumpUpR", "beam_kirby.bmp", 25, 25, false);
//		BeamRender_->CreateAnimation("BeamJumpUpL", "beam_kirby.bmp", SpriteReverse + 25, SpriteReverse + 25, false);
//		BeamRender_->CreateAnimation("BeamJumpDownR", "beam_kirby.bmp", 26, 31, false, 0.05f);
//		BeamRender_->CreateAnimation("BeamJumpDownL", "beam_kirby.bmp", SpriteReverse + 26, SpriteReverse + 31, false, 0.05f);
//		BeamRender_->CreateAnimation("BeamFlyR", "beam_kirby.bmp", 37, 47, false, 0.05f);
//		BeamRender_->CreateAnimation("BeamFlyL", "beam_kirby.bmp", SpriteReverse + 37, SpriteReverse + 47, false, 0.05f);
//		BeamRender_->CreateAnimation("BeamFlyEndR", "beam_kirby.bmp", 34, 36, false, 0.07f);
//		BeamRender_->CreateAnimation("BeamFlyEndL", "beam_kirby.bmp", SpriteReverse + 34, SpriteReverse + 36, false, 0.07f);
//		BeamRender_->CreateAnimation("BeamAttackR", "beam_kirby.bmp", 48, 57, false, 0.05f);
//		BeamRender_->CreateAnimation("BeamAttackL", "beam_kirby.bmp", SpriteReverse + 48, SpriteReverse + 57, false, 0.05f);
//	}
//
//	//������� ����Ʈ ���� �ڵ�
//	{
//		DrainEffectRender_ =CreateRenderer("Kirby_Drain.bmp");
//		DrainEffectRender_->CreateAnimation("DrainAfterDrainEffectR", "Kirby_Drain.bmp", 0, 4, true, 0.02f);
//		DrainEffectRender_->CreateAnimation("DrainAfterDrainEffectL", "Kirby_Drain.bmp", 5, 9, true, 0.02f);
//		DrainEffectRender_->SetPivotPos(PlayerPivot_ + float4::RIGHT * 100);
//	}
//
//	//�� ���� ����Ʈ ���� �ڵ�
//	{
//		BeamEffectRender_ = CreateRenderer("Beam_Att.bmp");
//		BeamEffectRender_->CreateAnimation("BeamAttackEffectR", "Beam_Att.bmp", 0, 9, false, 0.05f);
//		BeamEffectRender_->CreateAnimation("BeamAttackEffectL", "Beam_Att.bmp", 10, 19, false, 0.05f);
//		BeamEffectRender_->SetPivotPos(PlayerPivot_ + float4::RIGHT * 100);
//	}
//
//	//Ŀ�� ��ų���� ����Ʈ ���� �ڵ�
//	{
//		EatEffectRender_ = CreateRenderer("Eat_Effect.bmp");
//		EatEffectRender_->CreateAnimation("EatEffect", "Eat_Effect.bmp", 0, 5, false, 0.04f);
//	}
//
//	//Ŀ�� ���� ���� �ڵ�
//	{
//		DanceRender_ = CreateRenderer("KirbyDance_one.bmp");
//		DanceRender_->CreateAnimation("KirbyDanceWait", "KirbyDance_one.bmp", 1, 1, false);
//		DanceRender_->CreateAnimation("KirbyDance", "KirbyDance_one.bmp", 1, 19, false, 0.085f);
//
//		DanceRendertwo_ = CreateRenderer("KirbyDance_two.bmp");
//		DanceRendertwo_->CreateAnimation("KirbyDanceWaittwo", "KirbyDance_two.bmp", 0, 0, false);
//		DanceRendertwo_->CreateAnimation("KirbyDancetwo", "KirbyDance_two.bmp", 0, 19, false, 0.085f);
//
//		DanceRendertwo_->ChangeAnimation("KirbyDanceWaittwo");
//		DanceRendertwo_->Off();
//
//		DanceRenderthree_ = CreateRenderer("KirbyDance_three.bmp");
//		DanceRenderthree_->CreateAnimation("KirbyDanceWaitthree", "KirbyDance_three.bmp", 0, 0, false);
//		DanceRenderthree_->CreateAnimation("KirbyDancethree", "KirbyDance_three.bmp", 0, 19, false, 0.085f);
//
//		DanceRenderthree_->ChangeAnimation("KirbyDanceWaitthree");
//		DanceRenderthree_->Off();
//
//	}
//	dirstate_ = DirectionState::RIGHT;
//
//	ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//	HoldingAbilityStarType_ = KirbyAbilityState::Normal;
//
//	MiddleGroundCheckCollision = CreateCollision(CollisionOrder::Player, CollisionType::Point);
//	RightGroundCheckCollision = CreateCollision(CollisionOrder::Player, CollisionType::Point);
//	RightGroundCheckCollision->SetPivot({ 30, -30 });
//	LeftGroundCheckCollision = CreateCollision(CollisionOrder::Player, CollisionType::Point);
//	LeftGroundCheckCollision->SetPivot({ -35,-30 });
//	TopGroundCheckCollision = CreateCollision(CollisionOrder::Player, CollisionType::Point);
//	TopGroundCheckCollision->SetPivot({ 0, -65 });
//
//	{
//		//�浹�� ����ų ���� ����
//		//�� ���� ���� ��������, ���� �浹�� �̹����� ��ǥ�� ���� ���ٸ� PointToImage�� true�� �����ϰ� �Ǵ� ���̴�
//		MiddleGroundCheckCollision->SetColorCheck(RGB(0, 0, 0));
//		RightGroundCheckCollision->SetColorCheck(RGB(0, 0, 0));
//		LeftGroundCheckCollision->SetColorCheck(RGB(0, 0, 0));
//		TopGroundCheckCollision->SetColorCheck(RGB(0, 0, 0));
//	}
//
//	//Ŀ�� ���� �浹����
//	BodyCheckCollision = CreateCollision(CollisionOrder::Player, CollisionType::Rect);
//	BodyCheckCollision->SetPivot(PlayerPivot_);
//	BodyCheckCollision->SetSize({ 75,70 });
//
//	//��� ������ �浹����
//	DrainAttackCollision = CreateCollision(CollisionOrder::Player, CollisionType::Rect);
//	DrainAttackCollision->SetSize({ 0,0 });
//	DrainAttackCollision->SetPivot(PlayerPivot_ + float4::RIGHT * 100);
//
//	//���������� ������ �ޱ� ���� �浹����
//	DrainCheckCollision = GH_CreateCollision(CollisionOrder::Player, CollisionType::Rect);
//	DrainCheckCollision->SetSize({ 0,0 });
//	DrainCheckCollision->SetPivot(PlayerPivot_ + float4::RIGHT * 50);
//
//	//�� ������ ���� �浹����
//	BeamAttackCollision = GH_CreateCollision(CollisionOrder::Player, CollisionType::Rect);
//	BeamAttackCollision->SetSize({ 0,0 });
//	BeamAttackCollision->SetPivot(PlayerPivot_ + float4::RIGHT * 100);
//
//
//	EffectPlayer = GameEngineSound::GetInst().CreateSoundPlayer();
//	if (EffectPlayer == nullptr)
//	{
//		MsgBoxAssert("���� �÷��̾� ������ ���� �ʾҽ��ϴ�");
//	}
//
//	//��� Ƚ���� �Ź� ���� �� �ִ� PlayCoundReset
//	EffectPlayer->PlayCountReset(1);
//
//}
//
//void Normal_Kirby::ChangeState(KirbyAbilityState _AbilityType, PlayerState _StateType)
//{
//	AbilityType_ = _AbilityType;
//	stateType_ = _StateType;
//
//
//	//���� ���°� ������ �ִϸ��̼��� �����Ų��
//	//string���� �� �ɷ»��¿� �ൿ���¸� ���� �̸����� �������,
//	//�Լ��ȿ��� string+�� �̿��ؼ� ���� ������ �ִϸ��̼� �̸��� ���� �̸����� �����.
//	//�׸��� �� �ִϸ��̼��� �� string�� �޾Ƽ� ���
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//	{
//		switch (stateType_)
//		{
//		case PlayerState::Stand:
//			AbilityStateName_ = "Normal";
//			StateName_ = "Stand";
//			StartStand();
//			break;
//		case PlayerState::Down:
//			AbilityStateName_ = "Normal";
//			StateName_ = "Down";
//			StartDown();
//			break;
//		case PlayerState::Walk:
//			AbilityStateName_ = "Normal";
//			StateName_ = "Walk";
//			StartWalk();
//			break;
//		case PlayerState::DrainReady:
//			AbilityStateName_ = "Normal";
//			StateName_ = "DrainReady";
//			StartDrainReady();
//			break;
//		case PlayerState::DrainING:
//			AbilityStateName_ = "Normal";
//			StateName_ = "DrainING";
//			StartDrainING();
//			break;
//		case PlayerState::JumpUp:
//			AbilityStateName_ = "Normal";
//			StateName_ = "JumpUp";
//			JumpDir_ = float4::UP * 700.0f;
//			StartJumpUp();
//			break;
//		case PlayerState::JumpDown:
//			AbilityStateName_ = "Normal";
//			StateName_ = "JumpDown";
//			StartJumpDown();
//			break;
//		case PlayerState::DamageUp:
//			AbilityStateName_ = "Normal";
//			DamageTime = 0.5f;
//			StateName_ = "DamageUp";
//			StartDamageUp();
//			break;
//		case PlayerState::DamageDown:
//			AbilityStateName_ = "Normal";
//			StateName_ = "DamageDown";
//			StartDamageDown();
//			break;
//		case PlayerState::Fly:
//			FlyDir_ = float4::UP * 400.0f;
//			AbilityStateName_ = "Normal";
//			StateName_ = "Fly";
//			StartFly();
//			break;
//		case PlayerState::FlyEnd:
//			AbilityStateName_ = "Normal";
//			StateName_ = "FlyEnd";
//			StartFlyEnd();
//			break;
//		case PlayerState::Dead:
//			DamageTime = 1.0f;
//			JumpDir_ = float4::UP * 1000.0f;
//			StartDead();
//			break;
//		case PlayerState::DanceReady:
//			StartDanceReady();
//			break;
//		case PlayerState::Dance:
//			StartDance();
//			break;
//		default:
//			break;
//		}
//	}
//	break;
//	case KirbyAbilityState::DrainAfter:
//		switch (stateType_)
//		{
//		case PlayerState::Stand:
//			AbilityStateName_ = "DrainAfter";
//			StateName_ = "Stand";
//			StartStand();
//			break;
//		case PlayerState::Down:
//			AbilityStateName_ = "DrainAfter";
//			StateName_ = "Down";
//			StartDown();
//			break;
//		case PlayerState::Walk:
//			AbilityStateName_ = "DrainAfter";
//			StateName_ = "Walk";
//			StartWalk();
//			break;
//		case PlayerState::JumpUp:
//			AbilityStateName_ = "DrainAfter";
//			StateName_ = "JumpUp";
//			JumpDir_ = float4::UP * 700.0f;
//			StartJumpUp();
//			break;
//		case PlayerState::JumpDown:
//			AbilityStateName_ = "DrainAfter";
//			StateName_ = "JumpDown";
//			StartJumpDown();
//			break;
//		case PlayerState::Attack:
//			AbilityStateName_ = "DrainAfter";
//			StateName_ = "Attack";
//			StartAttack();
//			break;
//		case PlayerState::Eat:
//			AbilityStateName_ = "DrainAfter";
//			StateName_ = "Eat";
//			StartEat();
//			break;
//		default:
//			break;
//		}
//		break;
//	case KirbyAbilityState::Beam:
//		switch (stateType_)
//		{
//		case PlayerState::Stand:
//			AbilityStateName_ = "Beam";
//			StateName_ = "Stand";
//			StartStand();
//			break;
//		case PlayerState::Down:
//			AbilityStateName_ = "Beam";
//			StateName_ = "Down";
//			StartDown();
//			break;
//		case PlayerState::Walk:
//			AbilityStateName_ = "Beam";
//			StateName_ = "Walk";
//			StartWalk();
//			break;
//		case PlayerState::JumpUp:
//			AbilityStateName_ = "Beam";
//			StateName_ = "JumpUp";
//			JumpDir_ = float4::UP * 700.0f;
//			StartJumpUp();
//			break;
//		case PlayerState::JumpDown:
//			AbilityStateName_ = "Beam";
//			StateName_ = "JumpDown";
//			StartJumpDown();
//			break;
//		case PlayerState::Fly:
//			FlyDir_ = float4::UP * 400.0f;
//			AbilityStateName_ = "Beam";
//			StateName_ = "Fly";
//			StartFly();
//			break;
//		case PlayerState::FlyEnd:
//			AbilityStateName_ = "Beam";
//			StateName_ = "FlyEnd";
//			StartFlyEnd();
//			break;
//		case PlayerState::Attack:
//			AbilityStateName_ = "Beam";
//			StateName_ = "Attack";
//			StartAttack();
//			break;
//		default:
//			break;
//		}
//		break;
//	case KirbyAbilityState::Cutter:
//		switch (stateType_)
//		{
//		case PlayerState::Stand:
//			AbilityStateName_ = "Cutter";
//			StateName_ = "Stand";
//			StartStand();
//			break;
//		case PlayerState::Down:
//			AbilityStateName_ = "Cutter";
//			StateName_ = "Down";
//			StartDown();
//			break;
//		case PlayerState::Walk:
//			AbilityStateName_ = "Cutter";
//			StateName_ = "Walk";
//			StartWalk();
//			break;
//		case PlayerState::JumpUp:
//			AbilityStateName_ = "Cutter";
//			StateName_ = "JumpUp";
//			JumpDir_ = float4::UP * 700.0f;
//			StartJumpUp();
//			break;
//		case PlayerState::JumpDown:
//			AbilityStateName_ = "Cutter";
//			StateName_ = "JumpDown";
//			StartJumpDown();
//			break;
//		case PlayerState::Fly:
//			FlyDir_ = float4::UP * 400.0f;
//			AbilityStateName_ = "Cutter";
//			StateName_ = "Fly";
//			StartFly();
//			break;
//		case PlayerState::FlyEnd:
//			AbilityStateName_ = "Cutter";
//			StateName_ = "FlyEnd";
//			StartFlyEnd();
//			break;
//		case PlayerState::Attack:
//			AbilityStateName_ = "Cutter";
//			StateName_ = "Attack";
//			StartAttack();
//			break;
//		default:
//			break;
//		}
//		break;
//	default:
//		break;
//	}
//
//
//
//}
//
//void Normal_Kirby::StartStand()
//{
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::DrainAfter:
//		DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//
//	//�ִϸ��̼� �̸��� �� �����̸�+ L or R �̹Ƿ�
//	//���� ���ʻ��¸� L���� �ִϸ��̼���,
//	//������ ���¸� R���� �ִϸ��̼��� ������ ���̴�
//
//}
//
//void Normal_Kirby::StartDown()
//{
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::DrainAfter:
//		DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//}
//
//void Normal_Kirby::StartWalk()
//{
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::DrainAfter:
//		DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//}
//
//
//
//void Normal_Kirby::StartDrainReady()
//{
//
//	MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//}
//
//void Normal_Kirby::StartDrainING()
//{
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//	MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//	DrainEffectRender_->ChangeAnimation("DrainAfterDrainEffect" + GetDirString());
//
//}
//
//void Normal_Kirby::StartJumpUp()
//{
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::DrainAfter:
//		DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//}
//
//void Normal_Kirby::StartJumpDown()
//{
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::DrainAfter:
//		DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//}
//
//void Normal_Kirby::StartDamageUp()
//{
//	HP -= 1;
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//
//	//�������� ������ ������ �븻���·� ���ƿ�
//	MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//
//	EatEffectRender_->ChangeAnimation("EatEffect", true);
//}
//
//void Normal_Kirby::StartDamageDown()
//{
//
//	MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//}
//
//void Normal_Kirby::StartFly()
//{
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//
//}
//
//void Normal_Kirby::StartFlyEnd()
//{
//	MakeBreath();
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//
//}
//
//void Normal_Kirby::StartAttack()
//{
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::DrainAfter:
//		DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		BeamEffectRender_->ChangeAnimation("BeamAttackEffect" + GetDirString(), true);
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//		break;
//	default:
//		break;
//	}
//}
//
//void Normal_Kirby::StartEat()
//{
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//
//	DrainAfterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString());
//
//	if (HoldingAbilityStarType_ != KirbyAbilityState::Normal)
//	{
//		EatEffectRender_->ChangeAnimation("EatEffect", true);
//
//	}
//
//}
//
//void Normal_Kirby::StartDead()
//{
//
//	EffectPlayer->PlayCountReset(1);
//
//
//	MainRender_->ChangeAnimation("NormalDead");
//
//
//
//}
//
//void Normal_Kirby::StartDanceReady()
//{
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//}
//
//void Normal_Kirby::StartDance()
//{
//	DamageTime = 2.0f;
//	EffectPlayer->Stop();
//	EffectPlayer->PlayCountReset(1);
//	DanceRender_->ChangeAnimation("KirbyDanceWait");
//}
//
//void Normal_Kirby::Update(float _Delta)
//{
//	if (DebugState_ == DebugMode::DEBUGMODE && GameEngineInput::IsDown("ChangeDebugMode"))
//	{
//		DebugState_ = DebugMode::PLAYMODE;
//	}
//	else if (DebugState_ == DebugMode::PLAYMODE && GameEngineInput::IsDown("ChangeDebugMode"))
//	{
//		DebugState_ = DebugMode::DEBUGMODE;
//	}
//
//
//	switch (dirstate_)
//	{
//	case DirectionState::LEFT:
//	{
//		DrainAttackCollision->SetPivot(PlayerPivot_ + float4::LEFT * 100);
//		DrainCheckCollision->SetPivot(PlayerPivot_ + float4::LEFT * 30);
//		BeamAttackCollision->SetPivot(PlayerPivot_ + float4::LEFT * 100);
//		DrainEffectRender_->SetPivotPos(PlayerPivot_ + float4::LEFT * 100 + float4::DOWN * 60);
//		//��� �̹����� ��ġ�� �¿� 100 + �Ʒ��� 60
//		BeamEffectRender_->SetPivotPos(PlayerPivot_);
//	}
//	break;
//	case DirectionState::RIGHT:
//	{
//		DrainAttackCollision->SetPivot(PlayerPivot_ + float4::RIGHT * 100);
//		DrainCheckCollision->SetPivot(PlayerPivot_ + float4::RIGHT * 30);
//		BeamAttackCollision->SetPivot(PlayerPivot_ + float4::RIGHT * 100);
//		DrainEffectRender_->SetPivotPos(PlayerPivot_ + float4::RIGHT * 100 + float4::DOWN * 60);
//		BeamEffectRender_->SetPivotPos(PlayerPivot_ + float4::RIGHT * 120);
//	}
//	break;
//	default:
//		break;
//	}
//
//
//	switch (stateType_)
//	{
//	case PlayerState::Stand:
//		Stand();
//		break;
//	case PlayerState::Down:
//		Down();
//		break;
//	case PlayerState::Walk:
//		Walk();
//		break;
//	case PlayerState::DrainReady:
//		DrainReady();
//		break;
//	case PlayerState::DrainING:
//		DrainING();
//		break;
//	case PlayerState::JumpUp:
//		JumpUp();
//		break;
//	case PlayerState::JumpDown:
//		JumpDown();
//		break;
//	case PlayerState::DamageUp:
//		DamageUp();
//		break;
//	case PlayerState::DamageDown:
//		DamageDown();
//		break;
//	case PlayerState::Fly:
//		Fly();
//		break;
//	case PlayerState::FlyEnd:
//		FlyEnd();
//		break;
//	case PlayerState::Attack:
//		Attack();
//		break;
//	case PlayerState::Eat:
//		Eat();
//		break;
//	case PlayerState::Dead:
//		Dead();
//		break;
//	case PlayerState::DanceReady:
//		DanceReady();
//		break;
//	case PlayerState::Dance:
//		Dance();
//		break;
//	default:
//		break;
//	}
//
//
//
//	//�� ��ü�� ��ġ�� �޾ƿ��°����� ī�޶��� ��ġ�� ����
//	GetLevel()->SetCamPos({ (GetPos() - GameEngineWindow:GetInst().GetSize().halffloat4()).x, 0 });
//
//	//�����̵��� �ص� ī�޶��� y���� �ȹٲ�� ����
//	if (0 > GetLevel()->GetCamPos().x)
//	{
//		//ī�޶� ���� ��ǥ�̸�, 0,0�� ī�޶� ����
//		GetLevel()->SetCamPos({ 0,0 });
//	}
//
//	if ((BackGroundSizeforCamX - GameEngineWindow::GetInst().GetSize().x) < GetLevel()->GetCamPos().x)
//	{
//		//ī�޶� ��ǥ�� ��� �̹���ũ�� - ȭ��ũ�⸦ �Ѿ�ٸ� ī�޶� ����
//		//��� �̹��� ���� -> 3172
//
//		GetLevel()->SetCamPos(
//			{
//				(BackGroundSizeforCamX - GameEngineWindow::GetInst().GetSize().x), 0
//			}
//		);
//	}
//
//
//}
//
//void Normal_Kirby::Stand()
//{
//	MonsterCollisionCheck();
//	LeftRightCheck();
//	MonsterAttackCollisionCheck();
//	DoorCollisionCheck();
//
//	if (true == GameEngineInput::IsDown("BeamChange"))
//	{
//		ChangeState(KirbyAbilityState::Beam, PlayerState::Stand);
//	}
//
//	if (true == GameEngineInput::IsDown("CutterChange"))
//	{
//		ChangeState(KirbyAbilityState::Cutter, PlayerState::Stand);
//	}
//
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		//�޹����� �浹�� false���
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Down);
//			break;
//		case KirbyAbilityState::DrainAfter:
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Down);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Down);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Down);
//			break;
//		default:
//			break;
//		}
//	}
//
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//	{
//
//		if (true == GameEngineInput::IsPress('R')
//			|| true == GameEngineInput::IsPress("L"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Walk);
//		}
//
//		if (true == GameEngineInput::IsPress("Att"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::DrainReady);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::JumpUp);
//		}
//	}
//	break;
//	case KirbyAbilityState::DrainAfter:
//	{
//		if (true == GameEngineInput::IsDown("BackToNormal"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//		}
//
//
//		if (true == GameEngineInput::IsPress("R") || true == GameEngineInput::IsPress("L"))
//		{
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Walk);
//		}
//
//		if (true == GameEngineInput::GetInst().IsDown("Att"))
//		{
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Attack);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::JumpUp);
//		}
//
//		if (true == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision)) //���ٴڿ� ���������
//		{
//			if (true == GameEngineInput::IsDown("D"))
//			{
//				ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Eat);
//			}
//		}
//	}
//	break;
//	case KirbyAbilityState::Beam:
//	{
//		if (true == GameEngineInput::IsDown("BackToNormal"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//		}
//
//
//		if (true == GameEngineInput::IsPress("R")
//			|| true == GameEngineInput::IsPress("L"))
//		{
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Walk);
//		}
//
//		if (true == GameEngineInput::IsDown("Att"))
//		{
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Attack);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			ChangeState(KirbyAbilityState::Beam, PlayerState::JumpUp);
//		}
//	}
//	break;
//	break;
//	case KirbyAbilityState::Cutter:
//	{
//		if (true == GameEngineInput::IsDown("BackToNormal"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//		}
//
//
//		if (true == GameEngineInput::IsPress("R")
//			|| true == GameEngineInput::IsPress("L"))
//		{
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Walk);
//		}
//
//		if (true == GameEngineInput::IsDown("Att"))
//		{
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Attack);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::JumpUp);
//		}
//	}
//	break;
//	default:
//		break;
//	}
//
//}
//
//void Normal_Kirby::Down()
//{
//	LeftRightCheck();
//	MonsterCollisionCheck();
//	MonsterAttackCollisionCheck();
//
//	if (false == RightGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("R"))
//		{
//			SetMove(float4::RIGHT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//	if (false == LeftGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("L"))
//		{
//			SetMove(float4::LEFT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//
//	if (true == GameEngineInput::IsDown("Att"))
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::DrainReady);
//			break;
//		case KirbyAbilityState::DrainAfter:
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Attack);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Attack);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Attack);
//			break;
//		default:
//			break;
//		}
//
//	}
//
//	if (true == GameEngineInput::IsDown("Jump"))
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Fly);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Fly);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Fly);
//			break;
//		default:
//			break;
//		}
//	}
//
//
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//	}
//	else
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//			break;
//		case KirbyAbilityState::DrainAfter:
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Stand);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Stand);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Stand);
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//
//void Normal_Kirby::Walk()
//{
//	LeftRightCheck();
//	MonsterCollisionCheck();
//	MonsterAttackCollisionCheck();
//	DoorCollisionCheck();
//
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Down);
//			break;
//		case KirbyAbilityState::DrainAfter:
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Down);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Down);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Down);
//			break;
//		default:
//			break;
//		}
//	}
//
//	if (false == RightGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("R"))
//		{
//			SetMove(float4::RIGHT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//	if (false == LeftGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("L"))
//		{
//			SetMove(float4::LEFT * GameEngineTime::GetInst().GH_GetDeltaTime() * Speed);
//		}
//	}
//
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//	{
//		if (false == GameEngineInput::IsPress("R")
//			&& false == GameEngineInput::IsPress("L"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//		}
//
//		if (true == GameEngineInput::IsDown("Att"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::DrainReady);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::JumpUp);
//		}
//
//	}
//	break;
//	case KirbyAbilityState::DrainAfter:
//	{
//		if (false == GameEngineInput::IsPress("R")
//			&& false == GameEngineInput::IsPress("L"))
//		{
//			return ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Stand);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			return ChangeState(KirbyAbilityState::DrainAfter, PlayerState::JumpUp);
//		}
//
//		if (true == GameEngineInput::IsDown("Att"))
//		{
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Attack);
//		}
//
//		if (true == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision)) //���ٴڿ� ����������� �Ʒ�Ű�� ���� Eat���·� �� �� �մ�
//		{
//			if (true == GameEngineInput::IsDown("D"))
//			{
//				ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Eat);
//			}
//		}
//	}
//	break;
//	case KirbyAbilityState::Beam:
//	{
//		if (false == GameEngineInput::IsPress("R")
//			&& false == GameEngineInput::IsPress("L"))
//		{
//			return ChangeState(KirbyAbilityState::Beam, PlayerState::Stand);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			return ChangeState(KirbyAbilityState::Beam, PlayerState::JumpUp);
//		}
//
//		if (true == GameEngineInput::IsDown("Att"))
//		{
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Attack);
//		}
//	}
//	break;
//	case KirbyAbilityState::Cutter:
//	{
//		if (false == GameEngineInput::IsPress("R")
//			&& false == GameEngineInput::IsPress("L"))
//		{
//			return ChangeState(KirbyAbilityState::Cutter, PlayerState::Stand);
//		}
//
//		if (true == GameEngineInput::IsPress("Jump"))
//		{
//			return ChangeState(KirbyAbilityState::Cutter, PlayerState::JumpUp);
//		}
//
//		if (true == GameEngineInput::IsDown("Att"))
//		{
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Attack);
//		}
//	}
//	break;
//	default:
//		break;
//	}
//}
//
//
//
//void Normal_Kirby::DrainReady()
//{
//	LeftRightCheck();
//	MonsterCollisionCheck();
//	MonsterAttackCollisionCheck();
//
//
//
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		//�޹����� �浹�� false���
//		SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//	}
//
//	if (true == MainRender_->IsCurAnimationEnd())
//	{
//		return ChangeState(KirbyAbilityState::Normal, PlayerState::DrainING);
//	}
//}
//
//void Normal_Kirby::DrainING()
//{
//	//���� �浹üũ���� ChageState�ϸ鼭 �Ҹ��� �ٲ�Ƿ� �Ҹ��� ������ �� ���� ��ġ�ؾ� �Ѵ�.
//	EffectPlayer->PlayAlone("KirbyDrain.wav", 0);
//	EffectPlayer->PlayCountReset(1);
//
//	DrainCollisionCheck();
//	MonsterCollisionCheck();
//	LeftRightCheck();
//	MonsterAttackCollisionCheck();
//
//
//
//	if (AbilityType_ == KirbyAbilityState::Normal)
//	{
//		DrainAttackCollision->SetSize({ 150,70 });
//	}
//	else
//	{
//		return;
//	}
//
//
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		//�޹����� �浹�� false���
//		SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//	}
//
//	if (false == GameEngineInput::IsPress("Att") && false == DrainMonsterActive)
//	{
//		EffectPlayer->Stop();
//		EffectPlayer->PlayCountReset(1);
//		DrainAttackCollision->SetSize({ 0,0 });
//		return ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//	}
//}
//
//void Normal_Kirby::JumpUp()
//{
//	EffectPlayer->PlayAlone("KirbyJump.wav", 0);
//	EffectPlayer->PlayCountReset(1);
//
//	LeftRightCheck();
//	MonsterCollisionCheck();
//	MonsterAttackCollisionCheck();
//
//	if (true == GameEngineInput::IsDown("Jump"))
//	{
//
//
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Fly);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Fly);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Fly);
//			break;
//		default:
//			break;
//		}
//	}
//
//	if (false == RightGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("R"))
//		{
//			SetMove(float4::RIGHT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//	if (false == LeftGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("L"))
//		{
//			SetMove(float4::LEFT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//	if (true == GameEngineInput::IsDown("Att"))
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::DrainReady);
//			break;
//		case KirbyAbilityState::DrainAfter:
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Attack);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Attack);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Attack);
//			break;
//		default:
//			break;
//		}
//
//	}
//
//
//
//	if (0 >= JumpDir_.Y)//�������� ����������
//	{
//		JumpDir_ += float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * 1500.0f;
//		if (false == TopGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//		{
//			SetMove(JumpDir_ * GameEngineTime::GetInst().GetDeltaTime());
//		}
//
//
//		if (0 < JumpDir_.Y)//������ ���� ���� ���� �����ϸ�
//		{
//
//			switch (AbilityType_)
//			{
//			case KirbyAbilityState::Normal:
//				ChangeState(KirbyAbilityState::Normal, PlayerState::JumpDown);
//				break;
//			case KirbyAbilityState::DrainAfter:
//				ChangeState(KirbyAbilityState::DrainAfter, PlayerState::JumpDown);
//				break;
//			case KirbyAbilityState::Beam:
//				ChangeState(KirbyAbilityState::Beam, PlayerState::JumpDown);
//				break;
//			case KirbyAbilityState::Cutter:
//				ChangeState(KirbyAbilityState::Cutter, PlayerState::JumpDown);
//				break;
//			default:
//				break;
//			}
//		}
//		return;
//	}
//
//
//}
//
//void Normal_Kirby::JumpDown()
//{
//	LeftRightCheck();
//	MonsterCollisionCheck();
//	MonsterAttackCollisionCheck();
//
//
//	if (false == RightGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::GIsPress("R"))
//		{
//			SetMove(float4::RIGHT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//	if (false == LeftGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("L"))
//		{
//			SetMove(float4::LEFT * GameEngineTime::GetInst().GH_GetDeltaTime() * Speed);
//		}
//	}
//
//
//
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		//�޹����� �浹�� false���
//		SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//	}
//
//
//	if (true == GameEngineInput::IsDown("Jump"))
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Fly);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Fly);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Fly);
//			break;
//		default:
//			break;
//		}
//	}
//
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		if (MainRender_->IsCurAnimationEnd())
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Down);
//		}
//		break;
//	case KirbyAbilityState::DrainAfter:
//		if (DrainAfterRender_->IsCurAnimationEnd())
//		{
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Down);
//		}
//		break;
//	case KirbyAbilityState::Beam:
//		if (BeamRender_->IsCurAnimationEnd())
//		{
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Down);
//		}
//		break;
//	case KirbyAbilityState::Cutter:
//		if (CutterRender_->IsCurAnimationEnd())
//		{
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Down);
//		}
//		break;
//	default:
//		break;
//	}
//
//
//	if (true == GameEngineInput::IsDown("Att"))
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::DrainReady);
//			break;
//		case KirbyAbilityState::DrainAfter:
//			ChangeState(KirbyAbilityState::DrainAfter, PlayerState::Attack);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Attack);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Attack);
//			break;
//		default:
//			break;
//		}
//
//	}
//
//
//}
//
//
//void Normal_Kirby::DamageUp()
//{
//	EffectPlayer->PlayAlone("KirbyDamage.wav", 0);
//	if (0 >= HP)
//	{
//		ChangeState(KirbyAbilityState::Normal, PlayerState::Dead);
//		return;
//	}
//
//
//	BodyCheckCollision->SetSize({ 0,0 });
//	DrainAttackCollision->SetSize({ 0,0 });
//	DrainCheckCollision->SetCollisionScale({ 0,0 });
//
//	float4 RightHit = { -1,-1 };
//	float4 LeftHit = { 1, -1 };
//	DamageTime -= GameEngineTime::GetInst().GetDeltaTime();
//
//	if (dirstate_ == DirectionState::RIGHT)
//	{
//		SetMove(RightHit * GameEngineTime::GetInst().GetDeltaTime() * 60.0f);
//	}
//	else
//	{
//		SetMove(LeftHit * GameEngineTime::GetInst().GetDeltaTime() * 60.0f);
//	}
//
//	if (0 >= DamageTime)
//	{
//		//�������� ������ ������ �븻���·� ���ư����Ѵ�
//		EffectPlayer->PlayCountReset(1);
//		DamageTime = 0.5f;
//		ChangeState(KirbyAbilityState::Normal, PlayerState::DamageDown);
//	}
//
//}
//
//void Normal_Kirby::DamageDown()
//{
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		//�޹����� �浹�� false���
//		SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//	}
//
//	if (MainRender_->IsCurAnimationEnd())
//	{
//		BodyCheckCollision->SetSize({ 75,70 });
//		ChangeState(KirbyAbilityState::Normal, PlayerState::Down);
//	}
//}
//
//void Normal_Kirby::Fly()
//{
//	EffectPlayer->PlayOverLap("KirbyFly.wav");
//
//	//�ö��� �ִϸ��̼��� �ٽ� �ݺ���Ű�� �ʹ�
//	LeftRightCheck();
//	MonsterCollisionCheck();
//	MonsterAttackCollisionCheck();
//
//	if (false == RightGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::IsPress("R"))
//		{
//			SetMove(float4::RIGHT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//	if (false == LeftGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		if (true == GameEngineInput::GetInst().GH_IsPress("L"))
//		{
//			SetMove(float4::LEFT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//
//	if (true == GameEngineInput::IsDown("Att"))
//	{
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::Normal:
//			ChangeState(KirbyAbilityState::Normal, PlayerState::FlyEnd);
//			break;
//		case KirbyAbilityState::Beam:
//			ChangeState(KirbyAbilityState::Beam, PlayerState::FlyEnd);
//			break;
//		case KirbyAbilityState::Cutter:
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::FlyEnd);
//			break;
//		default:
//			break;
//		}
//	}
//
//
//	if (0 >= FlyDir_.Y)//�������� ����������
//	{
//		//�������� �����ϰ� ���߱� ���ؼ� ���⿡�� ��ŸŸ���� ��������
//		FlyDir_ += float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * 1000.0f;
//
//
//		if (true == GameEngineInput::IsDown("Jump"))
//		{
//			EffectPlayer->PlayCountReset(1);
//			FlyDir_ = float4::UP * 400.0f;
//		}
//
//		if (false == TopGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//		{
//			SetMove(FlyDir_ * GameEngineTime::GetInst().GH_GetDeltaTime());
//		}
//
//
//	}
//
//	if (0 < FlyDir_.Y) //������ ���� ���� ���� �����ϸ�
//	{
//		if (true == GameEngineInput::GetInst().IsDown("Jump"))
//		{
//			EffectPlayer->PlayCountReset(1);
//
//			if (true == TopGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//			{
//				FlyDir_ = { 0,0 };
//			}
//			else if (false == TopGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//			{
//				switch (AbilityType_)
//				{
//				case KirbyAbilityState::Normal:
//					MainRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString(), true);
//					break;
//				case KirbyAbilityState::Beam:
//					BeamRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString(), true);
//					break;
//				case KirbyAbilityState::Cutter:
//					CutterRender_->ChangeAnimation(AbilityStateName_ + StateName_ + GetDirString(), true);
//					break;
//				default:
//					break;
//				}
//
//
//				FlyDir_ = float4::UP * 400.0f;
//			}
//		}
//
//
//		if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//		{
//			//�޹����� �浹�� false���
//			SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * 300.0f);
//		}
//		else
//		{
//			switch (AbilityType_)
//			{
//			case KirbyAbilityState::Normal:
//				ChangeState(KirbyAbilityState::Normal, PlayerState::FlyEnd);
//				break;
//			case KirbyAbilityState::Beam:
//				ChangeState(KirbyAbilityState::Beam, PlayerState::FlyEnd);
//				break;
//			case KirbyAbilityState::Cutter:
//				ChangeState(KirbyAbilityState::Cutter, PlayerState::FlyEnd);
//				break;
//			default:
//				break;
//			}
//
//		}
//	}
//}
//
//void Normal_Kirby::FlyEnd()
//{
//	EffectPlayer->PlayAlone("KirbyYawnAttack.wav");
//
//	MonsterCollisionCheck();
//	MonsterAttackCollisionCheck();
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//		if (MainRender_->IsCurAnimationEnd())
//		{
//			EffectPlayer->PlayCountReset(1);
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Down);
//
//		}
//		break;
//	case KirbyAbilityState::Beam:
//		if (BeamRender_->IsCurAnimationEnd())
//		{
//			EffectPlayer->PlayCountReset(1);
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Down);
//		}
//		break;
//	case KirbyAbilityState::Cutter:
//		if (CutterRender_->IsCurAnimationEnd())
//		{
//			EffectPlayer->PlayCountReset(1);
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Down);
//		}
//		break;
//	default:
//		break;
//	}
//
//
//}
//
//void Normal_Kirby::Attack()
//{
//	MonsterCollisionCheck();
//	BeamCollisionCheck();
//	MonsterAttackCollisionCheck();
//
//	if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//	{
//		//�޹����� �浹�� false���
//		SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//	}
//
//	if (false == ShootMoveActive && AbilityType_ != KirbyAbilityState::Beam) //�� ���¿����� bullet�� ������ �ʴ´�
//	{
//
//
//		//�Ѿ��� �߻��Ѵ�
//		Bullet* BulletPtr = Normal_Kirby::Actor::GetLevel()->CreateActor<Bullet>();
//
//		if (dirstate_ == DirectionState::LEFT)
//		{
//			BulletPtr->BulletDir_ = BulletDirectionState::LEFT;
//		}
//		else
//		{
//			BulletPtr->BulletDir_ = BulletDirectionState::RIGHT;
//		}
//
//		switch (AbilityType_)
//		{
//		case KirbyAbilityState::DrainAfter:
//			BulletPtr->ChangeState(BulletState::Star);
//			EffectPlayer->PlayAlone("KirbyStarShot.wav");
//			break;
//		case KirbyAbilityState::Cutter:
//			BulletPtr->ChangeState(BulletState::Cutter);
//			EffectPlayer->PlayAlone("KirbyCutterAttack.wav");
//			break;
//		default:
//			break;
//		}
//
//		BulletPtr->GH_SetPos(GH_GetPos());
//		//Ŀ�� ��ġ�� �������� �Ѿ��� ����
//
//		ShootMoveActive = true;
//	}
//
//	if (ShootMoveActive == false && AbilityType_ == KirbyAbilityState::Beam)
//	{
//		//�������϶��� ����
//		BeamAttackCollision->SetSize({ 200,100 });
//		EffectPlayer->PlayOverLap("KirbyBeamAttack.wav", 0);
//
//		ShootMoveActive = true;
//	}
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::DrainAfter:
//		if (DrainAfterRender_->IsCurAnimationEnd())
//		{
//			EffectPlayer->PlayCountReset(1);
//			ShootMoveActive = false;
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//		}
//		break;
//	case KirbyAbilityState::Beam:
//		if (BeamRender_->IsCurAnimationEnd())
//		{
//			EffectPlayer->PlayCountReset(1);
//			ShootMoveActive = false;
//			BeamAttackCollision->GH_SetSize({ 0,0 });
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Stand);
//		}
//		break;
//	case KirbyAbilityState::Cutter:
//		if (CutterRender_->IsCurAnimationEnd())
//		{
//			EffectPlayer->PlayCountReset(1);
//			ShootMoveActive = false;
//			ChangeState(GH_KirbyAbilityState::Cutter, PlayerState::Stand);
//		}
//		break;
//	default:
//		break;
//	}
//}
//
//void Normal_Kirby::Eat()
//{
//
//
//	switch (HoldingAbilityStarType_)
//	{
//	case KirbyAbilityState::Normal:
//	{
//		EffectPlayer->PlayOverLap("KirbyDrainEat.wav", 0);
//		if (true == DrainAfterRender_->IsCurAnimationEnd())
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Stand);
//			EffectPlayer->PlayCountReset(1);
//		}
//	}
//	break;
//	case KirbyAbilityState::Beam:
//	{
//
//		EffectPlayer->PlayOverLap("KirbyDrainChange.wav", 0);
//		if (true == DrainAfterRender_->IsCurAnimationEnd())
//		{
//			ChangeState(KirbyAbilityState::Beam, PlayerState::Stand);
//			EffectPlayer->PlayCountReset(1);
//		}
//	}
//	break;
//	case KirbyAbilityState::Cutter:
//	{
//		EffectPlayer->PlayOverLap("KirbyDrainChange.wav", 0);
//		if (true == DrainAfterRender_->IsCurAnimationEnd())
//		{
//			ChangeState(KirbyAbilityState::Cutter, PlayerState::Stand);
//			EffectPlayer->PlayCountReset(1);
//		}
//	}
//	break;
//	default:
//		break;
//	}
//
//
//}
//
//void Normal_Kirby::Dead()
//{
//	Stage_one_one::StagePtr->BackgroundPlayer->Stop();
//
//	DamageTime -= GameEngineTime::GetInst().GetDeltaTime();
//
//	if (DamageTime < 0)
//	{
//
//		EffectPlayer->PlayAlone("Die.wav");
//		;
//		MainRender_->ChangeAnimation("NormalSpin");
//		JumpDir_ += float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * 2000.0f;
//		SetMove(JumpDir_ * GameEngineTime::GetInst().GetDeltaTime());
//
//		if (false == EffectPlayer->IsPlay() && true == GameEngineInput::IsDown("Jump"))
//		{
//			GetLevel()->StageRestart();
//		}
//	}
//
//}
//
//void Normal_Kirby::DanceReady()
//{
//	int KirbyPosX = GetPos().iX();
//	int DancePosX = GameEngineWindow::GetInst().GetSize().halffloat4().iX() - 100;
//
//	if (KirbyPosX != DancePosX)
//	{
//		if ((KirbyPosX - DancePosX) < 0)
//		{
//			MainRender_->ChangeAnimation("NormalWalkR");
//			SetMove(float4::RIGHT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//		else
//		{
//			MainRender_->ChangeAnimation("NormalWalkL");
//			SetMove(float4::LEFT * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//	}
//	else
//	{
//		if (false == MiddleGroundCheckCollision->CollisionCheck(One_One_Back::MapCollision))
//		{
//			MainRender_->ChangeAnimation("NormalJumpDownR");
//			SetMove(float4::DOWN * GameEngineTime::GetInst().GetDeltaTime() * Speed);
//		}
//		else
//		{
//			ChangeState(KirbyAbilityState::Normal, PlayerState::Dance);
//		}
//
//	}
//
//}
//
//
//void Normal_Kirby::Dance()
//{
//
//	DamageTime -= GameEngineTime::GetInst().GetDeltaTime();
//
//	if (DamageTime <= 0)
//	{
//		EffectPlayer->PlayAlone("KirbyDance.wav");
//
//
//		if (DanceRender_->IsCurAnimationEnd() && true == DanceRender_->IsOn())
//		{
//			if (true == DanceRender_->IsCurAnimationName("KirbyDanceWait"))
//			{
//				DanceRender_->ChangeAnimation("KirbyDance");
//				DanceRendertwo_->Off();
//				//DanceRendertwo_->GH_ChangeAnimation("KirbyDanceWaittwo");
//				DanceRenderthree_->Off();
//				//DanceRenderthree_->GH_ChangeAnimation("KirbyDanceWaitthree");
//
//			}
//			else
//			{
//				DanceRender_->Off();
//				DanceRendertwo_->On();
//				//DanceRendertwo_->GH_ChangeAnimation("KirbyDanceWaittwo");
//				DanceRenderthree_->Off();
//
//			}
//		}
//
//		if (DanceRendertwo_->IsCurAnimationEnd() && true == DanceRendertwo_->IsOn())
//		{
//			if (true == DanceRendertwo_->IsCurAnimationName("KirbyDanceWaittwo"))
//			{
//				//DanceRender_->GH_ChangeAnimation("KirbyDanceWait");
//				DanceRender_->Off();
//				DanceRendertwo_->ChangeAnimation("KirbyDancetwo");
//				//DanceRenderthree_->GH_ChangeAnimation("KirbyDanceWaitthree");
//				DanceRenderthree_->Off();
//
//			}
//			else
//			{
//				DanceRender_->Off();
//				DanceRendertwo_->Off();
//				DanceRenderthree_->On();
//				//DanceRenderthree_->GH_ChangeAnimation("KirbyDanceWaitthree");
//			}
//		}
//
//
//		if (DanceRenderthree_->IsCurAnimationEnd() && true == DanceRenderthree_->IsOn())
//		{
//			if (true == DanceRenderthree_->IsCurAnimationName("KirbyDanceWaitthree"))
//			{
//				DanceRender_->Off();
//				DanceRendertwo_->Off();
//				DanceRenderthree_->ChangeAnimation("KirbyDancethree");
//			}
//		}
//
//
//
//		if ((false == EffectPlayer->IsPlay()) && (true == GameEngineInput::IsDown("Jump")))
//		{
//			Stage_one_one::StagePtr->ChangeStage();
//			LevelManager::GetInst().ChangeLevel("EndLevel");
//		}
//	}
//}
//
//void Normal_Kirby::Render(float _Delta)
//{
//	if (DebugState_ == DebugMode::DEBUGMODE)
//	{
//		MiddleGroundCheckCollision->DebugRender();
//		LeftGroundCheckCollision->DebugRender();
//		RightGroundCheckCollision->DebugRender();
//		TopGroundCheckCollision->DebugRender();
//		BodyCheckCollision->DebugRender();
//		DrainAttackCollision->DebugRender();
//		DrainCheckCollision->DebugRender();
//		BeamAttackCollision->DebugRender();
//	}
//
//
//	switch (AbilityType_)
//	{
//	case KirbyAbilityState::Normal:
//	{
//
//		if (stateType_ != PlayerState::Dance)
//		{
//			MainRender_->AnimationUpdate();
//
//		}
//		else if (stateType_ == PlayerState::Dance)
//		{
//			if (DanceRender_->IsOn())
//			{
//				DanceRender_->AnimationUpdate();
//			}
//
//			if (DanceRendertwo_->IsOn())
//			{
//				DanceRendertwo_->AnimationUpdate();
//			}
//
//			if (DanceRenderthree_->IsOn())
//			{
//				DanceRenderthree_->AnimationUpdate();
//			}
//		}
//
//
//		if (stateType_ == PlayerState::DrainING)
//		{
//			DrainEffectRender_->AnimationUpdate();
//		}
//
//		if (stateType_ == PlayerState::DamageUp)
//		{
//			EatEffectRender_->AnimationUpdate();
//		}
//	}
//	break;
//	case KirbyAbilityState::DrainAfter:
//		DrainAfterRender_->AnimationUpdate();
//		if (stateType_ == PlayerState::Eat && HoldingAbilityStarType_ != KirbyAbilityState::Normal)
//		{
//			EatEffectRender_->AnimationUpdate();
//		}
//
//		break;
//	case KirbyAbilityState::Beam:
//		BeamRender_->AnimationUpdate();
//		if (stateType_ == PlayerState::Attack)
//		{
//			BeamEffectRender_->AnimationUpdate();
//		}
//		break;
//	case KirbyAbilityState::Cutter:
//		CutterRender_->AnimationUpdate();
//		break;
//	default:
//		break;
//	}
//
//}
//
