#include "PreCompile.h"
#include "Mouse.h"
#include <EngineCore/DefaultSceneComponent.h>

AMouse::AMouse()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Root);
	Renderer->SetupAttachment(Root);
	InputOn();

}

AMouse::~AMouse()
{
}

void AMouse::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("Cursor", "spr_GameCursor1_0.png", 0.1f, false);
	Renderer->ChangeAnimation("Cursor");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(10);
}

void AMouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

