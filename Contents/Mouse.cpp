#include "PreCompile.h"
#include "Mouse.h"

AMouse::AMouse()
{
	
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);

	InputOn();
}

AMouse::~AMouse()
{
}

void AMouse::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("spr_GameCursor1_0.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(10);
}

void AMouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

