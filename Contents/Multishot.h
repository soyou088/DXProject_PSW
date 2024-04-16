#pragma once

// Ό³Έν :
class AMultishot
{
public:
	// constrcuter destructer
	AMultishot();
	~AMultishot();

	// delete Function
	AMultishot(const AMultishot& _Other) = delete;
	AMultishot(AMultishot&& _Other) noexcept = delete;
	AMultishot& operator=(const AMultishot& _Other) = delete;
	AMultishot& operator=(AMultishot&& _Other) noexcept = delete;

protected:

private:

};

