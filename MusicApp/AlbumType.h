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
	//생성자
	AlbumType();

	//소멸자
	~AlbumType();
	
	//연산자 오버로딩
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

	//뮤직리스트에 곡 추가
	void AddMusicInMusicList(SimpleMusicType& data);

	//뮤직리스트에 곡 삭제
	int DeleteMusicInMusicList(SimpleMusicType& data);
	void DisplayAlbumOnScreen();
	void DisplayArtistOnScreen();
	AvlTree<SimpleMusicType>* DetailInAlbumList();

private:
	string s_Album;
	string s_Artist;
	AvlTree<SimpleMusicType> s_MusicList; //수록곡
};
#endif