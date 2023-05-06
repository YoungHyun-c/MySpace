#pragma once

// ���� :
class EndingLevel
{
public:
	// constructer destructer
	EndingLevel();
	~EndingLevel();

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator = (const EndingLevel& _Other) = delete;
	EndingLevel& operator = (EndingLevel&& _Other) noexcept = delete;

protected:

private:

};
