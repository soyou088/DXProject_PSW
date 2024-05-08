#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

// Ό³Έν :
class UBax : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	UBax();
	~UBax();

	// delete Function
	UBax(const UBax& _Other) = delete;
	UBax(UBax&& _Other) noexcept = delete;
	UBax& operator=(const UBax& _Other) = delete;
	UBax& operator=(UBax&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

