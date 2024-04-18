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
#include <EngineBase/EngineRandom.h>


APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	std::shared_ptr<UEngineTexture> Tex = UEngineTexture::FindRes("Holo_map_03.png");

	CurIndex = { 0, 0 };
	float4 PlayerStartPos = IndexToCenterPos(CurIndex);


	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -200.0f });
	AMouse::MousePos = GEngine->EngineWindow.GetScreenMousePos();

	float4 CameraPos = PlayerStartPos;
	CameraPos.Z = -500.0f;
	Camera->SetActorLocation(CameraPos);

	Player = GetWorld()->SpawnActor<APlayer>("Player");
	Player->SetActorLocation(PlayerStartPos);

	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");

	//Ranged = GetWorld()->SpawnActor<ARanged>("Ranged");
	Melee = GetWorld()->SpawnActor<AMelee>("Melee");
	//Multishot = GetWorld()->SpawnActor<ARanged>("Ranged");
	int a = 0;
	

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


void APlayGameMode::MeleeAttack(float _DeltaTime)
{
	if (1.0f <= AttackTime)
	{

		Melee->SetActorLocation(APlayer::PlayerPos);
		AttackTime = 0.0f;
	}

	AttackTime += _DeltaTime;
}

float4 APlayGameMode::RandomLocation()
{
	float4 MonsterPos = APlayer::PlayerPos;
	MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 200.0f;
	MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 200.0f;

	return MonsterPos;
}

void APlayGameMode::SpawnMonster(std::string _Name, float4 _Location)
{
	std::shared_ptr<AMonster> Monster;
	//Monster->SetName(_Name);
	Monster = GetWorld()->SpawnActor<AMonster>(_Name);
	Monster->SetActorLocation(_Location);
	int a = 0;
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

void APlayGameMode::CursorOFf()
{
	ShowCursor(FALSE);
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AMouse::MousePos = GEngine->EngineWindow.GetScreenMousePos();
	ContentsValue::PlayLevelMousePos = FVector{ APlayer::PlayerPos.X + AMouse::MousePos.X - 640, APlayer::PlayerPos.Y - AMouse::MousePos.Y + 360 };
	Mouse->SetActorLocation(ContentsValue::PlayLevelMousePos);




	int a = 0;
	InfinityGroundCheck();

	// Melee 공격
	MeleeAttack(_DeltaTime);
	if (Player->GetPlayerDir() == EActorDir::E)
	{
		Melee->SetActorLocation({ APlayer::PlayerPos.X + 50 , APlayer::PlayerPos.Y });
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,0.0f });
	}
	else if (Player->GetPlayerDir() == EActorDir::N)
	{
		Melee->SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y + 50});
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,90.0f });
	}
	else if (Player->GetPlayerDir() == EActorDir::S)
	{
		Melee->SetActorLocation(FVector{ APlayer::PlayerPos.X, APlayer::PlayerPos.Y - 50});
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,270.0f });
	}
	else if (Player->GetPlayerDir() == EActorDir::W)
	{
		Melee->SetActorLocation(FVector{ APlayer::PlayerPos.X - 50, APlayer::PlayerPos.Y});
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,180.0f });
	}
	else if (Player->GetPlayerDir() == EActorDir::NE)
	{
		Melee->SetActorLocation(FVector{ APlayer::PlayerPos.X + 50, APlayer::PlayerPos.Y + 50});
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,45.0f });
	}
	else if (Player->GetPlayerDir() == EActorDir::NW)
	{
		Melee->SetActorLocation(FVector{ APlayer::PlayerPos.X - 50, APlayer::PlayerPos.Y + 50});
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,135.0f });
	}
	else if (Player->GetPlayerDir() == EActorDir::SE)
	{
		Melee->SetActorLocation(FVector{ APlayer::PlayerPos.X + 50, APlayer::PlayerPos.Y - 50});
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,315.0f });
	}
	else if (Player->GetPlayerDir() == EActorDir::SW)
	{
		Melee->SetActorLocation(FVector{ APlayer::PlayerPos.X - 50, APlayer::PlayerPos.Y - 50});
		Melee->SetActorRotation(FVector{ 0.0f,0.0f,225.0f });
	}	

	// 몬스터 스폰

	if (SpawnTerm <= 0)
	{
		SpawnMonster("Shrimp", RandomLocation());
		SpawnTerm = 5.0f;
	}
	else
	{
		SpawnTerm -= _DeltaTime;
	}
	
	
	{

		float4 PlayerPos = Player->GetActorLocation();
		FIntPoint Index = PosToIndex(PlayerPos);
		CurIndex = Index;
		float4 PlayerScale = Player->GetActorScale3D();
		UEngineDebugMsgWindow::PushMsg(std::format("PlayerPos : {}", PlayerPos.ToString()));
		UEngineDebugMsgWindow::PushMsg(std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString()));
		
		std::string PlayerDir = "";
		switch (Player->GetPlayerDir())
		{
		case EActorDir::N:
			PlayerDir = "N";
			break;
		case EActorDir::NE:
			PlayerDir = "NE";
			break;
		case EActorDir::NW:
			PlayerDir = "NW";
			break;
		case EActorDir::E:
			PlayerDir = "E";
			break;
		case EActorDir::W:
			PlayerDir = "W";
			break;
		case EActorDir::S:
			PlayerDir = "S";
			break;
		case EActorDir::SE:
			PlayerDir = "SE";
			break;
		case EActorDir::SW:
			PlayerDir = "SW";
			break;
		default:
			break;
		}
		UEngineDebugMsgWindow::PushMsg(std::format("PlayerDir : {}", PlayerDir));
	}

	CursorOFf();


}

