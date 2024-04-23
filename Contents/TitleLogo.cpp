#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	SetRoot(Root);
}

ATitleLogo::~ATitleLogo()
{
}


void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(500.0f, 200.0f, 100.0f));
	// Renderer->SetSprite("CharWalk1_0.png");
	Renderer->SetSprite("HoloTitle.png");
	Renderer->SetPosition(FVector({0.8f, 0.8f }));
	Renderer->SetOrder(ERenderOrder::Title);
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	
	
	int a = 0;
}

