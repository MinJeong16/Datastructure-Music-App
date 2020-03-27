#include "LylicsType.h"


//������
LylicsType::LylicsType()
{
}

//�Ҹ���
LylicsType::~LylicsType()
{
}
//////////// ������ �����ε�//////////
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
