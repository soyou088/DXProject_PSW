#include "PreCompile.h"
#include "Bullet.h"

ABullet::ABullet()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::MAX);

	SetRoot(Root);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale({ 10.0f,10.f });

	Collision->SetCollisionGroup(ECollisionOrder::Weapon);
	Collision->SetCollisionType(ECollisionType::Rect);
}

ABullet::~ABullet()
{
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
	//CreatePlayerAnimation("Ame");
	Renderer->CreateAnimation("AmeAttack", "AmeAttack", 0.1f, true);
	Renderer->SetAutoSize(2.0f, true);
	Renderer->ChangeAnimation("AmeAttack");
	Renderer->SetOrder(ERenderOrder::Attack);
}

void ABullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			_Collison->GetActor()->Destroy();
		}
	);

}

