#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

// ���� :
class USpriteRenderer;
class AMouse : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	static FVector MousePos;
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


	//�÷��̾� �ֺ��� ����ٴҲ��� ���� �Լ� tick
};

