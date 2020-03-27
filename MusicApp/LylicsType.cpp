#include "LylicsType.h"


//생성자
LylicsType::LylicsType()
{
}

//소멸자
LylicsType::~LylicsType()
{
}
//////////// 연산자 오버로딩//////////
void LylicsType::operator=(const LylicsType & s)
{
	ID = s.ID;
	Lylics = s.Lylics;
}

bool LylicsType::operator==(LylicsType & s)
{
	return Lylics == s.Lylics;
}

bool LylicsType::operator>(const LylicsType & s)
{
	return Lylics > s.Lylics;
}

bool LylicsType::operator<(const LylicsType & s)
{
	return Lylics < s.Lylics;
}

bool LylicsType::operator>=(const LylicsType & s)
{
	return Lylics >= s.Lylics;
}

bool LylicsType::operator<=(const LylicsType & s)
{
	return Lylics <= s.Lylics;
}

string LylicsType::GetLylics()
{
	return Lylics;
}

string LylicsType::GetID()
{
	return ID;
}

void LylicsType::SetID(string inID)
{
	ID = inID;
}

void LylicsType::SetLylics(string inLylics)
{
	Lylics = inLylics;
}

ostream& operator <<(ostream& os, LylicsType& l)
{
	os << l.Lylics;
	return os;
}
