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
	//생성자
	GenreType();
	//소멸자
	~GenreType();

	//연산자 = 정의
	void operator = (GenreType &s);
	// 연산자 == 정의
	bool operator == (GenreType &s);
	// 연산자 > 정의
	bool operator > (const GenreType &s);
	// 연산자 < 정의
	bool operator < (const GenreType &s);
	// 연산자 >= 정의
	bool operator >= (const GenreType &s);
	// 연산자 <= 정의
	bool operator <= (const GenreType &s);

	friend ostream& operator <<(ostream& os, GenreType& g);

	//장르 얻기
	string GetGenre();
	//장르 받기
	//param inGenre
	void SetGenre(string inGenre);
	//장르의 곡 목록 받기
	void SetMusicInGenre(AvlTree<SimpleMusicType> g_List);
	//장르명 키보드로부터 받기
	void SetGenreFromKB();
	//장르 출력
	void DisplayGenreOnScreen();

	//장르의 곡 목록 출력
//	void PrintMusic();
	//장르의 곡 목록에 곡 추가
	int AddMusicInGenre(SimpleMusicType& music);
	//장르의 곡 목록에서 곡 삭제
	int DeleteMusicInGenre(SimpleMusicType& music);
	//장르의 곡 목록의 길이 얻기
	int GetLengthOfList();

	AvlTree<SimpleMusicType>* DetailMusicInGenreList();

private:
	string s_Genre;
	AvlTree<SimpleMusicType> s_GMusicList;
};

#endif

