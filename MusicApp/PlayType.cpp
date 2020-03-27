#include "PlayType.h"
//생성자
PlayType::PlayType()
{
}
//소멸자
PlayType::~PlayType() {}
//넘버 받기
void PlayType::SetPlayID(string inid)
{
	s_ID = inid;
}
//곡명 받기
void PlayType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}
//가수명 받기
void PlayType::SetArtist(string inArtist)
{
	s_Artist = inArtist;
}
//가사 받기
void PlayType::SetLylics(string inLylics)
{
	s_Lylics = inLylics;
}
int PlayType::saveitem(ofstream& fout)
{
	fout << endl;
	fout << s_ID << ' ';
	fout << s_Title << ' ';
	fout << s_Artist << ' ';
	fout << s_Lylics << ' ';

	return 1;
}
void PlayType::readitem(ifstream & fin)
{
	fin >> s_ID;
	fin >> s_Title;
	fin >> s_Artist;
	getline(fin, s_Lylics);

}
//곡 정보 출력
void PlayType::Display()
{
	cout << "\t넘버: " << s_ID << endl;
	cout << "\t제목: " << s_Title << endl;
	cout << "\t가수: " << s_Artist << endl;
	cout << "\t가사: " << s_Lylics;
}
//연산자 = 오버로딩
void PlayType::operator=(const PlayType & p)
{
	s_ID = p.s_ID;
	s_Title = p.s_Title;
	s_Artist = p.s_Artist;
	s_Lylics = p.s_Lylics;
}
// 연산자 == 오버로딩
bool PlayType::operator==(PlayType & p)
{
	return this->s_ID == p.s_ID;
}
// 연산자 > 오버로딩
bool PlayType::operator>(const PlayType & p)
{
	return this->s_ID > p.s_ID;
}
// 연산자 < 오버로딩
bool PlayType::operator<(const PlayType & p)
{
	return this->s_ID < p.s_ID;
}
// 연산자 >= 오버로딩
bool PlayType::operator>=(const PlayType & p)
{
	return this->s_ID >= p.s_ID;
}
// 연산자 <= 오버로딩
bool PlayType::operator<=(const PlayType & p)
{
	return this->s_ID <= p.s_ID;
}
