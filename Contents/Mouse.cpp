#include "PreCompile.h"
#include "Player.h"
#include "Mouse.h"

FVector AMouse::MousePos = FVector::Zero;

AMouse::AMouse()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);
	
	MouseCursorRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MouseCursorRenderer->SetupAttachment(Root);
	
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
}

void AMouse::CursorOFf()
{
	ShowCursor(FALSE);
}

void AMouse::GetMouseCursorON()
{
	MouseCursorON = false;
}

void AMouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == MouseCursorON && true == IsDown(VK_LBUTTON))
	{
		CursorOFf();
		MouseCursorRenderer->SetSprite("spr_GameCursor1_0.png");
		MouseCursorRenderer->SetActive(true);
		MouseCursorON = true;

	}

	else if (true == MouseCursorON && true == IsDown(VK_LBUTTON))
	{
		CursorOFf();
		MouseCursorRenderer->SetSprite("spr_GameCursor_0.png");
		MouseCursorRenderer->SetActive(true);
		MouseCursorON = false;
	}

	FVector MouseLocation = FVector{ APlayer::PlayerPos.X + MousePos.X - 640, APlayer::PlayerPos.Y - MousePos.Y + 360 };

	SetActorLocation(MouseLocation);
}

