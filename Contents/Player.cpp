#include "PreCompile.h"
#include "Player.h"
#include "Mouse.h"
#include "Ranged.h"
#include "Melee.h"
#include "Multishot.h"


FVector APlayer::PlayerPos = FVector::Zero;



APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	PlayerCursor = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	PlayerCursor->SetupAttachment(Root);
	PlayerCursor->SetPivot(EPivot::MAX);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);

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
	UEngineSerializer Ser;

	Ser << this;

	Super::BeginPlay();

	CreatePlayerAnimation("Ame");
	CreatePlayerAnimation("Aqua");
	CreatePlayerAnimation("Ayame");
	CreatePlayerAnimation("AZKiPortrait");
	CreatePlayerAnimation("Bae");
	CreatePlayerAnimation("Calli");
	CreatePlayerAnimation("Suisei");
	CreatePlayerAnimation("Kiara");
	
	
	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	

	PlayerCursor->SetSprite("spr_arrow_1.png");
	PlayerCursor->SetAutoSize(1.0f, true);
	PlayerCursor->SetOrder(ERenderOrder::Player);

	FVector PCursor = FVector{ PlayerPos.X, PlayerPos.Y + 20.0f };
	PlayerCursor->SetPosition(PCursor);

	// 공격 스폰
	//Melee = GetWorld()->SpawnActor<AMelee>("Melee");
	//Melee->SetActorLocation(GetActorLocation());



	StateInit();
}

void APlayer::CreatePlayerAnimation(std::string _Name)
{
	Renderer->CreateAnimation(_Name + "_Idle", _Name, 0.1f, true, 0, 3);
	Renderer->CreateAnimation(_Name + "_Run", _Name, 0.1f, true, 4, 9);
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

void APlayer::SpawnRanged(float _DeltaTime)
{
	if (1.0f <= AttackTime)
	{
		Ranged = GetWorld()->SpawnActor<ARanged>("Ranged");
		Ranged->SetActorLocation(GetActorLocation());
		AttackTime = 0.0f;
	}
	AttackTime += _DeltaTime;
}

void APlayer::PCursorDirCheck()
{
	EActorDir InputDir = EActorDir::None;
	// 처음들어올때
	if (true == IsDown('W'))
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,90.0f });
		InputDir = EActorDir::N;
	}
	if (true == IsDown('S'))
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,270.0f });
		InputDir = EActorDir::S;
	}
	if (true == IsDown('A'))
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,180.0f });
		InputDir = EActorDir::W;
	}
	if (true == IsDown('D'))
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,0.0f });
		InputDir = EActorDir::E;
	}

	// 두 같이 방향일때
	if (DirState == EActorDir::NE)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,45.0f });
		InputDir = EActorDir::E;
	}

	if (DirState == EActorDir::SE)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,315.0f });
		InputDir = EActorDir::E;
	}

	if (DirState == EActorDir::SW)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,225.0f });
		InputDir = EActorDir::W;
	}

	if (DirState == EActorDir::NW)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,135.0f });
		InputDir = EActorDir::W;
	}

	// 한뱡향일때
	if (DirState == EActorDir::N)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,90.0f });
	}

	if (DirState == EActorDir::S)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,270.0f });
	}

	if (DirState == EActorDir::W)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,180.0f });
	}

	if (DirState == EActorDir::E)
	{
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,0.0f });
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



void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	Melee->AMelee::PlayerDir = GetPlayerDir();

	State.Update(_DeltaTime);

	PlayerPos = GetActorLocation();

	PCursorDirCheck();
	CursorDirChange();
	ChangeMouseAimAtkDir();
	SpawnRanged(_DeltaTime);
	
	int a = 0;

	Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			_Collison->GetActor()->Destroy();
		}
	);



}
