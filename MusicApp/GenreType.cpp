#include "GenreType.h"
//생성자
GenreType::GenreType() {}
//소멸자
GenreType::~GenreType() {}
//연산자 = 오버로딩
void GenreType::operator=(GenreType & s)
{
	s_Genre = s.s_Genre;
	s_GMusicList = s.s_GMusicList;
}
// 연산자 == 오버로딩
bool GenreType::operator==(GenreType & s)
{
	return this->s_Genre == s.s_Genre;
}
// 연산자 > 오버로딩
bool GenreType::operator>(const GenreType & s)
{
	return this->s_Genre > s.s_Genre;
}
// 연산자 < 오버로딩
bool GenreType::operator<(const GenreType & s)
{
	return this->s_Genre < s.s_Genre;
}
//연산자 >= 오버로딩
bool GenreType::operator>=(const GenreType & s)
{
	return this->s_Genre >= s.s_Genre;
}
// 연산자 <= 오버로딩
bool GenreType::operator<=(const GenreType & s)
{
	return this->s_Genre <= s.s_Genre;
}
// 장르 얻기
string GenreType::GetGenre()
{
	return s_Genre;
}
// 장르 받기
void GenreType::SetGenre(string inGenre)
{
	s_Genre = inGenre;
}
// 장르의 곡 목록 받기
void GenreType::SetMusicInGenre(AvlTree<SimpleMusicType> g_List)
{
	s_GMusicList = g_List;
}
// 장르명 키보드로부터 받기
void GenreType::SetGenreFromKB()
{
	cout << "\t장르: ";
	cin >> s_Genre;
}
// 장르명 출력하기
void GenreType::DisplayGenreOnScreen()
{
	cout << "\t장르: " << s_Genre << endl;
}

// 장르의 곡 목록에 곡을 추가
int GenreType::AddMusicInGenre(SimpleMusicType & music)
{
	s_GMusicList.Add(music);
	return 1;
}
// 장르의 곡 목록에서 곡을 삭제
int GenreType::DeleteMusicInGenre(SimpleMusicType & music)
{
	if (s_GMusicList.DeleteItem(music))
	{
		if (s_GMusicList.GetLength() == 0)
		{
			return 1;
		}
		return 0;
	}
	return -1;
}
//장르의 곡 목록의 길이를 얻기
int GenreType::GetLengthOfList()
{
	return s_GMusicList.GetLength();
}

AvlTree<SimpleMusicType>* GenreType::DetailMusicInGenreList()
{
	return &s_GMusicList;
}

ostream& operator <<(ostream& os, GenreType& g)
{
	cout << "\n\t--------------------------------" << endl;
	g.DisplayGenreOnScreen();
	cout << "\n\t--------------------------------" << endl;
	return os;
}