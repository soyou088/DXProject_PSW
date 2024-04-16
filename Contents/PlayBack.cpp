#include "PreCompile.h"
#include "PlayBack.h"

APlayBack::APlayBack()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
	InputOn();
}

APlayBack::~APlayBack()
{
}

void APlayBack::BeginPlay()
{
	Super::BeginPlay();
	
	
	// ���ο��� ���÷��� ���� ã��
	Renderer->SetSprite("Holo_map_03.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void APlayBack::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);
}