#ifndef _ALBUMTYPE_H
#define _ALBUMTYPE_H

#include <iostream>
#include <string>

#include "SimpleMusicType.h"
#include "AvlTree.h"
using namespace std;

class AlbumType
{
public:
	//������
	AlbumType();

	//�Ҹ���
	~AlbumType();
	
	//������ �����ε�
	void operator=(AlbumType& a);
	bool operator>(AlbumType &a);
	bool operator<(AlbumType &a);
	bool operator>=(AlbumType &a);
	bool operator<=(AlbumType &a);
	bool operator==(AlbumType &a);
	bool operator!=(AlbumType &a);
	friend ostream& operator <<(ostream& os, AlbumType& a);


	string GetAlbum();
	string GetArtist();
	void SetAlbum(string inalbum);
	void SetArtist(string inartist);
	void SetAlbumFromKB();

	//��������Ʈ�� �� �߰�
	void AddMusicInMusicList(SimpleMusicType& data);

	//��������Ʈ�� �� ����
	int DeleteMusicInMusicList(SimpleMusicType& data);
	void DisplayAlbumOnScreen();
	void DisplayArtistOnScreen();
	AvlTree<SimpleMusicType>* DetailInAlbumList();

private:
	string s_Album;
	string s_Artist;
	AvlTree<SimpleMusicType> s_MusicList; //���ϰ�
};
#endif