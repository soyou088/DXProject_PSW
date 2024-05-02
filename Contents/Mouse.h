#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

// Ό³Έν :
class USpriteRenderer;
class AMouse : public AActor
{
	GENERATED_BODY(AActor)
public:
	static FVector MousePos;
	static bool MouseCursorON;

	// constrcuter destructer

	AMouse();
	~AMouse();

	// delete Function
	AMouse(const AMouse& _Other) = delete;
	AMouse(AMouse&& _Other) noexcept = delete;
	AMouse& operator=(const AMouse& _Other) = delete;
	AMouse& operator=(AMouse&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CursorOFf();
	void CurCursor();
	void CheckCurCursor();

private:
	USpriteRenderer* MouseCursorRenderer;
	UCollision* Collision;


};

