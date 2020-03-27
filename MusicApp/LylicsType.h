#ifndef _LYLICS_TYPE_
#define _LYLICS_TYPE_
#include <iostream>
#include <string>
#include "SimpleMusicType.h"

using namespace std;
class LylicsType
{
public:
	//������
	LylicsType();
	//�Ҹ���
	~LylicsType();

	//������ = ����
	void operator = (const LylicsType &s);
	// ������ == ����
	bool operator == (LylicsType &s);
	// ������ > ����
	bool operator > (const LylicsType &s);
	// ������ < ����
	bool operator < (const LylicsType &s);
	// ������ >= ����
	bool operator >= (const LylicsType &s);
	// ������ <= ����
	bool operator <= (const LylicsType &s);

	friend ostream& operator <<(ostream& os, LylicsType& l);

	string GetLylics();
	string GetID();
	void SetID(string inID);
	void SetLylics(string inLylics);

private:
	string ID;
	string Lylics;
};

#endif
