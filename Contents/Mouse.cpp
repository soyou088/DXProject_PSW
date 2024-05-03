#include "PreCompile.h"
#include "Mouse.h"
#include "ContentsValue.h"
#include "Player.h"


FVector AMouse::MousePos = FVector::Zero;
bool AMouse::MouseCursorON = false;


AMouse::AMouse()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");


	
	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale({ 5.0f,5.f });
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

	MouseCursorRenderer = CreateWidget<UImage>(GetWorld(), "MouseCursor");
	MouseCursorRenderer->AddToViewPort(10);
	MouseCursorRenderer->SetSprite("spr_GameCursor_0.png");
	MouseCursorRenderer->SetAutoSize(ContentsValue::MultipleSize, true);



	
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

void AMouse::CheckCurCursor(FVector _MousePos)
{
	if (true != MouseCursorON)
	{
		CursorOFf();
		MouseCursorRenderer->SetSprite("spr_GameCursor_0.png");
		MouseCursorRenderer->SetPosition({ _MousePos.X- 595, -_MousePos.Y+ 310 });
	}
	else
	{
		CursorOFf();
		MouseCursorRenderer->SetSprite("spr_GameCursor1_0.png");
		MouseCursorRenderer->SetPosition({ _MousePos.X - 640, -_MousePos.Y + 360 });
	}
}


void AMouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector MouseLocation = FVector{ MousePos.X - 640,-MousePos.Y + 360 };
	FVector MPos = ContentsValue::PlayLevelMousePos;
	if ("PlayLevel" == GetWorld()->GetName())
	{
		CurCursor();
		Collision->SetPosition({ MPos.X + 5 , MPos.Y - 40.0f });
	}
	else
	{
		Collision->SetPosition(MouseLocation);
	}
	CheckCurCursor(MousePos);
	
	int a = 0;

}

