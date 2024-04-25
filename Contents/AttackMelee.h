#pragma once
#include "Weapon.h"

// Ό³Έν :
class AttackMelee : public AWeapon
{
	GENERATED_BODY(AWeapon)
public:
	// constrcuter destructer
	AttackMelee();
	~AttackMelee();

	// delete Function
	AttackMelee(const AttackMelee& _Other) = delete;
	AttackMelee(AttackMelee&& _Other) noexcept = delete;
	AttackMelee& operator=(const AttackMelee& _Other) = delete;
	AttackMelee& operator=(AttackMelee&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void SetKnifeTypeMeleeLocation(float _DistanceFromPlayer);

private:

};

