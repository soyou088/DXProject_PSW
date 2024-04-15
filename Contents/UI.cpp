#include "PreCompile.h"
#include "UI.h"




AUI::AUI()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Root);
	Renderer->SetupAttachment(Root);

}

AUI::~AUI()
{
}

void AUI::BeginPlay()
{
	Super::BeginPlay();
	
	//Renderer->CreateAnimation("Bubba", "Bubba", 0.1f, true, 0, 2);
	Renderer->SetSprite("spr_Ame_portrait_0.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::UI);
	
}

void AUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

