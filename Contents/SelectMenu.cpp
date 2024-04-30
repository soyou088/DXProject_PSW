#include "PreCompile.h"
#include "SelectMenu.h"

ASelectMenu::ASelectMenu()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	TopGround = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TopGround->SetupAttachment(Root);

	BackChaGround = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	BackChaGround->SetupAttachment(Root);

	SetRoot(Root);
}

ASelectMenu::~ASelectMenu()
{
}

void ASelectMenu::BeginPlay()
{
	Super::BeginPlay();

	TopGround->SetSprite("hud_OptionButton_0.png");
	TopGround->SetScale({ 2000.0f,50.0f });
	TopGround->SetPosition({ 0.0f, 315.0f });
	TopGround->SetOrder(ERenderOrder::Menu);

	BackChaGround->SetSprite("spr_Title_Kiara_0.png");
	BackChaGround->SetAutoSize(4.0f, true);
	BackChaGround->SetOrder(ERenderOrder::Menu);

}

void ASelectMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

