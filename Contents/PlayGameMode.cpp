#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "PlayBack.h"
#include <EngineCore/Camera.h>

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();

	UContentsConstValue::MapTex = UEngineTexture::FindRes("Holo_map_04.png");
	UContentsConstValue::MapTexScale = UContentsConstValue::MapTex->GetScale();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(1920.0f, -1920.0f, -500.0f));


	{
		std::shared_ptr<APlayer> Actor = GetWorld()->SpawnActor<APlayer>("Player");

		float TileSize = UContentsConstValue::TileSize;
		float4 TexScale = UContentsConstValue::MapTexScale;
		float4 ImageScale = { TexScale.X * TileSize, TexScale.Y * TileSize, 0.0f };

		Actor->SetActorScale3D(ImageScale);
		Actor->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 1000.0f });
	}


		std::shared_ptr<APlayBack> Back0 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back1 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back2 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back3 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back4 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back5 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back6 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back7 = GetWorld()->SpawnActor<APlayBack>("PlayBack");
		std::shared_ptr<APlayBack> Back8 = GetWorld()->SpawnActor<APlayBack>("PlayBack");


		float TileSize = UContentsConstValue::TileSize;
		float4 TexScale = UContentsConstValue::MapTexScale;
		float4 ImageScale = { TexScale.X * TileSize, TexScale.Y * TileSize, 0.0f };

		Back0->SetActorScale3D(ImageScale);
		Back0->SetActorLocation({ -ImageScale.hX() , ImageScale.hY(), 500.0f });            // 왼쪽 대각선 위
		Back1->SetActorScale3D(ImageScale);
		Back1->SetActorLocation({ ImageScale.hX() , ImageScale.hY(), 500.0f });             // 위쪽
		Back2->SetActorScale3D(ImageScale);
		Back2->SetActorLocation({ ImageScale.hX() * 3, ImageScale.hY(), 500.0f });          // 오른쪽 대각선 위
		Back3->SetActorScale3D(ImageScale);
		Back3->SetActorLocation({ ImageScale.hX() * 3, -ImageScale.hY(), 500.0f });         // 오른쪽
		Back4->SetActorScale3D(ImageScale);
		Back4->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });             // 가운데
		Back5->SetActorScale3D(ImageScale);
		Back5->SetActorLocation({ -ImageScale.hX() , -ImageScale.hY(), 500.0f });           // 왼쪽
		Back6->SetActorScale3D(ImageScale);
		Back6->SetActorLocation({ ImageScale.hX() * 3, -ImageScale.hY() * 3, 500.0f });     // 오른쪽 대각선 아래
		Back7->SetActorScale3D(ImageScale);
		Back7->SetActorLocation({ ImageScale.hX(), -ImageScale.hY() * 3, 500.0f });         // 아래
		Back8->SetActorScale3D(ImageScale);
		Back8->SetActorLocation({ -ImageScale.hX() , -ImageScale.hY() * 3, 500.0f });       // 왼쪽 대각선 아래


		Back0->index = 0;
		BackList.push_back(Back0);
		BackList.push_back(Back1);
		BackList.push_back(Back2);
		BackList.push_back(Back3);
		BackList.push_back(Back4);
		BackList.push_back(Back5);
		BackList.push_back(Back6);
		BackList.push_back(Back7);
		BackList.push_back(Back8);

}



void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}

