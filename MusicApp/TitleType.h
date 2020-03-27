#ifndef _TITLETYPE_H
#define _TITLETYPE_H

#include <iostream>
#include <string>
#include "AvlTree.h"
using namespace std;

//곡목록
class TitleType
{
public:
	//생성자
	TitleType();
	//소멸자
	~TitleType();
	
	//연산자 오버로딩
	void operator=(TitleType &t);
	bool operator>(TitleType &t);
	bool operator<(TitleType &t);
	bool operator>=(TitleType &t);
	bool operator<=(TitleType &t);
	bool operator==(TitleType &t);
	bool operator!=(TitleType &t);
	friend ostream& operator<<(ostream& os, TitleType& t);

	//TitleType을 설정하기 위한 함수
	string GetTitle();
	void SetTitle(string inTitle);
	void SetTitleFromKB();

	//display 함수
	void DisplayTitleOnScreen();
	void AddArtistInList(string& data);
	int DeleteArtistInList(string& data);
	AvlTree<string>* DetailTitleListOnScreen();
private:
	string s_Title; //pk
	AvlTree<string> s_TitleList;
};
#endif