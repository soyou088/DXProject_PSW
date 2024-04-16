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
	
	
	// 내부에서 샘플러도 같이 찾을
	Renderer->SetSprite("Holo_map_03.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void APlayBack::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
}