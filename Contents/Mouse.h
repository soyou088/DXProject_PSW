#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

// 설명 :
class USpriteRenderer;
class AMouse : public AActor
{
	GENERATED_BODY(AActor)
public:
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
	void GetMouseCursorON();
	bool MouseCursorON = false;
	

	USpriteRenderer* MouseCursorRenderer;
private:


	float4 MousePos;

	//플레이어 주변을 따라다닐꺼다 나는 함수 tick
};

