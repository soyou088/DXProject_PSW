#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class TitleCh : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	TitleCh();
	~TitleCh();

	// delete Function
	TitleCh(const TitleCh& _Other) = delete;
	TitleCh(TitleCh&& _Other) noexcept = delete;
	TitleCh& operator=(const TitleCh& _Other) = delete;
	TitleCh& operator=(TitleCh&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Ame;
	USpriteRenderer* Bae;
	USpriteRenderer* Gura;
	USpriteRenderer* Mumei;
	USpriteRenderer* Fauna;
	USpriteRenderer* Suisei;
	USpriteRenderer* Sana;
	USpriteRenderer* Shion;
	USpriteRenderer* Sora;
	USpriteRenderer* Subaru;
	USpriteRenderer* Mio;
	USpriteRenderer* Okayu;
	USpriteRenderer* Roboco;
	USpriteRenderer* Kronii;
	USpriteRenderer* Matsuri;
	USpriteRenderer* Mel;
	USpriteRenderer* Miko;
	USpriteRenderer* Ina;
	USpriteRenderer* Irys;
	USpriteRenderer* Kiara;
	USpriteRenderer* Korone;
	USpriteRenderer* Fubuki;
	USpriteRenderer* Haato;
	USpriteRenderer* Azki;
	USpriteRenderer* Calli;
	USpriteRenderer* Choco;
	USpriteRenderer* Aki;
	USpriteRenderer* Ayame;
	USpriteRenderer* Aqua;
};

