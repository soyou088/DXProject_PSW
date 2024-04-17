#include "PreCompile.h"
#include "Ranged.h"
#include "Player.h"

ARanged::ARanged()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::MAX);

	SetRoot(Root);
}

ARanged::~ARanged()
{
}

void ARanged::BeginPlay()
{
	Super::BeginPlay();
	CreatePlayerAnimation("Ame");

	Renderer->SetOrder(ERenderOrder::Weapons);
	Renderer->SetPosition(APlayer::PlayerPos);
}

void ARanged::CreatePlayerAnimation(std::string _Name)
{
	Renderer->CreateAnimation(_Name + "Attack", _Name, 0.1f, true, 0, 3);
}



void ARanged::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Renderer->ChangeAnimation("AmeAttack");

}


