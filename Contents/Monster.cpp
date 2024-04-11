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
	Renderer->SetSprite("spr_Bubba_0.png");
	//Renderer->CreateAnimation("Bubba" , "Bubba" , 0.1f, true, 0 , 2);
	//Renderer->SetAutoSize(1.0f, true);
	Renderer->SetAutoSize(10, true);
	Renderer->SetOrder(0);
}

void AMonster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

