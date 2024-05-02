#pragma once
#include "Melee.h"

class AKiara : public AMelee
{
	GENERATED_BODY(AMelee)

public:
	// constrcuter destructer
	AKiara();
	~AKiara();

	// delete Function
	AKiara(const AKiara& _Other) = delete;
	AKiara(AKiara&& _Other) noexcept = delete;
	AKiara& operator=(const AKiara& _Other) = delete;
	AKiara& operator=(AKiara&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CheckHit();

private:
	UCollision* CollisionR0;
	UCollision* CollisionR1;
	UCollision* CollisionC0;

};

