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
	MouseCursorRenderer->SetAutoSize(1.0f, true);
	MouseCursorRenderer->SetOrder(10);
}

void AMouse::CursorOFf()
{
	ShowCursor(FALSE);
}

void AMouse::CursorON()
{
	ShowCursor(TRUE);
}


void AMouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true != MouseCursorON && true == IsPress(VK_LBUTTON))
	{
		CursorOFf();
		MouseCursorRenderer->SetActive(true);
		MouseCursorRenderer->ChangeAnimation("Cursor");
		MouseCursorON = true;

	}



	if (true == MouseCursorON && true == IsPress(VK_RBUTTON))
	{
		CursorON();
		MouseCursorRenderer->SetActive(false);
		MouseCursorON = false;
	}





}

