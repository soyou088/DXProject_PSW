#include "PreCompile.h"
#include "Menu.h"

AMenu::AMenu()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	MenuRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer->SetupAttachment(Root);
	MenuRenderer->SetPivot(EPivot::BOT);

	SetRoot(Root);

}

AMenu::~AMenu()
{
}

void AMenu::BeginPlay()
{
	Super::BeginPlay();

	MenuRenderer->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer->SetAutoSize(2.0f, true);
	MenuRenderer->SetPosition({ 100.0f,0.5f});
	MenuRenderer->SetOrder(ERenderOrder::Title);

}

void AMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

