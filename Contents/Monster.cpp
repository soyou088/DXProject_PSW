#include "PreCompile.h"
#include "Monster.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

AMonster::AMonster()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

AMonster::~AMonster()
{
}

void AMonster::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Baerat" , "Baerat" , 0.1f, true, 0 , 2);
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Monster);
}

void AMonster::Tick(float _DeltaTime)
{
}

