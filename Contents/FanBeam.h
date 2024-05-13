#pragma once
#include "Melee.h"


class AFanBeam : public AMelee
{
	GENERATED_BODY(AMelee)

public:
	// constrcuter destructer
	AFanBeam();
	~AFanBeam();

	// delete Function
	AFanBeam(const AFanBeam& _Other) = delete;
	AFanBeam(AFanBeam&& _Other) noexcept = delete;
	AFanBeam& operator=(const AFanBeam& _Other) = delete;
	AFanBeam& operator=(AFanBeam&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CheckHit();
private:
	UCollision* Collision;

};