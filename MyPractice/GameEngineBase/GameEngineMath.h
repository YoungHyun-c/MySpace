#pragma once

// ���� :
class GameEngineMath
{
};

class float4
{
public:
	// �Ǽ��� �⺻������ 1.0f == 1.0f (�´ٰ�� ����)
	// == �� ���� �Ұ����ϴ�.
	// �ص� ��Ȯ���� �ʴ´�. �Ǽ��� ó���ϴ� ����� ���ʿ� ��Ȯ�ϱ� �ʱ� ������ 
	// �ε��Ҽ��� ������� �⺻������ ������ ������ �ְ�
	// + - ���� �� �� �����е��� �������� �ٸ� ���� ������ ���ɼ��� ����.
	// ���� ����� ����� �Ƹ� �ȵ� ����� �ϴ� ���̴�.
	// Player->GetPos() == Monster->GetPos();
	float X;
	float Y;
	float Z;
	float W;

	inline int iX() const
	{
		return static_cast<int>(X);
	}
	
protected:

private:

};

