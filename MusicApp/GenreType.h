#ifndef _GENRE_TYPE_
#define _GENRE_TYPE_
#include <iostream>
#include <string>
#include "AvlTree.h"
#include "SimpleMusicType.h"

using namespace std;
class GenreType
{
public:
	//������
	GenreType();
	//�Ҹ���
	~GenreType();

	//������ = ����
	void operator = (GenreType &s);
	// ������ == ����
	bool operator == (GenreType &s);
	// ������ > ����
	bool operator > (const GenreType &s);
	// ������ < ����
	bool operator < (const GenreType &s);
	// ������ >= ����
	bool operator >= (const GenreType &s);
	// ������ <= ����
	bool operator <= (const GenreType &s);

	friend ostream& operator <<(ostream& os, GenreType& g);

	//�帣 ���
	string GetGenre();
	//�帣 �ޱ�
	//param inGenre
	void SetGenre(string inGenre);
	//�帣�� �� ��� �ޱ�
	void SetMusicInGenre(AvlTree<SimpleMusicType> g_List);
	//�帣�� Ű����κ��� �ޱ�
	void SetGenreFromKB();
	//�帣 ���
	void DisplayGenreOnScreen();

	//�帣�� �� ��� ���
//	void PrintMusic();
	//�帣�� �� ��Ͽ� �� �߰�
	int AddMusicInGenre(SimpleMusicType& music);
	//�帣�� �� ��Ͽ��� �� ����
	int DeleteMusicInGenre(SimpleMusicType& music);
	//�帣�� �� ����� ���� ���
	int GetLengthOfList();

	AvlTree<SimpleMusicType>* DetailMusicInGenreList();

private:
	string s_Genre;
	AvlTree<SimpleMusicType> s_GMusicList;
};

#endif

