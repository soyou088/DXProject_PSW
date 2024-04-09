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

	UContentsConstValue::MapTex = UEngineTexture::FindRes("Holo_map_06.png");
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

	{
		std::shared_ptr<APlayBack> Back = GetWorld()->SpawnActor<APlayBack>("PlayBack");

		float TileSize = UContentsConstValue::TileSize;
		float4 TexScale = UContentsConstValue::MapTexScale;
		float4 ImageScale = { TexScale.X * TileSize, TexScale.Y * TileSize, 0.0f };

		Back->SetActorScale3D(ImageScale);
		Back->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });
	}
}



void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	

}

