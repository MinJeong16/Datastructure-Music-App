#ifndef _TITLETYPE_H
#define _TITLETYPE_H

#include <iostream>
#include <string>
#include "AvlTree.h"
using namespace std;

//����
class TitleType
{
public:
	//������
	TitleType();
	//�Ҹ���
	~TitleType();
	
	//������ �����ε�
	void operator=(TitleType &t);
	bool operator>(TitleType &t);
	bool operator<(TitleType &t);
	bool operator>=(TitleType &t);
	bool operator<=(TitleType &t);
	bool operator==(TitleType &t);
	bool operator!=(TitleType &t);
	friend ostream& operator<<(ostream& os, TitleType& t);

	//TitleType�� �����ϱ� ���� �Լ�
	string GetTitle();
	void SetTitle(string inTitle);
	void SetTitleFromKB();

	//display �Լ�
	void DisplayTitleOnScreen();
	void AddArtistInList(string& data);
	int DeleteArtistInList(string& data);
	AvlTree<string>* DetailTitleListOnScreen();
private:
	string s_Title; //pk
	AvlTree<string> s_TitleList;
};
#endif