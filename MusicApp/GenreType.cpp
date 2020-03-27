#include "GenreType.h"
//������
GenreType::GenreType() {}
//�Ҹ���
GenreType::~GenreType() {}
//������ = �����ε�
void GenreType::operator=(GenreType & s)
{
	s_Genre = s.s_Genre;
	s_GMusicList = s.s_GMusicList;
}
// ������ == �����ε�
bool GenreType::operator==(GenreType & s)
{
	return this->s_Genre == s.s_Genre;
}
// ������ > �����ε�
bool GenreType::operator>(const GenreType & s)
{
	return this->s_Genre > s.s_Genre;
}
// ������ < �����ε�
bool GenreType::operator<(const GenreType & s)
{
	return this->s_Genre < s.s_Genre;
}
//������ >= �����ε�
bool GenreType::operator>=(const GenreType & s)
{
	return this->s_Genre >= s.s_Genre;
}
// ������ <= �����ε�
bool GenreType::operator<=(const GenreType & s)
{
	return this->s_Genre <= s.s_Genre;
}
// �帣 ���
string GenreType::GetGenre()
{
	return s_Genre;
}
// �帣 �ޱ�
void GenreType::SetGenre(string inGenre)
{
	s_Genre = inGenre;
}
// �帣�� �� ��� �ޱ�
void GenreType::SetMusicInGenre(AvlTree<SimpleMusicType> g_List)
{
	s_GMusicList = g_List;
}
// �帣�� Ű����κ��� �ޱ�
void GenreType::SetGenreFromKB()
{
	cout << "\t�帣: ";
	cin >> s_Genre;
}
// �帣�� ����ϱ�
void GenreType::DisplayGenreOnScreen()
{
	cout << "\t�帣: " << s_Genre << endl;
}

// �帣�� �� ��Ͽ� ���� �߰�
int GenreType::AddMusicInGenre(SimpleMusicType & music)
{
	s_GMusicList.Add(music);
	return 1;
}
// �帣�� �� ��Ͽ��� ���� ����
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
//�帣�� �� ����� ���̸� ���
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