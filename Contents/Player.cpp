#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

//std::vector<std::shared_ptr<APlayer>> BackList;

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

		Renderer->CreateAnimation("AmeIdle", "AmeIdle");
		//Renderer->CreateAnimation("Die", "Die");
		Renderer->CreateAnimation("AmeRun", "AmeRun");

		StateInit();
		Renderer->SetOrder(ERenderOrder::Player);


}


void APlayer::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	
	
}




