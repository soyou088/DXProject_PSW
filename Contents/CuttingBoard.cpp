#include "PreCompile.h"
#include "CuttingBoard.h"
#include "Monster.h"

ACuttingBoard::ACuttingBoard()
{
	//Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	
	Renderer->SetSprite("Board.png");
	//Renderer->SetupAttachment(Root);
	Renderer->SetAutoSize(ContentsValue::MultipleSize * 20, true);
//	SetRoot(Root);
}


ACuttingBoard::~ACuttingBoard()
{
}

void ACuttingBoard::BeginPlay()
{
	Super::BeginPlay();

	Name = "CuttingBoard";

}

void ACuttingBoard::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BulletSpeed = 500.0f;

	{
		FVector Pos = Root->GetLocalPosition() * Dir;
		UEngineDebugMsgWindow::PushMsg(std::format("RootPos : {}", Pos.ToString()));
	}

	//CheckHit();

}

void ACuttingBoard::CheckHit()
{
}
