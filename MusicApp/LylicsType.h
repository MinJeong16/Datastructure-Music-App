#ifndef _LYLICS_TYPE_
#define _LYLICS_TYPE_
#include <iostream>
#include <string>
#include "SimpleMusicType.h"

using namespace std;
class LylicsType
{
public:
	//생성자
	LylicsType();
	//소멸자
	~LylicsType();

	//연산자 = 정의
	void operator = (const LylicsType &s);
	// 연산자 == 정의
	bool operator == (LylicsType &s);
	// 연산자 > 정의
	bool operator > (const LylicsType &s);
	// 연산자 < 정의
	bool operator < (const LylicsType &s);
	// 연산자 >= 정의
	bool operator >= (const LylicsType &s);
	// 연산자 <= 정의
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
