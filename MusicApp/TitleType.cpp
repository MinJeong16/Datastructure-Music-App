#include "TitleType.h"


//생성자
TitleType::TitleType()
{
}

//소멸자
TitleType::~TitleType()
{
}
/////////// 연산자 오버로딩 ////////
void TitleType::operator=(TitleType & t)
{
	s_Title = t.s_Title;
	s_TitleList = t.s_TitleList;
}

bool TitleType::operator>(TitleType & t)
{
	return s_Title > t.s_Title;
}

bool TitleType::operator<(TitleType & t)
{
	return s_Title < t.s_Title;
}

bool TitleType::operator>=(TitleType & t)
{
	return s_Title >= t.s_Title;
}

bool TitleType::operator<=(TitleType & t)
{
	return s_Title <= t.s_Title;
}

bool TitleType::operator==(TitleType & t)
{
	return s_Title == t.s_Title;
}

bool TitleType::operator!=(TitleType & t)
{
	return s_Title != t.s_Title;
}

// 곡명을 리턴
string TitleType::GetTitle()
{
	return s_Title;
}
//곡명을 설정
void TitleType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}

void TitleType::SetTitleFromKB()
{
	cout << "\t곡명: ";
	cin >> s_Title;
}

void TitleType::DisplayTitleOnScreen()
{
	cout << "\t곡명: " << s_Title << endl;
}

void TitleType::AddArtistInList(string & data)
{
	s_TitleList.Add(data);
}

int TitleType::DeleteArtistInList(string & data)
{
	if (s_TitleList.DeleteItem(data))
	{
		if (s_TitleList.GetLength() == 0)
		{
			return 1;
		}
		return 0;
	}
	return -1;
}

AvlTree<string>* TitleType::DetailTitleListOnScreen()
{
	return &s_TitleList;
}

ostream& operator<<(ostream& os, TitleType& t)
{
	t.DisplayTitleOnScreen();
	return os;
}