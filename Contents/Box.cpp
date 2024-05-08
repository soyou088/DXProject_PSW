#include "PreCompile.h"
#include "Box.h"
#include "Player.h"

UBox::UBox()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Box = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Box->SetupAttachment(Root);

	ShakeBox = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	ShakeBox->SetupAttachment(Root);
	ShakeBox->SetPivot(EPivot::BOT);
	
	OpenBox = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	OpenBox->SetupAttachment(Root);


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
	
	ShakeBox->CreateAnimation("ShakeBox", "ShakeBox", 0.1, 2.f);
	ShakeBox->SetAutoSize(ContentsValue::MultipleSize, true);
	ShakeBox->SetOrder(ERenderOrder::Player);
	
	OpenBox->CreateAnimation("OpenBox", "OpenBox", 0.1, true);
	OpenBox->SetAutoSize(ContentsValue::MultipleSize, true);
	OpenBox->SetOrder(ERenderOrder::Player);

	ShakeBox->ChangeAnimation("ShakeBox");

}

void UBox::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ShakeBox->SetPosition(APlayer::PlayerPos);
	if (true == ShakeBox->IsCurAnimationEnd())
	{
		OpenBox->ChangeAnimation("OpenBox");
	}

}

void UBox::ColChack()
{

}



