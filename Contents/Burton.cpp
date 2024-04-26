#include "PreCompile.h"
#include "Burton.h"

ABurton::ABurton()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	MenuRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	MenuRenderer->SetupAttachment(Root);
	MenuRenderer->SetPivot(EPivot::MAX);
	MenuRenderer->SetOrder(ERenderOrder::Menu);


	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetScale({ 340.0f, 50.0f });
	Collision->SetCollisionGroup(ECollisionOrder::Menu);
	Collision->SetCollisionType(ECollisionType::Rect);
	Collision->SetupAttachment(Root);

	SetRoot(Root);

}

ABurton::~ABurton()
{
}

void ABurton::BeginPlay()
{
	Super::BeginPlay();
	MenuRenderer->SetSprite("hud_OptionButton_0.png");
	MenuRenderer->SetAutoSize(2.0f, true);
}

void ABurton::CollisionCheck()
{
	Collision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer->SetSprite("hud_OptionButton_1.png");
		}
	);
	Collision->CollisionExit(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer->SetSprite("hud_OptionButton_0.png");
		}
	);
}


void ABurton::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	CollisionCheck();

}