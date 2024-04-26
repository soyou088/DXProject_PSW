#include "PreCompile.h"
#include "Menu.h"

AMenu::AMenu()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	MenuRenderer0 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer0->SetupAttachment(Root);
	MenuRenderer0->SetPivot(EPivot::MAX);

	MenuRenderer1 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer1->SetupAttachment(Root);
	MenuRenderer1->SetPivot(EPivot::MAX);

	MenuRenderer2 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer2->SetupAttachment(Root);
	MenuRenderer2->SetPivot(EPivot::MAX);

	MenuRenderer3 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer3->SetupAttachment(Root);
	MenuRenderer3->SetPivot(EPivot::MAX);

	MenuRenderer4 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer4->SetupAttachment(Root);
	MenuRenderer4->SetPivot(EPivot::MAX);

	MenuRenderer5 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer5->SetupAttachment(Root);
	MenuRenderer5->SetPivot(EPivot::MAX);

	MenuRenderer6 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer6->SetupAttachment(Root);
	MenuRenderer6->SetPivot(EPivot::MAX);

	MenuRenderer7 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer7->SetupAttachment(Root);
	MenuRenderer7->SetPivot(EPivot::MAX);

	Collision0 = CreateDefaultSubObject<UCollision>("Collision");
	Collision0->SetupAttachment(Root);
	Collision0->SetScale({ 340.0f, 50.0f });
	Collision0->SetPosition({ 430.0f,220.0f });
	Collision0->SetCollisionGroup(ECollisionOrder::Menu);
	Collision0->SetCollisionType(ECollisionType::Rect);

	Collision1 = CreateDefaultSubObject<UCollision>("Collision");
	Collision1->SetupAttachment(Root);
	Collision1->SetScale({ 340.0f, 50.0f });;
	Collision1->SetPosition({ 430.0f, 150.0f });
	Collision1->SetCollisionGroup(ECollisionOrder::Menu);
	Collision1->SetCollisionType(ECollisionType::Rect);

	Collision2 = CreateDefaultSubObject<UCollision>("Collision");
	Collision2->SetupAttachment(Root);
	Collision2->SetScale({ 340.0f, 50.0f });;
	Collision2->SetPosition({ 430.0f, 80.0f });
	Collision2->SetCollisionGroup(ECollisionOrder::Menu);
	Collision2->SetCollisionType(ECollisionType::Rect);

	Collision3 = CreateDefaultSubObject<UCollision>("Collision");
	Collision3->SetupAttachment(Root);
	Collision3->SetScale({ 340.0f, 50.0f });;
	Collision3->SetPosition({ 430.0f, 10.0 });
	Collision3->SetCollisionGroup(ECollisionOrder::Menu);
	Collision3->SetCollisionType(ECollisionType::Rect);

	Collision4 = CreateDefaultSubObject<UCollision>("Collision");
	Collision4->SetupAttachment(Root);
	Collision4->SetScale({ 340.0f, 50.0f });;
	Collision4->SetPosition({ 430.0f, -60.0f });
	Collision4->SetCollisionGroup(ECollisionOrder::Menu);
	Collision4->SetCollisionType(ECollisionType::Rect);

	Collision5 = CreateDefaultSubObject<UCollision>("Collision");
	Collision5->SetupAttachment(Root);
	Collision5->SetScale({ 340.0f, 50.0f });;
	Collision5->SetPosition({ 430.0f,-130.0f });
	Collision5->SetCollisionGroup(ECollisionOrder::Menu);
	Collision5->SetCollisionType(ECollisionType::Rect);

	Collision6 = CreateDefaultSubObject<UCollision>("Collision");
	Collision6->SetupAttachment(Root);
	Collision6->SetScale({ 340.0f, 50.0f });;
	Collision6->SetPosition({ 430.0f, -200.0 });
	Collision6->SetCollisionGroup(ECollisionOrder::Menu);
	Collision6->SetCollisionType(ECollisionType::Rect);

	Collision7 = CreateDefaultSubObject<UCollision>("Collision");
	Collision7->SetupAttachment(Root);
	Collision7->SetScale({ 340.0f, 50.0f });;
	Collision7->SetPosition({ 430.0f, -270.0f });
	Collision7->SetCollisionGroup(ECollisionOrder::Menu);
	Collision7->SetCollisionType(ECollisionType::Rect);



	SetRoot(Root);



}

AMenu::~AMenu()
{
}

void AMenu::BeginPlay()
{
	Super::BeginPlay();

	MenuRenderer0->SetSprite("hud_OptionButton_0.png");
	MenuRenderer0->SetAutoSize(2.0f, true);
	MenuRenderer0->SetPosition({ 430.0f,220.0f});
	MenuRenderer0->SetOrder(ERenderOrder::Menu);

	MenuRenderer1->SetSprite("hud_OptionButton_0.png");
	MenuRenderer1->SetAutoSize(2.0f, true);
	MenuRenderer1->SetPosition({ 430.0f, 150.0f });
	MenuRenderer1->SetOrder(ERenderOrder::Menu);

	MenuRenderer2->SetSprite("hud_OptionButton_0.png");
	MenuRenderer2->SetAutoSize(2.0f, true);
	MenuRenderer2->SetPosition({ 430.0f, 80.0f });
	MenuRenderer2->SetOrder(ERenderOrder::Menu);

	MenuRenderer3->SetSprite("hud_OptionButton_0.png");
	MenuRenderer3->SetAutoSize(2.0f, true);
	MenuRenderer3->SetPosition({ 430.0f, 10.0f });
	MenuRenderer3->SetOrder(ERenderOrder::Menu);

	MenuRenderer4->SetSprite("hud_OptionButton_0.png");
	MenuRenderer4->SetAutoSize(2.0f, true);
	MenuRenderer4->SetPosition({ 430.0f,-60.0f });
	MenuRenderer4->SetOrder(ERenderOrder::Menu);

	MenuRenderer5->SetSprite("hud_OptionButton_0.png");
	MenuRenderer5->SetAutoSize(2.0f, true);
	MenuRenderer5->SetPosition({ 430.0f,-130.0f });
	MenuRenderer5->SetOrder(ERenderOrder::Menu);

	MenuRenderer6->SetSprite("hud_OptionButton_0.png");
	MenuRenderer6->SetAutoSize(2.0f, true);
	MenuRenderer6->SetPosition({ 430.0f,-200.0f });
	MenuRenderer6->SetOrder(ERenderOrder::Menu);

	MenuRenderer7->SetSprite("hud_OptionButton_0.png");
	MenuRenderer7->SetAutoSize(2.0f, true);
	MenuRenderer7->SetPosition({ 430.0f,-270.0f });
	MenuRenderer7->SetOrder(ERenderOrder::Menu);




}

void AMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Collision0->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer0->SetSprite("hud_OptionButton_1.png");
		}
	);	
	Collision1->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer1->SetSprite("hud_OptionButton_1.png");
		}
	);	
	Collision2->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer2->SetSprite("hud_OptionButton_1.png");
		}
	);	
	Collision3->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer3->SetSprite("hud_OptionButton_1.png");		
		}
	);	
	Collision4->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer4->SetSprite("hud_OptionButton_1.png");	
		}
	);
	Collision5->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer5->SetSprite("hud_OptionButton_1.png");	
		}
	);	
	Collision6->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer6->SetSprite("hud_OptionButton_1.png");	
		}
	);	
	Collision7->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer7->SetSprite("hud_OptionButton_1.png");	
		}
	);	

}

