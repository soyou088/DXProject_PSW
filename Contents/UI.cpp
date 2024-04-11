#include "PreCompile.h"
#include "UI.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>


AUI::AUI()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

AUI::~AUI()
{
}

void AUI::BeginPlay()
{
	Super::BeginPlay();
	
	Renderer->SetSprite("spr_Ame_portrait_0.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::UI);
	
}

void AUI::Tick(float _DeltaTime)
{
}

