#include "ArtistType.h"

//생성자
ArtistType::ArtistType() {}

//소멸자
ArtistType::~ArtistType() {}

//가수명 얻기
string ArtistType::GetName()
{
	return s_Name;
}

//소속사 얻기
string ArtistType::GetEnt()
{
	return s_Ent;
}

void ArtistType::SetName(string inName)
{
	s_Name = inName;
}

//소속사 받기
void ArtistType::SetEnt(string inEnt)
{
	s_Ent = inEnt;
}

//곡목록 받기
void ArtistType::SetList(AvlTree<SimpleMusicType> inList)
{
	s_List = inList;
}

//레코드 받기
void ArtistType::SetRecord(string inName, string inEnt, AvlTree<SimpleMusicType> inList)
{
	SetName(inName);
	SetEnt(inEnt);
	SetList(inList);
}

//이름 키보드로부터 받기
void ArtistType::SetNameFromKB()
{
	cout << "\t가수: ";
	cin >> s_Name;
}
//소속사 키보드로부터 받기
void ArtistType::SetEntFromKB()
{
	cout << "\t소속사: ";
	cin >> s_Ent;
}
//레코드 키보드로부터 받기
void ArtistType::SetRecordFromKB()
{
	SetNameFromKB();
	SetEntFromKB();
}
//가수명 출력
void ArtistType::DisplayNameOnScreen()
{
	cout << "\t가수: " << s_Name;
}
//소속사 출력
void ArtistType::DisplayEntOnScreen()
{
	cout << "\t소속사: " << s_Ent;
}
//레코드 출력
void ArtistType::DisplayRecordOnScreen()
{
	DisplayNameOnScreen();
	cout << endl;
	DisplayEntOnScreen();
	cout << endl;
}
//연산자 = 오버로딩
void ArtistType::operator=(ArtistType & a)
{
	s_Name = a.s_Name;
	s_Ent = a.s_Ent;
	s_List = a.s_List;
}
//연산자 ==오버로딩
bool ArtistType::operator==(ArtistType & a)
{
	return this->s_Name == a.s_Name;
}
// 연산자 > 오버로딩
bool ArtistType::operator>(const ArtistType & a)
{
	return this->s_Name > a.s_Name;
}
// 연산자 < 오버로딩
bool ArtistType::operator<(const ArtistType & a)
{
	return this->s_Name < a.s_Name;
}
// 연산자 >= 오버로딩
bool ArtistType::operator>=(const ArtistType & a)
{
	return this->s_Name >= a.s_Name;
}
// 연산자 <= 오버로딩
bool ArtistType::operator<=(const ArtistType & a)
{
	return this->s_Name <= a.s_Name;
}
// 곡 목록에 곡을 추가
int ArtistType::AddList(SimpleMusicType& music)
{
	s_List.Add(music);
	return 1;
}
//곡 목록에서 곡을 삭제
int ArtistType::DeleteList(SimpleMusicType & music)
{
	if (s_List.DeleteItem(music))
	{
		if (s_List.GetLength() == 0)
		{
			return 1;
		}
		return 0;
	}
	return -1;
}

// 곡 목록의 길이를 얻기
int ArtistType::GetLengthOfList()
{
	return s_List.GetLength();
}

AvlTree<SimpleMusicType>* ArtistType::DetailInArtistList()
{
	return &s_List;
}

ostream& operator <<(ostream& os, ArtistType& a)
{
	cout << "\n\t--------------------------------" << endl;
	a.DisplayRecordOnScreen();
	cout << "\n\t--------------------------------" << endl;
	return os;
}
