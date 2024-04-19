#include "PreCompile.h"
#include "Ranged.h"
#include "Player.h"

ARanged::ARanged()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::MAX);

	SetRoot(Root);
}

ARanged::~ARanged()
{
}

void ARanged::BeginPlay()
{
	Super::BeginPlay();
	//CreatePlayerAnimation("Ame");
	Renderer->CreateAnimation("AmeAttack", "AmeAttack", 0.1f, true);
	Renderer->SetAutoSize(10.0f, true);
	Renderer->ChangeAnimation("AmeAttack");
	Renderer->SetOrder(ERenderOrder::Attack);



	//AttackDir();
	//FVector AttackRot = AttackDir();
	//AttackRot.Normalize2D();
	SetActorLocation(AttackDir());
}

void ARanged::CreatePlayerAnimation(std::string _Name)
{
	//Renderer->CreateAnimation(_Name + "Attack", _Name + "Attack", 0.1f, true, 0, 3);
}


void ARanged::AttackDirr(float _DeltaTime)
{
	if (AMelee::PlayerDir == EActorDir::E)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,0.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::N)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::S)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::W)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::NE)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::NW)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::SE)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::SW)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
	}
}


FVector ARanged::AttackDir()
{

	//SetActorRotation(FVector{ 0.0f,0.0f,0.0f }) = EActorDir::E;

	if (AMelee::PlayerDir == EActorDir::E)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,0.0f });
		AtkDir = { 1,0,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::N)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
		AtkDir = { 0,1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::S)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
		AtkDir = {0,-1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::W)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
		AtkDir = { -1,0,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::NE)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
		AtkDir = { 1,1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::NW)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
		AtkDir = { -1,1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::SE)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
		AtkDir = { 1,-1,0,0 };
	}
	else if (AMelee::PlayerDir == EActorDir::SW)
	{
		SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
		AtkDir = { -1,-1,0,0 };
	}
	AtkDir = AtkDir.Normalize3DReturn();
	return FVector::Zero;
}

void ARanged::AttackAimDir(float _DeltaTime)
{
	FVector MPos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WorldMPos = GetWorld()->GetMainCamera()->ScreenPosToWorldPos(MPos);

	AttackAngle = atan2f((ContentsValue::PlayLevelMousePos.Y - APlayer::PlayerPos.Y), (ContentsValue::PlayLevelMousePos.X - APlayer::PlayerPos.X)) * 180.0f / UEngineMath::PI;

	FVector Dir = WorldMPos - APlayer::PlayerPos;
	Dir.Normalize2D();
	Dir.Z = 0.0f;
	SetActorLocation(APlayer::PlayerPos);
	//AddActorLocation(Dir * 100);
	SetActorRotation(FVector{ 0.0f,0.0f, AttackAngle });
	AddActorLocation(Dir * _DeltaTime * RangedSpeed);
}

void ARanged::RangedMove(float _DeltaTime)
{
	if (AMelee::PlayerDir == EActorDir::E)
	{
		AddActorLocation(FVector::Right *_DeltaTime * RangedSpeed);
	}
	else if (AMelee::PlayerDir == EActorDir::N)
	{
		AddActorLocation(FVector::Up *_DeltaTime * RangedSpeed);
	}
	else if (AMelee::PlayerDir == EActorDir::S)
	{
		AddActorLocation(FVector::Down*_DeltaTime * RangedSpeed);
	}
	else if (AMelee::PlayerDir == EActorDir::W)
	{
		AddActorLocation(FVector::Left *_DeltaTime * RangedSpeed);
	}
	else if (AMelee::PlayerDir == EActorDir::NE)
	{
		//AddActorLocation(FVector::*_DeltaTime * RangedSpeed);
	}
	else if (AMelee::PlayerDir == EActorDir::NW)
	{
		//AddActorLocation(FVector{ 0.0f,0.0f,135.0f }*_DeltaTime * RangedSpeed);
	}
	else if (AMelee::PlayerDir == EActorDir::SE)
	{
		//AddActorLocation(FVector{ 0.0f,0.0f,315.0f }*_DeltaTime * RangedSpeed);
	}
	else if (AMelee::PlayerDir == EActorDir::SW)
	{
		//AddActorLocation(FVector{ 0.0f,0.0f,225.0f }*_DeltaTime * RangedSpeed);
	}

}

void ARanged::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AddActorLocation(AtkDir * 100 * _DeltaTime);
//	AttackDirr(_DeltaTime);
	//RangedMove(_DeltaTime);

	//CursorOFf();
}

void ARanged::CursorOFf()
{
	ShowCursor(FALSE);
}
