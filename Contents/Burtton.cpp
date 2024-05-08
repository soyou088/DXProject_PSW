#include "PreCompile.h"
#include "Burtton.h"

ABurtton::ABurtton()
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

ABurtton::~ABurtton()
{
}

void ABurtton::BeginPlay()
{
	Super::BeginPlay();
	MenuRenderer->SetSprite("hud_OptionButton_0.png");
	MenuRenderer->SetAutoSize(2.0f, true);
}

void ABurtton::CollisionCheck()
{
	Collision->CollisionEnter(ECollisionOrder::Mouse, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer->SetSprite("hud_OptionButton_1.png");
		}
	);
	Collision->CollisionExit(ECollisionOrder::Mouse, [=](std::shared_ptr<UCollision> _Collison)
		{
			MenuRenderer->SetSprite("hud_OptionButton_0.png");
		}
	);
	
}


void ABurtton::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	CollisionCheck();

}