#include "PreCompile.h"
#include "Box.h"
#include "Player.h"

UBox::UBox()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Box = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Box->SetupAttachment(Root);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(40.f, 30.f));
	Collision->SetPosition(FVector{ APlayer::PlayerPos.X + 2560 , APlayer::PlayerPos.Y + 2450});
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);
	InputOn();
}

UBox::~UBox()
{
}

void UBox::BeginPlay()
{
	Super::BeginPlay();

	
	Box->SetSprite("spr_holozonBox_0.png");
	Box->SetAutoSize(ContentsValue::MultipleSize, true);
	Box->SetOrder(ERenderOrder::Player);
	Box->SetPosition(FVector{ APlayer::PlayerPos.X + 2560 , APlayer::PlayerPos.Y + 2500 });
	

	BoxAnimation = CreateWidget<UImage>(GetWorld(), "BoxAnimation");
	BoxAnimation->CreateAnimation("ShakeBox", "ShakeBox", 0.1,true);
	BoxAnimation->CreateAnimation("OpenBox", "OpenBox", 0.1, true);
	BoxAnimation->SetPosition(APlayer::PlayerPos);
	BoxAnimation->SetAutoSize(ContentsValue::MultipleSize, true);
	BoxAnimation->SetOrder(ERenderOrder::Player);

	BoxAnimation->ChangeAnimation("ShakeBox");
}

void UBox::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ColChack();
}

void UBox::ColChack()
{
	Collision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			//BoxAnimation->ChangeAnimation("OpenBox");
		}
	);

}



