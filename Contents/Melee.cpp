#include "PreCompile.h"
#include "Melee.h"
#include "Player.h"

AMelee::AMelee()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::MAX);


	SetRoot(Root);
}

AMelee::~AMelee()
{
}

void AMelee::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("KiaraAttack", "KiaraAttack", 0.1f);
	Renderer->SetPosition(APlayer::PlayerPos);
	Renderer->SetAutoSize(1.0f, true);
	Renderer->ChangeAnimation("KiaraAttack");
	Renderer->SetOrder(ERenderOrder::Attack);
}



void AMelee::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}

