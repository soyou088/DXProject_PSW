#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);


	BackRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	BackRenderer->SetupAttachment(Root);
	SetRoot(Root);
}

ATitleLogo::~ATitleLogo()
{
}


void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(600.0f, 200.0f, 100.0f));
	Renderer->SetSprite("HoloTitle.png");
	Renderer->SetPosition(FVector({0.65f, 0.7f }));
	Renderer->SetOrder(ERenderOrder::Title);

	BackRenderer->SetSprite("menu_charselecBG_0.png");
	BackRenderer->SetScale({10.0f,10.0f});
	BackRenderer->SetOrder(ERenderOrder::Back);
}


void ATitleLogo::Move()
{
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	
	
	int a = 0;
}
