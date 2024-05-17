#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineMath.h>
#include "Mouse.h"
#include "Weapon.h"
#include "Kiara.h"
#include "Wamy.h"
#include "Asacoco.h"
#include "FanBeam.h"
#include "CuttingBoard.h"

float4 APlayer::PlayerColPos = float4::Zero;
float4 APlayer::PlayerPos = float4::Zero;
bool APlayer::IsLevelUp = false;

APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	Shadow = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Shadow->SetupAttachment(Root);
	Shadow->SetPivot(EPivot::BOT);

	PlayerCursor = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	PlayerCursor->SetupAttachment(Root);
	PlayerCursor->SetPivot(EPivot::MAX);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale({ 65.0f,65.f });
	Collision->SetPosition({ 0.0f,35.0f });
	Collision->SetCollisionGroup(ECollisionOrder::Player);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);

	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{

	Super::BeginPlay();

	CreatePlayerAnimation("Ame");
	CreatePlayerAnimation("Kiara");
	
	
	Renderer->SetAutoSize(ContentsValue::MultipleSize, true);
	Renderer->SetOrder(ERenderOrder::Player);
	
	Shadow->SetSprite("Shadow_0.png");
	Shadow->SetAutoSize(ContentsValue::MultipleSize, true);
	Shadow->SetOrder(ERenderOrder::Shadow);
	Shadow->SetMulColor({ 1.f,1.f,1.f,0.7f });

	Collision->SetPosition({ GetActorLocation().X, GetActorLocation().Y + (10.0f * ContentsValue::MultipleSize) });


	PlayerCursor->SetSprite("spr_arrow_1.png");
	PlayerCursor->SetAutoSize(1.0f, true);
	PlayerCursor->SetOrder(ERenderOrder::Mouse);
	PlayerCursor->SetPosition(FVector{ PlayerPos.X, PlayerPos.Y + (20.0f * ContentsValue::MultipleSize) });

	// 공격 스폰

	//AddWeapon<AKiara>("AKiara");
	//AddWeapon<AWamy>("AWamy");
	//AddWeapon<AAsacoco>("Asacoco");
	AddWeapon<AFanBeam>("FanBeam");
	
	StateInit();
}



void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);

	PlayerColPos = GetActorLocation();
	PlayerPos = float4{ PlayerColPos.X, PlayerColPos.Y + (20.0f * ContentsValue::MultipleSize) };
	
	CursorDirChange();
	PCursorDirCheck();
	ChangeMouseAimAtkDir();
	{
		for (VPlayerWeaponsIter = VPlayerWeapons.begin(); VPlayerWeaponsIter != VPlayerWeapons.end(); ++VPlayerWeaponsIter)
		{
			std::shared_ptr<AWeapon> Weapon = *VPlayerWeaponsIter;

			*VPlayerWeaponsIter = Weapon;
		}
	}

}

template<typename WeaponType>
void APlayer::AddWeapon(std::string _Name)
{
	std::shared_ptr<AWeapon> Weapon = GetWorld()->SpawnActor<WeaponType>(_Name);
	VPlayerWeapons.push_back(Weapon);
}


void APlayer::CreatePlayerAnimation(std::string _Name)
{
	Renderer->CreateAnimation(_Name + "_Idle", _Name, 0.1f, true, 0, 3);
	Renderer->CreateAnimation(_Name + "_Run", _Name, 0.1f, true, 4, 9);
}


void APlayer::CalStatus()
{
	AtkTime = roundf(1.0f / (1.0f + Haste));

	CalSpeed = ContentsValue::BaseSpeed * Speed;
	LineSpeed = CalSpeed * 0.75f;
}

void APlayer::CursorDirChange()
{
	if (false == AMouse::MouseCursorON)
	{
		PlayerCursor->SetSprite("spr_arrow_1.png");
		PlayerCursor->SetAutoSize(1.0f, true);
	}
	
	if (true == AMouse::MouseCursorON)
	{
	
		PlayerCursor->SetSprite("spr_arrow_2.png");
		PlayerCursor->SetAutoSize(1.0f, true);

	}
}

void APlayer::PCursorDirCheck()
{
	if (false == AMouse::MouseCursorON)
	{
		switch (PlayerDir)
		{
		case EActorDir::N:
			Angle = 90.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EActorDir::NE:
			Angle = 45.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EActorDir::E:
			Angle = 0.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EActorDir::SE:
			Angle = 315.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EActorDir::S:
			Angle = 270.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EActorDir::SW:
			Angle = 225.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EActorDir::W:
			Angle = 180.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		case EActorDir::NW:
			Angle = 135.0f;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });
			break;
		default:
			break;
		}
	}
}


void APlayer::ChangeMouseAimAtkDir()
{
	if (true == AMouse::MouseCursorON)
	{
		Angle = atan2f((ContentsValue::PlayLevelMousePos.Y - APlayer::PlayerPos.Y), (ContentsValue::PlayLevelMousePos.X - APlayer::PlayerPos.X)) * 180.0f / UEngineMath::PI;
		PlayerCursor->SetRotationDeg(FVector{ 0.0f, 0.0f, Angle });

		if (-90.0f <= Angle && 90.0f > Angle)
		{
			Renderer->SetDir(EEngineDir::Right);
		}
		else
		{
			Renderer->SetDir(EEngineDir::Left);
		}
	}
}


