#pragma once
#include "Mouse.h"
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>


// ���� :
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	std::shared_ptr<AMouse> Mouse;

private:
	USpriteRenderer* Renderer;
	USpriteRenderer* PlayerCursor;

	float4 Color;
	float4 MousePos;

	float4 MouseCursor;
	//////////////////////// State
	void StateInit();

	void Die(float _DeltaTime);

	void Idle(float _DeltaTime);
	void IdleStart();
	void Run(float _DeltaTime);
	void RunStart();


	//���� ���콺 ������ ����Ű�� �̹��� �ϳ��� �־����� ���ڴ�
};

