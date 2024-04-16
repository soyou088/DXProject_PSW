#include "PreCompile.h"
#include "Mouse.h"

AMouse::AMouse()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	MouseCursorRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Root);
	MouseCursorRenderer->SetupAttachment(Root);
	InputOn();

}

AMouse::~AMouse()
{
}

void AMouse::BeginPlay()
{
	Super::BeginPlay();
	MouseCursorRenderer->CreateAnimation("Cursor", "spr_GameCursor1_0.png", 0.1f, false);
	MouseCursorRenderer->CreateAnimation("MCursor", "spr_GameCursor_0.png", 0.1f, false);
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
		MouseCursorRenderer->SetActive(true);
		MouseCursorRenderer->ChangeAnimation("Cursor");
		MouseCursorON = true;

	}

	else if (true == MouseCursorON && true == IsDown(VK_LBUTTON))
	{
		CursorOFf();
		MouseCursorRenderer->ChangeAnimation("MCursor");
		MouseCursorRenderer->SetActive(true);
		MouseCursorON = false;
	}





}

