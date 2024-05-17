#include "PreCompile.h"
#include "PlayGameMode.h"
#include "ContentsValue.h"
#include "NomalMonster.h"
#include "UIManager.h"
#include "Box.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Camera.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineBase/EngineRandom.h>
#include "Fubuzilla.h"

std::shared_ptr<APlayer> APlayGameMode::MainPlayer = nullptr;
std::shared_ptr<class UIManager> APlayGameMode::PlayUIManager;
std::shared_ptr<class UBox> APlayGameMode::UIBox;
bool APlayGameMode::ESCPauseON = false;
bool APlayGameMode::LevelUpPauseON = false;
bool APlayGameMode::IsPause = false;
bool APlayGameMode::IsPlayStart = true;


APlayGameMode::APlayGameMode()
{
	InputOn();

}

APlayGameMode::~APlayGameMode()
{
	Sound.Off();
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	std::shared_ptr<UEngineTexture> Tex = UEngineTexture::FindRes("Holo_map_03.png");

	CurIndex = { 0, 0 };
	float4 PlayerStartPos = IndexToCenterPos(CurIndex);

	// Camera ����
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -200.0f });
	AMouse::MousePos = GEngine->EngineWindow.GetScreenMousePos();
	float4 CameraPos = PlayerStartPos;
	CameraPos.Z = -500.0f;
	Camera->SetActorLocation(CameraPos);


	//Player ����
	Player = GetWorld()->SpawnActor<APlayer>("Player");
	Player->SetName("Kiara");
	Player->SetActorLocation(PlayerStartPos);
	MainPlayer = Player;
	Player->State.ChangeState("Idle");

	//Mouse ����
	Mouse = GetWorld()->SpawnActor<AMouse>("Mouse");
	AMouse::MouseCursorON = false;
	AMouse::MousePos = GEngine->EngineWindow.GetScreenMousePos();
	Mouse->SetActorLocation(AMouse::MousePos);

	//Object ����
	UIBox = GetWorld()->SpawnActor<UBox>("Box");
	
	//UI ����
	PlayUIManager = GetWorld()->SpawnActor<UIManager>("UIManager");

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

	Sound = UEngineSound::SoundPlay("StageOneBGM.mp3");
	Sound.On();


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

void APlayGameMode::SpawnNomalMonsterTimeSet(float _DeltaTime, float _SpawnBegin, float _SpawnEnd, float _Term, float& _SpawnTerm,
	std::string _Name, float _Size, int _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType,
	bool _WillTimeOutDestroy, float _TimeOutDestoryDelay, bool _Group, int _Quantity)
{
	if (PlayTime >= _SpawnBegin && PlayTime < _SpawnEnd)
	{
		if (0.0f >= _SpawnTerm)
		{
			RandomSpawnNomalMonster(_Name, _Size, _Hp, _Atk, _Speed, _Exp, _MoveType, _Group, _Quantity, _WillTimeOutDestroy, _TimeOutDestoryDelay);
			_SpawnTerm = _Term;
		}
		else
		{
			_SpawnTerm -= PlayDeltaTime;
		}
	}
}

void APlayGameMode::SpawnBossMonsterTimeSet(float _SpawnTime, std::string _Name)
{
	if (PlayTime >= _SpawnTime && PlayTime < (_SpawnTime + 1.0f))
	{
		if (0.0f >= BossSpawn)
		{
			if (UEngineString::ToUpper("Fubuzilla") == UEngineString::ToUpper(_Name))
			{
				std::shared_ptr<AFubuzilla> Boss = GetWorld()->SpawnActor<AFubuzilla>("Fubuzilla");
				Boss->SetActorLocation(RandomLocation());

				BossSpawn = 1.5f;
			}
		}
		else if (PlayTime >= (_SpawnTime + 1.0f) && PlayTime < (_SpawnTime + 2.0f))
		{
			BossSpawn = 0.0f;
		}
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
		UEngineDebugMsgWindow::PushMsg(std::format("Angle : {}", Player->GetAngle()));
}




std::shared_ptr<ANomalMonster> APlayGameMode::SpawnNomalMonster(std::string _Name, float _Size, int _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType, bool _WillTimeOutDestroy, float _TimeOutDestoryDelay)
{
	std::shared_ptr<ANomalMonster> Monster;

	Monster = GetWorld()->SpawnActor<ANomalMonster>(_Name);
	Monster->GetRenderer()->SetAutoSize(_Size * ContentsValue::MultipleSize, true);
	Monster->GetRenderer()->ChangeAnimation(_Name);
	Monster->SetMonsterStatus(_Hp, _Atk, _Speed, _Exp, _MoveType, _WillTimeOutDestroy, _TimeOutDestoryDelay);
	Monster->GetCollosion()->SetScale({ _Size * 16.0f * ContentsValue::MultipleSize, _Size * 16.0f * ContentsValue::MultipleSize });
	Monster->GetCollosion()->SetPosition({ Monster->GetActorLocation().X, Monster->GetActorLocation().Y + (_Size * 10.0f * ContentsValue::MultipleSize) });
	Monster->GetSavedRenderer()->SetPosition({ Monster->GetActorLocation().X, Monster->GetActorLocation().Y + (50.0f * ContentsValue::MultipleSize) });
	Monster->GetOverCheckCollision()->SetScale({ _Size * 16.0f * ContentsValue::MultipleSize, _Size * 32.0f * ContentsValue::MultipleSize });
	Monster->GetOverCheckCollision()->SetPosition({ Monster->GetActorLocation().X, Monster->GetActorLocation().Y + (_Size * 18.0f * ContentsValue::MultipleSize) });

	return Monster;
}

void APlayGameMode::RandomSpawnNomalMonster(std::string _Name, float _Size, int _Hp, float _Atk, float _Speed, float _Exp, EMonsterMoveType _MoveType,
	bool _WillTimeOutDestroy, float _TimeOutDestoryDelay, bool _Group, int _Quantity)
{
	if (0 >= _Quantity)
	{
		MsgBoxAssert("�����Ϸ��� ������ ���� 0 ���� �Դϴ�.");
		return;
	}

	FVector GroupToPlayerDir;

	for (int i = 0; i < _Quantity; i++)
	{
		std::shared_ptr<ANomalMonster> Monster = SpawnNomalMonster(_Name, _Size, _Hp, _Atk, _Speed, _Exp, _MoveType, _WillTimeOutDestroy, _TimeOutDestoryDelay);

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
	// ���ļ� ������ ���� ��
	if (false == _Group)
	{
		MonsterPos = APlayer::PlayerPos;

		while (MonsterPos.X > (APlayer::PlayerPos.X - 350.0f) && MonsterPos.X < (APlayer::PlayerPos.X + 350.0f))
		{
			MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-450.0f, 450.0f);
		}
		while (MonsterPos.Y > (APlayer::PlayerPos.Y - 300.0f) && MonsterPos.Y < (APlayer::PlayerPos.Y + 300.0f))
		{
			MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-450.0f, 450.0f);
		}
	}
	else
	{
		//���ļ� ���� �� 
		if (false == GroupSpawn)
		{
			GroupMonsterPos = APlayer::PlayerPos;

			while (GroupMonsterPos.X > (APlayer::PlayerPos.X - 350.0f) && GroupMonsterPos.X < (APlayer::PlayerPos.X + 350.0f))
			{
				GroupMonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-450.0f, 450.0f);
			}
			while (GroupMonsterPos.Y > (APlayer::PlayerPos.Y - 300.0f) && GroupMonsterPos.Y < (APlayer::PlayerPos.Y + 300.0f))
			{
				GroupMonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-450.0f, 450.0f);
			}
		}

		MonsterPos = GroupMonsterPos;

		MonsterPos.X += UEngineRandom::MainRandom.RandomFloat(-50.0f, 50.0f);
		MonsterPos.Y += UEngineRandom::MainRandom.RandomFloat(-50.0f, 50.0f);
	}

	return MonsterPos;
}
void APlayGameMode::Pause(float _DeltaTime)
{

	if (true == IsDown(VK_ESCAPE))
	{
		if (true == IsPause)
		{
			IsPause = false;
			GEngine->SetOrderTimeScale(0, 1.f);
			ESCPauseON = false;
		}
		else
		{
			IsPause = true;
			ESCPauseON = true;
		}
	}

	if (false == IsPause)
	{
		PlayDeltaTime = _DeltaTime;

	}
	else
	{
		PlayDeltaTime = 0.0f;
		GEngine->SetOrderTimeScale(0, 0.f);
	}
	PlayTime += PlayDeltaTime;
	_DeltaTime = 0.0f;


}

void APlayGameMode::LevelUpPause(float _DeltaTime)
{

	if (true == IsDown('L'))
	{
		if (true == IsPause)
		{
			IsPause = false;
			GEngine->SetOrderTimeScale(0, 1.f);
			LevelUpPauseON = false;
		}
		else
		{
			IsPause = true;
			LevelUpPauseON = true;
		}
	}

	if (false == IsPause)
	{
		PlayDeltaTime = _DeltaTime;

	}
	else
	{
		PlayDeltaTime = 0.0f;
		GEngine->SetOrderTimeScale(0, 0.f);
	}
	PlayTime += PlayDeltaTime;
	_DeltaTime = 0.0f;



}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Pause(_DeltaTime);
	LevelUpPause(_DeltaTime);

	ContentsValue::PlayLevelMousePos = FVector{ APlayer::PlayerColPos.X + AMouse::MousePos.X - 645, APlayer::PlayerColPos.Y - AMouse::MousePos.Y + 400 };

	InfinityGroundCheck();

	if (true == IsPlayStart)
	{
		IsPlayStart = false;
	}
	SpawnNomalMonsterTimeSet(PlayTime, 0.5f, 20.0f, 5.0f, SpawnTerm1,
		"Shrimp", 1.0f, 8, 2.0f, 0.35f, 6.0f, EMonsterMoveType::Follow,
		false, 10);
	SpawnNomalMonsterTimeSet(PlayTime, 0.5f, 20.0f, 10.0f, SpawnTerm2,
		"Shrimp", 1.0f, 8, 2.0f, 0.35f, 6.0f, EMonsterMoveType::Follow,
		true, 10);
	SpawnNomalMonsterTimeSet(PlayTime, 20.0f, 40.0f, 5.0f, SpawnTerm1,
		"Deadbeat", 1.0f, 40, 4.0f, 0.4f, 7.0f, EMonsterMoveType::Follow,
		false, 5);
	SpawnNomalMonsterTimeSet(PlayTime, 40.0f, 60.0f, 5.0f, SpawnTerm1,
		"Takodachi", 1.0f, 80, 4.0f, 0.4f, 8.0f);
	SpawnNomalMonsterTimeSet(PlayTime, 60.0f, 80.0f, 5.0f, SpawnTerm1,
		"KFP", 1.0f, 20, 2.0f, 1.0f, 3.0f, EMonsterMoveType::StraightToPlayer,
		true, 20.0f, true, 10);
	SpawnBossMonsterTimeSet(5.0f, "Fubuzilla");

	PlayDebugText();

}

void APlayGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void APlayGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}


void APlayGameMode::CursorOFF()
{
	ShowCursor(FALSE);
}
