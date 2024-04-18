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
	Renderer->SetPosition(APlayer::PlayerPos);
	Renderer->SetAutoSize(10.0f, true);
	//Renderer->ChangeAnimation("AmeAttack");
	Renderer->ChangeAnimation("AmeAttack");
	Renderer->SetOrder(ERenderOrder::Attack);
}

void ARanged::CreatePlayerAnimation(std::string _Name)
{
	//Renderer->CreateAnimation(_Name + "Attack", _Name + "Attack", 0.1f, true, 0, 3);
}



void ARanged::AttackDir()
{
	if (AMelee::PlayerDir == EActorDir::E)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y});
		SetActorRotation(FVector{ 0.0f,0.0f,0.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::N)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y});
		SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::S)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y});
		SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::W)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y });
		SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::NE)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y});
		SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::NW)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X , APlayer::PlayerPos.Y });
		SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::SE)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X , APlayer::PlayerPos.Y });
		SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
	}
	else if (AMelee::PlayerDir == EActorDir::SW)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y });
		SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
	}

}

void ARanged::AttackAimDir()
{
	FVector MPos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WorldMPos = GetWorld()->GetMainCamera()->ScreenPosToWorldPos(MPos);

	AttackAngle = atan2f((ContentsValue::PlayLevelMousePos.Y - APlayer::PlayerPos.Y), (ContentsValue::PlayLevelMousePos.X - APlayer::PlayerPos.X)) * 180.0f / UEngineMath::PI;

	FVector Dir = WorldMPos - APlayer::PlayerPos;
	Dir.Normalize2D();
	Dir.Z = 0.0f;
	SetActorLocation(APlayer::PlayerPos);
	AddActorLocation(Dir * 100);
	SetActorRotation(FVector{ 0.0f,0.0f, AttackAngle });

}

void ARanged::RangedMove(float _DeltaTime)
{
	AddActorLocation(FVector::Right * _DeltaTime * RangedSpeed);
}

void ARanged::RangedAttack(float _DeltaTime)
{
	if (1.0f <= AttackTime)
	{
		AttackTime = 0.0f;
	}

	AttackTime += _DeltaTime;

}



void ARanged::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RangedMove(_DeltaTime);

	if (false == AMouse::MouseCursorON)
	{
		AttackDir();
	}
	else
	{
		AttackAimDir();
		int a = 0;
	}
	CursorOFf();
}

void ARanged::CursorOFf()
{
	ShowCursor(FALSE);
}
