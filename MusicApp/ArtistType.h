#ifndef _ARTIST_TYPE_
#define _ARTIST_TYPE_
#include <iostream>
#include <string>
#include "AvlTree.h"
#include "SimpleMusicType.h"
using namespace std;

class ArtistType
{
public:
	/**
	*	@brief	생성자
	*/
	ArtistType();
	/**
	*	@brief	소멸자
	*/
	~ArtistType();
	/**
	*	@brief	가수명 얻기
	*	@return s_Name
	*/
	string GetName();
	/**
	*	@brief	소속사 얻기
	*	@return s_Ent
	*/
	string GetEnt();

	/**
	*	@brief	가수명 설정
	*	@param	inName 새로운 가수정보
	*/
	void SetName(string inName);
	/**
	*	@brief	소속사 설정
	*	@param	inEnt 새로운 가수의 소속사정보
	*/
	void SetEnt(string inEnt);
	/**
	*	@brief	곡 목록 설정
	*	@param	inList 새로운 가수의 곡목록
	*/
	void SetList(AvlTree<SimpleMusicType> inList);
	/**
	*	@brief	곡의 모든 정보 설정
	*/
	void SetRecord(string inName, string inEnt, AvlTree<SimpleMusicType> inList);

	//가수명 키보드로부터 받기
	void SetNameFromKB();
	//가수 소속사 키보드로부터 받기
	void SetEntFromKB();
	//가수의 모든 정보 키보드로부터 받기
	void SetRecordFromKB();

	//가수의 이름 출력
	void DisplayNameOnScreen();
	//가수의 소속사 출력
	void DisplayEntOnScreen();
	//가수의 모든 기록 출력
	void DisplayRecordOnScreen();

	/**
	*	@brief	연산자 = 정의
	*/
	void operator = (ArtistType &a);
	/**
	*	@brief	연산자 == 정의
	*/
	bool operator == (ArtistType & a);
	/**
	*	@brief	연산자 > 정의
	*/
	bool operator > (const ArtistType &a);
	/**
	*	@brief	연산자 < 정의
	*/
	bool operator < (const ArtistType &a);
	/**
	*	@brief	연산자 >= 정의
	*/
	bool operator >= (const ArtistType &a);
	/**
	*	@brief	연산자 <= 정의
	*/
	bool operator <= (const ArtistType &a);

	friend ostream& operator <<(ostream& os, ArtistType& a);

	//가수의 곡 목록에 곡을 추가
	int AddList(SimpleMusicType& music);
	//가수의 곡 목록에서 곡을 삭제
	int DeleteList(SimpleMusicType& music);
	//가수의 곡 목록의 길이를 얻기
	int GetLengthOfList();

	AvlTree<SimpleMusicType>* DetailInArtistList();

private:
	string s_Name;
	string s_Ent;
	AvlTree<SimpleMusicType> s_List;
};

#endif