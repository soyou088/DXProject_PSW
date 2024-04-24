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

	SetActorScale3D(FVector(500.0f, 200.0f, 100.0f));
	Renderer->SetSprite("HoloTitle.png");
	Renderer->SetPosition(FVector({0.8f, 0.8f }));
	Renderer->SetOrder(ERenderOrder::Title);

	BackRenderer->SetSprite("menu_charselecBG_0.png");
	BackRenderer->SetScale({10.0f,10.0f});
	BackRenderer->SetOrder(ERenderOrder::Back);
}


void ATitleLogo::Move(float _DeltaTime)
{
	if (0.0f <= LogoMoveTime && LogoMoveTime < 1.5f)
	{
		Renderer->AddPosition(LogoMove * _DeltaTime);
	}
	if (1.7f <= LogoMoveTime && LogoMoveTime < 3.5f)
	{
		Renderer->AddPosition(LogoMove * -1 * _DeltaTime);
	}
	if (3.7f <= LogoMoveTime)
	{
		LogoMoveTime = 0.0f;
	}
	LogoMoveTime += _DeltaTime;
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Move(_DeltaTime);
	int a = 0;
}
