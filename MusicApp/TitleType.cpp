#include "TitleType.h"


//������
TitleType::TitleType()
{
}

//�Ҹ���
TitleType::~TitleType()
{
}
/////////// ������ �����ε� ////////
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

// ����� ����
string TitleType::GetTitle()
{
	return s_Title;
}
//����� ����
void TitleType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}

void TitleType::SetTitleFromKB()
{
	cout << "\t���: ";
	cin >> s_Title;
}

void TitleType::DisplayTitleOnScreen()
{
	cout << "\t���: " << s_Title << endl;
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