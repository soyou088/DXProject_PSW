#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

APlayer::APlayer()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

		SetActorScale3D(FVector(100.0f, 100.0f, 100.0f));
		Renderer->CreateAnimation("AmeIdle", "AmeIdle");
		//Renderer->CreateAnimation("Die", "Die");
		//Renderer->CreateAnimation("Idle", "Idle");
		Renderer->CreateAnimation("AmeRun", "AmeRun");

		StateInit();

		Renderer->SetOrder(ERenderOrder::Player);
		
	
}

void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	
	
}