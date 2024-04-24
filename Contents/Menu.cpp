#include "PreCompile.h"
#include "Menu.h"

AMenu::AMenu()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	MenuRenderer0 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer0->SetupAttachment(Root);
	MenuRenderer0->SetPivot(EPivot::BOT);

	MenuRenderer1 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer1->SetupAttachment(Root);
	MenuRenderer1->SetPivot(EPivot::BOT);

	MenuRenderer2 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer2->SetupAttachment(Root);
	MenuRenderer2->SetPivot(EPivot::BOT);

	MenuRenderer3 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer3->SetupAttachment(Root);
	MenuRenderer3->SetPivot(EPivot::BOT);

	MenuRenderer4 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer4->SetupAttachment(Root);
	MenuRenderer4->SetPivot(EPivot::BOT);

	MenuRenderer5 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer5->SetupAttachment(Root);
	MenuRenderer5->SetPivot(EPivot::BOT);

	MenuRenderer6 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer6->SetupAttachment(Root);
	MenuRenderer6->SetPivot(EPivot::BOT);

	MenuRenderer7 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer7->SetupAttachment(Root);
	MenuRenderer7->SetPivot(EPivot::BOT);

	SetRoot(Root);

}

AMenu::~AMenu()
{
}

void AMenu::BeginPlay()
{
	Super::BeginPlay();

	MenuRenderer0->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer0->SetAutoSize(2.0f, true);
	MenuRenderer0->SetPosition({ 400.0f,90.0f});
	MenuRenderer0->SetOrder(ERenderOrder::Title);

	MenuRenderer1->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer1->SetAutoSize(2.0f, true);
	MenuRenderer1->SetPosition({ 400.0f, 30.0f });
	MenuRenderer1->SetOrder(ERenderOrder::Title);

	MenuRenderer2->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer2->SetAutoSize(2.0f, true);
	MenuRenderer2->SetPosition({ 400.0f, -30.0f });
	MenuRenderer2->SetOrder(ERenderOrder::Title);

	MenuRenderer3->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer3->SetAutoSize(2.0f, true);
	MenuRenderer3->SetPosition({ 400.0f,-90.0f });
	MenuRenderer3->SetOrder(ERenderOrder::Title);

	MenuRenderer4->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer4->SetAutoSize(2.0f, true);
	MenuRenderer4->SetPosition({ 400.0f,-150.0f });
	MenuRenderer4->SetOrder(ERenderOrder::Title);

	MenuRenderer5->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer5->SetAutoSize(2.0f, true);
	MenuRenderer5->SetPosition({ 400.0f,-210.0f });
	MenuRenderer5->SetOrder(ERenderOrder::Title);

	MenuRenderer6->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer6->SetAutoSize(2.0f, true);
	MenuRenderer6->SetPosition({ 400.0f,-270.0f });
	MenuRenderer6->SetOrder(ERenderOrder::Title);

	MenuRenderer7->SetSprite("menu_hiscoreButtons_0.png");
	MenuRenderer7->SetAutoSize(2.0f, true);
	MenuRenderer7->SetPosition({ 400.0f,-330.0f });
	MenuRenderer7->SetOrder(ERenderOrder::Title);
}

void AMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

