#pragma once

// Ό³Έν :
class ContentCore
{
public:
	// constructer destructer
	ContentCore();
	~ContentCore();

	// delete Function
	ContentCore(const ContentCore& _Other) = delete;
	ContentCore(ContentCore&& _Other) noexcept = delete;
	ContentCore& operator = (const ContentCore& _Other) = delete;
	ContentCore& operator = (ContentCore&& _Other) noexcept = delete;

protected:

private:

};

