#include "PreCompile.h"
#include "Player.h"
#include "Mouse.h"


FVector AMouse::MousePos = FVector::Zero;
bool AMouse::MouseCursorON = false;


AMouse::AMouse()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	
	MouseCursorRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MouseCursorRenderer->SetupAttachment(Root);

	
	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale({ 10.0f,20.f });
	Collision->SetPosition({-10.0f,10.0f});
	Collision->SetCollisionGroup(ECollisionOrder::Player);
	Collision->SetCollisionType(ECollisionType::Rect);



	SetRoot(Root);
	InputOn();
}

AMouse::~AMouse()
{
}

void AMouse::BeginPlay()
{
	Super::BeginPlay();

	MouseCursorRenderer->SetSprite("spr_GameCursor_0.png");
	MouseCursorRenderer->SetAutoSize(1.0f, true);
	MouseCursorRenderer->SetOrder(10);

	int a = 0;
}

void AMouse::CursorOFf()
{
	ShowCursor(FALSE);
}


void AMouse::CurCursor()
{
	if (true == IsDown(VK_LBUTTON))
	{
		if (true != MouseCursorON)
		{
			MouseCursorON = true;
		}
		else
		{
			MouseCursorON = false;
		}
	}
}

void AMouse::CheckCurCursor()
{
	if (true != MouseCursorON)
	{
		CursorOFf();
		MouseCursorRenderer->SetSprite("spr_GameCursor_0.png");
		//Renderer->SetPivot();
	}
	else
	{
		CursorOFf();
		MouseCursorRenderer->SetSprite("spr_GameCursor1_0.png");
		MouseCursorRenderer->SetPivot(EPivot::MAX);
	}
}


void AMouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if ("PlayLevel" == GetWorld()->GetName())
	{
		CurCursor();
		CheckCurCursor();
	}


	FVector PPos = APlayer::PlayerPos;
	MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector MouseLocation = FVector{ PPos.X + MousePos.X - 640, PPos.Y - MousePos.Y + 360 };
	SetActorLocation(MouseLocation);

	int a = 0;

}

