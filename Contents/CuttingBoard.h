#pragma once
#include "Bullet.h"
// Ό³Έν :
class ACuttingBoard : public ABullet
{
	GENERATED_BODY(ABullet)

public:
	// constrcuter destructer
	ACuttingBoard();
	~ACuttingBoard();

	// delete Function
	ACuttingBoard(const ACuttingBoard& _Other) = delete;
	ACuttingBoard(ACuttingBoard&& _Other) noexcept = delete;
	ACuttingBoard& operator=(const ACuttingBoard& _Other) = delete;
	ACuttingBoard& operator=(ACuttingBoard&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CheckHit();
private:
	UCollision* Collision;

};

