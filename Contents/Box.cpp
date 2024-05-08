#include "PreCompile.h"
#include "Box.h"
#include "Player.h"

UBox::UBox()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Box = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Box->SetupAttachment(Root);
	Box->SetPivot(EPivot::BOT);

	BoxAnimation = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	BoxAnimation->SetupAttachment(Root);




	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(40.f, 30.f));
	Collision->SetPosition(APlayer::PlayerPos);
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
	Box->SetPosition(FVector{ APlayer::PlayerPos.X + 100, APlayer::PlayerPos.Y});
	
	BoxAnimation->CreateAnimation("ShakeBox", "ShakeBox", 0.1, true);
	BoxAnimation->CreateAnimation("OpenBox", "OpenBox", 0.1, true);
	BoxAnimation->SetAutoSize(ContentsValue::MultipleSize, true);
	BoxAnimation->SetOrder(ERenderOrder::Player);

	

	BoxAnimation->ChangeAnimation("ShakeBox");

}

void UBox::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	BoxAnimation->SetPosition(APlayer::PlayerPos);
	if (true == BoxAnimation->IsCurAnimationEnd())
	{
		BoxAnimation->ChangeAnimation("OpenBox");
	}

}

void UBox::ColChack()
{

}



