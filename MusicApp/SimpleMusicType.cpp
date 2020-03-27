#include "SimpleMusicType.h"


//������
SimpleMusicType::SimpleMusicType()
{
	s_ID = "";
	s_Title = "";
}
//�Ҹ���
SimpleMusicType::~SimpleMusicType() {}
//������ = �����ε�
void SimpleMusicType::operator=(SimpleMusicType & s)
{
	s_ID = s.s_ID;
	s_Title = s.s_Title;
}
// ������ == �����ε�
bool SimpleMusicType::operator==(SimpleMusicType & s)
{
	return this->s_ID == s.s_ID;
}
//������ > �����ε�
bool SimpleMusicType::operator>(const SimpleMusicType & s)
{
	return this->s_ID > s.s_ID;
}
//������ < �����ε�
bool SimpleMusicType::operator<(const SimpleMusicType & s)
{
	return this->s_ID < s.s_ID;
}
//������ >= �����ε�
bool SimpleMusicType::operator>=(const SimpleMusicType & s)
{
	return this->s_ID >= s.s_ID;
}
//������ <= �����ε�
bool SimpleMusicType::operator<=(const SimpleMusicType & s)
{
	return this->s_ID <= s.s_ID;
}
bool SimpleMusicType::operator!=(const SimpleMusicType & s)
{
	return s_ID != s.s_ID;
}

ostream& operator<<(ostream& os, SimpleMusicType& s)
{
	s.DisplayRecordOnScreen();
	return os;
}

//�ѹ� �ޱ�
void SimpleMusicType::SetID(string inID)
{
	s_ID = inID;
}
//��� �ޱ�
void SimpleMusicType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}
// �� ���� �ޱ�
void SimpleMusicType::SetSimpleMusic(string inID, string inTitle)
{
	s_ID = inID;
	s_Title = inTitle;
}
//�� �ѹ� Ű����κ��� �ޱ�
void SimpleMusicType::SetIDFromKB()
{
	cout << "\n\t�ѹ�: ";
	cin >> s_ID;
}
// ��� Ű����κ��� �ޱ�
void SimpleMusicType::SetTitleFromKB()
{
	cout << "\n\t���: ";
	cin >> s_Title;
}
// �� ���� Ű����κ��� �ޱ�
void SimpleMusicType::SetSimpleMusicFromKB()
{
	SetIDFromKB();
	SetTitleFromKB();
}
// �ѹ� ���
string SimpleMusicType::GetID()
{
	return s_ID;
}
// ��� ���
string SimpleMusicType::GetTitle()
{
	return s_Title;
}
//�ѹ� ���
void SimpleMusicType::DisplayIDOnScreen()
{
	cout << "\n\t�ѹ�: " << s_ID;
}
// ��� ���
void SimpleMusicType::DisplayTitleOnScreen()
{
	cout << "\n\t���: " << s_Title;
}
//���� ���
void SimpleMusicType::DisplayRecordOnScreen()
{
	DisplayIDOnScreen();
	DisplayTitleOnScreen();
}
