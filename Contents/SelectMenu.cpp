#include "PreCompile.h"
#include "SelectMenu.h"

ASelectMenu::ASelectMenu()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	TopGround = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TopGround->SetupAttachment(Root);

	BackChaGroundL = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	BackChaGroundL->SetupAttachment(Root);

	BackChaGroundR = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	BackChaGroundR->SetupAttachment(Root);

	Explanation0 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Explanation0->SetupAttachment(Root);

	Explanation1 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Explanation1->SetupAttachment(Root);


	Explanation2 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Explanation2->SetupAttachment(Root);

	ExplanationFrame = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	ExplanationFrame->SetupAttachment(Root);

	ChAnimation = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	ChAnimation->SetupAttachment(Root);


	SetRoot(Root);
}

ASelectMenu::~ASelectMenu()
{
}

void ASelectMenu::BeginPlay()
{
	Super::BeginPlay();

	TopGround->SetSprite("menu_charselecLocked_0.png");
	TopGround->SetScale({ 2000.0f,50.0f });
	TopGround->SetPosition({ 0.0f, 315.0f });
	TopGround->SetOrder(ERenderOrder::Menu);

	BackChaGroundL->SetSprite("spr_Title_Kiara_0.png");
	BackChaGroundL->SetAutoSize(4.0f, true);
	BackChaGroundL->SetPosition({ -560.0f,0.0f });
	BackChaGroundL->SetOrder(ERenderOrder::Menu);

	BackChaGroundR->SetSprite("spr_Title_Kiara_0.png");
	BackChaGroundR->SetAutoSize(4.0f, true);
	BackChaGroundR->SetDir(EEngineDir::Left);
	BackChaGroundR->SetPosition({ 560.0f,0.0f });
	BackChaGroundR->SetOrder(ERenderOrder::Menu);

	Explanation0->SetSprite("menu_charselecLocked_0.png");
	Explanation0->SetScale({ 450.0f,250.0f });
	Explanation0->SetPosition({-400.0f,-200.0f,-20.0f});
	Explanation0->SetOrder(ERenderOrder::TitleF);

	Explanation1->SetSprite("menu_charselecLocked_0.png");
	Explanation1->SetScale({ 450.0f,250.0f });
	Explanation1->SetPosition({ 0.0f,-200.0f,-20.0f });
	Explanation1->SetOrder(ERenderOrder::TitleF);

	Explanation2->SetSprite("menu_charselecLocked_0.png");
	Explanation2->SetScale({ 450.0f,250.0f });
	Explanation2->SetPosition({ 400.0f,-200.0f,-20.0f });
	Explanation2->SetOrder(ERenderOrder::TitleF);

	ExplanationFrame->SetSprite("menu_charselecLocked_1.png");
	ExplanationFrame->SetAutoSize(1.0f, true);
	ExplanationFrame->SetPosition({ 0.0f,-200.0f,-20.0f });
	ExplanationFrame->SetOrder(ERenderOrder::Player);

	ChAnimation->CreateAnimation("KiaraMove", "Kiara", 0.1f,true);
	ChAnimation->SetAutoSize(4.0f, true);
	ChAnimation->ChangeAnimation("KiaraMove");
	ChAnimation->SetPosition({ -480.0f,-150.0f });
	ChAnimation->SetOrder(ERenderOrder::Player);

}

void ASelectMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

