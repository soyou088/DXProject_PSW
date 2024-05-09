#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include "ContentsEnum.h"


// ���� :
class AWeapon;
class USpriteRenderer;
class APlayer : public AActor
{
	
	GENERATED_BODY(AActor)

public:
	static float4 PlayerColPos;
	static float4 PlayerPos;
	static bool IsLevelUp;
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;


	UStateManager State;

	EActorDir GetPlayerDir()
	{
		return PlayerDir;
	}


	float GetAngle()
	{
		return Angle;
	}

	float GetHp()
	{
		return Hp;
	}

	float GetAtk()
	{
		return Atk;
	}

	float GetAtkTime()
	{
		return AtkTime;
	}

	float GetSpeed()
	{
		return Speed;
	}

	template <typename WeaponType>
	void AddWeapon(std::string _Name);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	
	void SpawnRanged(float _DeltaTime);




	// ����
	//std::shared_ptr<AMultishot> Multishot;

private:
	USpriteRenderer* Renderer;
	USpriteRenderer* PlayerCursor;
	USpriteRenderer* Shadow;
	
	UCollision* Collision;

	std::string Name = "Kiara";

	std::shared_ptr<UCamera> Camera;
	EActorDir PlayerDir = EActorDir::E;
	float Hp = 100.0f;
	float Atk = 1;
	float CriRate = 0.05f;
	float Haste = 0.0f;
	float AtkTime = 1.0f;
	float Speed = 1.0f;
	float CalSpeed = ContentsValue::BaseSpeed * Speed;
	float LineSpeed = CalSpeed * 0.75f;
	float Exp = 0;

	std::vector<std::shared_ptr<AWeapon>> VPlayerWeapons;
	std::vector<std::shared_ptr<AWeapon>>::iterator VPlayerWeaponsIter = VPlayerWeapons.begin();

	float4 Color;
	float4 MousePos;
	float Angle;

	void CreatePlayerAnimation(std::string _Name);
	void PCursorDirCheck();
	void ChangeMouseAimAtkDir();
	void CursorDirChange();
	void CalStatus();


	float4 MouseCursor;
	//////////////////////// State
	void StateInit();

	void Die(float _DeltaTime);

	void Idle(float _DeltaTime);
	void IdleStart();
	void Run(float _DeltaTime);
	void RunStart();

	void KeyMove(float _DeltaTime, float4 _Dir, float _Speed);
	void KeyLineMove(float _DeltaTime, float4 _Dir1, float4 _Dir2);
};

