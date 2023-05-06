#pragma once

// Ό³Έν :
class int2
{
public:
	int X = 0;
	int Y = 0;


	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}



protected:

private:
	
};

