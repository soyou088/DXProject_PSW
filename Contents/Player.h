#pragma once
#include "Mouse.h"
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// 설명 :
class USpriteRenderer;
class APlayer : public AActor
{
	GENERATED_BODY(AActor)

public:
	static FVector PlayerPos;
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
		return DirState;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	std::shared_ptr<AMouse> Mouse;
	

	void PCursorDirCheck();
	EActorDir DirState = EActorDir::None;

private:
	USpriteRenderer* Renderer;
	USpriteRenderer* PlayerCursor;
	UCollision* Collision;

	std::string Name = "Ame";
	void CreatePlayerAnimation(std::string _Name);



	float4 Color;
	float4 MousePos;

	bool MouseState = false;

	float Speed = 300.0f;
	float LineSpeed = Speed * 0.75f;

	float4 MouseCursor;
	//////////////////////// State
	void StateInit();

	void Die(float _DeltaTime);

	void Idle(float _DeltaTime);
	void IdleStart();
	void Run(float _DeltaTime);
	void RunStart();


	//나는 마우스 방향을 가리키는 이미지 하나가 있었으면 좋겠다
};

