#include "SimpleMusicType.h"


//생성자
SimpleMusicType::SimpleMusicType()
{
	s_ID = "";
	s_Title = "";
}
//소멸자
SimpleMusicType::~SimpleMusicType() {}
//연산자 = 오버로딩
void SimpleMusicType::operator=(SimpleMusicType & s)
{
	s_ID = s.s_ID;
	s_Title = s.s_Title;
}
// 연산자 == 오버로딩
bool SimpleMusicType::operator==(SimpleMusicType & s)
{
	return this->s_ID == s.s_ID;
}
//연산자 > 오버로딩
bool SimpleMusicType::operator>(const SimpleMusicType & s)
{
	return this->s_ID > s.s_ID;
}
//연산자 < 오버로딩
bool SimpleMusicType::operator<(const SimpleMusicType & s)
{
	return this->s_ID < s.s_ID;
}
//연산자 >= 오버로딩
bool SimpleMusicType::operator>=(const SimpleMusicType & s)
{
	return this->s_ID >= s.s_ID;
}
//연산자 <= 오버로딩
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

//넘버 받기
void SimpleMusicType::SetID(string inID)
{
	s_ID = inID;
}
//곡명 받기
void SimpleMusicType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}
// 곡 정보 받기
void SimpleMusicType::SetSimpleMusic(string inID, string inTitle)
{
	s_ID = inID;
	s_Title = inTitle;
}
//곡 넘버 키보드로부터 받기
void SimpleMusicType::SetIDFromKB()
{
	cout << "\n\t넘버: ";
	cin >> s_ID;
}
// 곡명 키보드로부터 받기
void SimpleMusicType::SetTitleFromKB()
{
	cout << "\n\t곡명: ";
	cin >> s_Title;
}
// 곡 정보 키보드로부터 받기
void SimpleMusicType::SetSimpleMusicFromKB()
{
	SetIDFromKB();
	SetTitleFromKB();
}
// 넘버 얻기
string SimpleMusicType::GetID()
{
	return s_ID;
}
// 곡명 얻기
string SimpleMusicType::GetTitle()
{
	return s_Title;
}
//넘버 출력
void SimpleMusicType::DisplayIDOnScreen()
{
	cout << "\n\t넘버: " << s_ID;
}
// 곡명 출력
void SimpleMusicType::DisplayTitleOnScreen()
{
	cout << "\n\t곡명: " << s_Title;
}
//정보 출력
void SimpleMusicType::DisplayRecordOnScreen()
{
	DisplayIDOnScreen();
	DisplayTitleOnScreen();
}
