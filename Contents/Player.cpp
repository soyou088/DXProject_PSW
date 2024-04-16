#include "PreCompile.h"
#include "Player.h"
#include "Mouse.h"


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

	//Collision->SetCollisionGroup(ECollisionOrder::Player);
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

	CreatePlayerAnimation("Aqua");
	CreatePlayerAnimation("Ame");

	Renderer->SetOrder(ERenderOrder::Player);

	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");
	Mouse->SetActorLocation(PlayerPos);
	
	PlayerCursor->SetSprite("spr_arrow_1.png");
	PlayerCursor->SetAutoSize(1.0f, true);
	PlayerCursor->SetOrder(ERenderOrder::Player);

	FVector PCursor = FVector{ PlayerPos.X, PlayerPos.Y + 20 };
	PlayerCursor->SetPosition(PCursor);

	StateInit();
}

void APlayer::CreatePlayerAnimation(std::string _Name)
{
	Renderer->CreateAnimation(_Name + "_Idle", _Name, 0.1f, true, 0, 3);
	Renderer->CreateAnimation(_Name + "_Run", _Name, 0.1f, true, 4, 9);
}



void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);

	PlayerPos = GetActorLocation();
	MousePos = GEngine->EngineWindow.GetScreenMousePos();
	MouseCursor = PlayerPos + MousePos;
	FVector MouseLocation = FVector{ PlayerPos.X + MousePos.X - 640, PlayerPos.Y - MousePos.Y + 360 };

	Mouse->SetActorLocation(MouseLocation);


	//if (true == IsDown(VK_LBUTTON))
	//{
	//	PlayerCursor->AddPosition(float4{ 0.0f, 0.0f, 1.0f } *360.0f * _DeltaTime);
	//	Color.X += _DeltaTime;
	//}

	PCursorDirCheck();

	if (false == MouseState && true == IsDown(VK_LBUTTON))
	{
		PlayerCursor->SetSprite("spr_arrow_2.png");
		MouseState = true;
	}
	else if (true == MouseState && true == IsDown(VK_LBUTTON))
	{
		PlayerCursor->SetSprite("spr_arrow_1.png");
		MouseState = false;
	}

	int a = 0;

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





