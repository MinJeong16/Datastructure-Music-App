#include "PlayType.h"
//������
PlayType::PlayType()
{
}
//�Ҹ���
PlayType::~PlayType() {}
//�ѹ� �ޱ�
void PlayType::SetPlayID(string inid)
{
	s_ID = inid;
}
//��� �ޱ�
void PlayType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}
//������ �ޱ�
void PlayType::SetArtist(string inArtist)
{
	s_Artist = inArtist;
}
//���� �ޱ�
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
//�� ���� ���
void PlayType::Display()
{
	cout << "\t�ѹ�: " << s_ID << endl;
	cout << "\t����: " << s_Title << endl;
	cout << "\t����: " << s_Artist << endl;
	cout << "\t����: " << s_Lylics;
}
//������ = �����ε�
void PlayType::operator=(const PlayType & p)
{
	s_ID = p.s_ID;
	s_Title = p.s_Title;
	s_Artist = p.s_Artist;
	s_Lylics = p.s_Lylics;
}
// ������ == �����ε�
bool PlayType::operator==(PlayType & p)
{
	return this->s_ID == p.s_ID;
}
// ������ > �����ε�
bool PlayType::operator>(const PlayType & p)
{
	return this->s_ID > p.s_ID;
}
// ������ < �����ε�
bool PlayType::operator<(const PlayType & p)
{
	return this->s_ID < p.s_ID;
}
// ������ >= �����ε�
bool PlayType::operator>=(const PlayType & p)
{
	return this->s_ID >= p.s_ID;
}
// ������ <= �����ε�
bool PlayType::operator<=(const PlayType & p)
{
	return this->s_ID <= p.s_ID;
}
