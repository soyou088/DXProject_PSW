#include "PreCompile.h"
#include "PlayBack.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

APlayBack::APlayBack()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

APlayBack::~APlayBack()
{
}

void APlayBack::BeginPlay()
{
	Super::BeginPlay();
	

	// ���ο��� ���÷��� ���� ã��
	Renderer->SetSprite("Holo_map_06.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void APlayBack::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);
}