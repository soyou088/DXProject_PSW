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
	SetRoot(Root);

	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("KroniiIdle", "Kronii", 0.1f, true, 6, 9);
	Renderer->CreateAnimation("KroniiRun", "Kronii", 0.1f, true, 0, 3);
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Player);
	//Renderer->CreateAnimation("Die", "Die");
	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");

	Mouse->SetActorLocation(PlayerPos);

	PlayerCursor->CreateAnimation("pcursor", "spr_arrow_1.png", 0.1f, false);
	PlayerCursor->SetAutoSize(1.0f, true);
	PlayerCursor->ChangeAnimation("pcursor");

	PlayerCursor->CreateAnimation("pmcursor", "spr_arrow_2.png", 0.1f, false);
	PlayerCursor->SetAutoSize(1.0f, true);
	PlayerCursor->SetOrder(ERenderOrder::Player);


	FVector PCursor = FVector{ PlayerPos.X, PlayerPos.Y + 20 };

	PlayerCursor->SetPosition(PCursor);




	StateInit();
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


	if (true == IsDown(VK_LBUTTON))
	{
		PlayerCursor->AddPosition(float4{ 0.0f, 0.0f, 1.0f } *360.0f * _DeltaTime);
		Color.X += _DeltaTime;
	}

	DirCheck();
	int a = 0;

}

void APlayer::DirCheck()
{

	// 처음들어올때

	//if (DirState == EActorDir::Right)
	//{
	//	PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,0.0f });
	//}
	//if (DirState == EActorDir::Left)
	//{
	//	PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,180.0f });
	//}
	//if (DirState == EActorDir::Top)
	//{
	//	PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,90.0f });
	//}
	//if (DirState == EActorDir::Bottom)
	//{
	//	PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,270.0f });
	//}

	if (true == IsDown('W'))
	{
		DirState = EActorDir::Top;
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,90.0f });
	}
	if (true == IsDown('S'))
	{
		DirState = EActorDir::Bottom;
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,270.0f });
	}
	if (true == IsDown('A'))
	{
		DirState = EActorDir::Left;
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,180.0f });
	}
	if (true == IsDown('D'))
	{
		DirState = EActorDir::Right;
		PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,0.0f });
	}

	if (DirState == EActorDir::Right)
	{
		if (true == IsDown('W'))
		{
			DirState = EActorDir::Top;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,45.0f });
		}
		if (true == IsDown('S'))
		{
			DirState = EActorDir::Bottom;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,315.0f });
		}
		if (true == IsDown('A'))
		{
			return;
		}
	}

	if (DirState == EActorDir::Left)
	{
		if (true == IsDown('W'))
		{
			DirState = EActorDir::Top;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,135.0f });
		}
		if (true == IsDown('S'))
		{
			DirState = EActorDir::Bottom;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,225.0f });
		}
		if (true == IsDown('D'))
		{
			return;
		}
	}

	if (DirState == EActorDir::Bottom)
	{
		if (true == IsDown('D'))
		{
			EActorDir::Right;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,315.0f });
		}
		if (true == IsDown('A'))
		{
			EActorDir::Left;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,225.0f });
		}
		if (true == IsDown('W'))
		{
			return;
		}
	}

	if (DirState == EActorDir::Top)
	{
		if (true == IsDown('D'))
		{
			EActorDir::Right;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,45.0f });
		}
		if (true == IsDown('A'))
		{
			EActorDir::Left;
			PlayerCursor->SetRotationDeg(FVector{ 0.0f,0.0f,135.0f });
		}
		if (true == IsDown('S'))
		{

			return;
		}
	}

}





