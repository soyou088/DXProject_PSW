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

	// Camera 세팅
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -200.0f });
	AMouse::MousePos = GEngine->EngineWindow.GetScreenMousePos();
	float4 CameraPos = PlayerStartPos;
	CameraPos.Z = -500.0f;
	Camera->SetActorLocation(CameraPos);


	//Player 스폰
	Player = GetWorld()->SpawnActor<APlayer>("Player");
	Player->SetName("Kiara");
	Player->SetActorLocation(PlayerStartPos);
	
	//Mouse 스폰
	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");
		

	int a = 0;



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



//float4 APlayGameMode::RandomLocation(bool _Group)
//{
//	float4 MonsterPos = APlayer::PlayerPos;
//	MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 200.0f;
//	MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 200.0f;
//
//	return MonsterPos;
//}


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

void APlayGameMode::PlayDebugText()
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

void APlayGameMode::SpawnMonsterTimeSet(float _DeltaTime, float _SpawnBegin, float _SpawnEnd, float _Term,
	std::string _Name, float _Size, float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType,
	bool _Group, int _Quantity)
{
	if (PlayTime >= _SpawnBegin && PlayTime < _SpawnEnd)
	{
		if (SpawnTerm <= 0)
		{
			RandomSpawnMonster(_Name, _Size, _Hp, _Atk, _Speed, _Exp, _MoveType, _Group, _Quantity);
			SpawnTerm = _Term;
		}
		else
		{
			SpawnTerm -= _DeltaTime;
		}
	}
}

void APlayGameMode::RandomSpawnMonster(std::string _Name, float _Size, float _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType,
	bool _Group, int _Quantity)
{
	if (0 >= _Quantity)
	{
		MsgBoxAssert("스폰하려는 몬스터의 수가 0 이하 입니다.");
		return;
	}

	FVector GroupToPlayerDir;

	for (int i = 0; i < _Quantity; i++)
	{
		std::shared_ptr<AMonster> Monster;

		Monster = GetWorld()->SpawnActor<AMonster>(_Name);
		Monster->GetRenderer()->SetAutoSize(_Size, true);
		Monster->GetRenderer()->ChangeAnimation(_Name);
		Monster->SetMonsterStatus(_Hp, _Atk, _Speed, _Exp, _MoveType);
		FVector GroupPos = RandomLocation(_Group);
		Monster->SetActorLocation(GroupPos);
		if (true == _Group)
		{
			if (false == GroupSpawn)
			{
				GroupToPlayerDir = Monster->CreateGroupToPlayerDir();
				Monster->SetToPlayerDir(GroupToPlayerDir);
				GroupSpawn = true;
			}
			else
			{
				Monster->SetToPlayerDir(GroupToPlayerDir);
			}
		}
		else
		{
			FVector Dir = APlayer::PlayerPos - Monster->GetActorLocation();
			Dir = Dir.Normalize2DReturn();
			Monster->SetToPlayerDir(Dir);
		}
	}
	GroupSpawn = false;
}


float4 APlayGameMode::RandomLocation(bool _Group)
{
	float4 MonsterPos;
	// 뭉쳐서 나오지 않을 때
	if (false == _Group)
	{
		MonsterPos = APlayer::PlayerPos;

		while (MonsterPos.X > (APlayer::PlayerPos.X - 300.0f) && MonsterPos.X < (APlayer::PlayerPos.X + 300.0f))
		{
			MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
		}
		while (MonsterPos.Y > (APlayer::PlayerPos.Y - 250.0f) && MonsterPos.Y < (APlayer::PlayerPos.Y + 250.0f))
		{
			MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
		}
	}
	else
	{
		//뭉쳐서 나올 때 
		if (false == GroupSpawn)
		{
			GroupMonsterPos = APlayer::PlayerPos;

			while (GroupMonsterPos.X > (APlayer::PlayerPos.X - 300.0f) && GroupMonsterPos.X < (APlayer::PlayerPos.X + 300.0f))
			{
				GroupMonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
			}
			while (GroupMonsterPos.Y > (APlayer::PlayerPos.Y - 250.0f) && GroupMonsterPos.Y < (APlayer::PlayerPos.Y + 250.0f))
			{
				GroupMonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 100.0f;
			}
		}

		MonsterPos = GroupMonsterPos;

		MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 10.0f;
		MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-5.0f, 5.0f) * 10.0f;
	}

	return MonsterPos;
}


void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AMouse::MousePos = GEngine->EngineWindow.GetScreenMousePos();
	ContentsValue::PlayLevelMousePos = FVector{ APlayer::PlayerPos.X + AMouse::MousePos.X - 640, APlayer::PlayerPos.Y - AMouse::MousePos.Y + 360 };
	Mouse->SetActorLocation(ContentsValue::PlayLevelMousePos);
	
	InfinityGroundCheck();

	

	// 몬스터 스폰
	SpawnMonsterTimeSet(_DeltaTime, 0.0f, 20.0f, 5.0f,
		"Shrimp", 1.0f, 8.0f, 2.0f, 0.35f, 6.0f, EMonsterMoveType::Follow,
		false, 10);
	SpawnMonsterTimeSet(_DeltaTime, 0.0f, 20.0f, 10.0f,
		"Shrimp", 1.0f, 8.0f, 2.0f, 0.35f, 6.0f, EMonsterMoveType::Follow,
		true, 10);
	SpawnMonsterTimeSet(_DeltaTime, 20.0f, 40.0f, 5.0f,
		"Deadbeat", 1.0f, 40.0f, 4.0f, 0.4f, 7.0f, EMonsterMoveType::Follow,
		false, 5);
	SpawnMonsterTimeSet(_DeltaTime, 40.0f, 60.0f, 5.0f,
		"Takodachi", 1.0f, 80.0f, 4.0f, 0.4f, 8.0f, EMonsterMoveType::Follow);
	SpawnMonsterTimeSet(_DeltaTime, 60.0f, 80.0f, 5.0f,
		"KFP", 1.0f, 20.0f, 2.0f, 1.0f, 3.0f, EMonsterMoveType::StraightToPlayer,
		true, 10);

	PlayTime += _DeltaTime;


	CursorOFF();
	PlayDebugText();

}


void APlayGameMode::CursorOFF()
{
	ShowCursor(FALSE);
}
