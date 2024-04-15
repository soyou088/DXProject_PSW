#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "PlayBack.h"
#include "ContentsValue.h"
#include "UI.h"
#include "Monster.h"
#include "Mouse.h"
#include <random>
#include <EngineCore/Camera.h>
#include <EngineCore/EngineDebugMsgWindow.h>



APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	std::shared_ptr<UEngineTexture> Tex = UEngineTexture::FindRes("Holo_map_04.png");

	CurIndex = { 0, 0 };
	float4 PlayerStartPos = IndexToCenterPos(CurIndex);


	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	MousePos = GEngine->EngineWindow.GetScreenMousePos();

	float4 CameraPos = PlayerStartPos;
	CameraPos.Z = -500.0f;
	Camera->SetActorLocation(CameraPos);


	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");

	{
		Player = GetWorld()->SpawnActor<APlayer>("Player");
		Player->SetActorLocation(PlayerStartPos);
	}
	for (int i = 0; i < 20; ++i) // 예를 들어 5마리의 몬스터를 생성하고 싶다면 5로 수정
	{
		SpawnMonsterRandomLocation();
	}

	{
		//UI = GetWorld()->SpawnActor<AUI>("UI");
		//UI->SetActorLocation(PlayerStartPos);
	}

	// 3840 x 3840

	for (int y = -1; y < 2; y++)
	{
		for (int x = -1; x < 2; x++)
		{
			std::shared_ptr<APlayBack> Back = GetWorld()->SpawnActor<APlayBack>("PlayBack");

			Back->SetActorScale3D(ContentsValue::GroundTileSize);

			FIntPoint Point;
			Point.X = x;
			Point.Y = y;

			float4 Pos;
			Pos.X = ContentsValue::GroundTileSize.X * x;
			Pos.Y = ContentsValue::GroundTileSize.Y * y;

			Pos.X += ContentsValue::GroundTileSize.hX();
			Pos.Y += ContentsValue::GroundTileSize.hY();
			Back->SetActorLocation(Pos);

			Grounds.push_back(Back);

		}
	}


}

// 랜덤한 위치에 몬스터 생성하는 함수
void APlayGameMode::SpawnMonsterRandomLocation()
{
	//float4 PlayerStartPos = IndexToCenterPos(CurIndex);
	//std::random_device rd;
	//std::mt19937 rng(rd());
	//std::uniform_int_distribution<int> distX(-5, 5); // X 축에서 -5부터 5까지의 랜덤한 위치
	//std::uniform_int_distribution<int> distY(-5, 5); // Y 축에서 -5부터 5까지의 랜덤한 위치

	//int randomX = distX(rng);
	//int randomY = distY(rng);

	//float4 MonsterStartPos = PlayerStartPos;
	//MonsterStartPos.X += randomX * 200.0f; // X 축 이동
	//MonsterStartPos.Y += randomY * 200.0f; // Y 축 이동



	//// 몬스터 생성 및 위치 설정
	//auto Baerat = GetWorld()->SpawnActor<AMonster>("Monster");
	//Baerat->SetActorLocation(MonsterStartPos);


	
}





float4 APlayGameMode::IndexToCenterPos(FIntPoint _Index)
{
	float4 Pos;
	Pos.X = ContentsValue::GroundTileSize.X * _Index.X;
	Pos.Y = ContentsValue::GroundTileSize.Y * _Index.Y;

	Pos.X += ContentsValue::GroundTileSize.hX();
	Pos.Y += ContentsValue::GroundTileSize.hY();

	return Pos;
}

FIntPoint APlayGameMode::PosToIndex(float4 _Pos)
{
	FIntPoint Index;

	float4 Location = _Pos;

	float4 Pos;
	Pos.X = Location.X / ContentsValue::GroundTileSize.X;
	Pos.Y = Location.Y / ContentsValue::GroundTileSize.Y;

	if (0 >= Pos.X)
	{
		Pos.X += -1;
	}
	if (0 >= Pos.Y)
	{
		Pos.Y += -1;
	}

	Index.X = Pos.X;
	Index.Y = Pos.Y;
	return Index;
}



void APlayGameMode::InfinityGroundCheck()
{
	float4 PlayerPos = Player->GetActorLocation();

	FIntPoint Index = PosToIndex(PlayerPos);

	if (Index.X != CurIndex.X || Index.Y != CurIndex.Y)
	{
		int GroundCount = 0;

		float4 MovePos;
		MovePos.X = Index.X * ContentsValue::GroundTileSize.X;
		MovePos.Y = Index.Y * ContentsValue::GroundTileSize.Y;

		for (int y = -1; y < 2; y++)
		{
			for (int x = -1; x < 2; x++)
			{
				std::shared_ptr<APlayBack> Back = Grounds[GroundCount];

				Back->SetActorScale3D(ContentsValue::GroundTileSize);
				FIntPoint Point;
				Point.X = x;
				Point.Y = y;

				float4 Pos;
				Pos.X = ContentsValue::GroundTileSize.X * x;
				Pos.Y = ContentsValue::GroundTileSize.Y * y;

				Pos.X += ContentsValue::GroundTileSize.hX();
				Pos.Y += ContentsValue::GroundTileSize.hY();
				Back->SetActorLocation(Pos + MovePos);
				++GroundCount;
			}
		}

		CurIndex = Index;
	}
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	InfinityGroundCheck();


	{

		float4 PlayerPos = Player->GetActorLocation();
		FIntPoint Index = PosToIndex(PlayerPos);
		CurIndex = Index;
		float4 PlayerScale = Player->GetActorScale3D();
		UEngineDebugMsgWindow::PushMsg(std::format("PlayerPos : {}", PlayerPos.ToString()));
		UEngineDebugMsgWindow::PushMsg(std::format("PlayerScale : {}", PlayerScale.ToString()));
		UEngineDebugMsgWindow::PushMsg(std::format("PlayerIndex : {}, {}", Index.X, Index.Y));
		UEngineDebugMsgWindow::PushMsg(std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString()));

	}



}

