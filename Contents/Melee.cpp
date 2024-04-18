#include "PreCompile.h"
#include "Melee.h"
#include "Player.h"

EActorDir AMelee::PlayerDir = EActorDir::None;;

AMelee::AMelee()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::MAX);

	SetRoot(Root);

}

AMelee::~AMelee()
{
}

void AMelee::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("KiaraAttack", "KiaraAttack", 0.1f);
	Renderer->SetAutoSize(1.5f, true);
	Renderer->ChangeAnimation("KiaraAttack");
	Renderer->SetOrder(ERenderOrder::Attack);

}

void AMelee::MeleeAttack(float _DeltaTime)
{
	if (1.0f <= AttackTime)
	{
		AttackTime = 0.0f;
	}

	AttackTime += _DeltaTime;
}



void AMelee::AttackDir()
{
	if (PlayerDir == EActorDir::E)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X + 100 , APlayer::PlayerPos.Y + 20 });
		SetActorRotation(FVector{ 0.0f,0.0f,0.0f });
	}
	else if (PlayerDir == EActorDir::N)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y + 100 });
		SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
	}
	else if (PlayerDir == EActorDir::S)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y - 30 });
		SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
	}
	else if (PlayerDir == EActorDir::W)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X - 100, APlayer::PlayerPos.Y + 20 });
		SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
	}
	else if (PlayerDir == EActorDir::NE)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X + 100, APlayer::PlayerPos.Y + 70 });
		SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
	}
	else if (PlayerDir == EActorDir::NW)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X - 100, APlayer::PlayerPos.Y + 70 });
		SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
	}
	else if (PlayerDir == EActorDir::SE)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X + 100, APlayer::PlayerPos.Y - 30 });
		SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
	}
	else if (PlayerDir == EActorDir::SW)
	{
		SetActorLocation(FVector{ APlayer::PlayerPos.X - 100, APlayer::PlayerPos.Y - 30 });
		SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
	}

}

void AMelee::AttackAimDir()
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

	//애니메이션이 끝나고 다음 이 나가야한다.
}


void AMelee::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MeleeAttack(_DeltaTime);
	if (false == AMouse::MouseCursorON)
	{
		AttackDir();
	}
	else
	{
		AttackAimDir();
	}

	CursorOFF();
}

void AMelee::CursorOFF()
{
	ShowCursor(FALSE);
}
