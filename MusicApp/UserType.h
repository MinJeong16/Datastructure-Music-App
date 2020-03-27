#ifndef _USER_TYPE_
#define _USER_TYPE_
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>

#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"
#include "PlayType.h"
using namespace std;

class UserType
{
private:
	string UserID;
	string UserPW;
	string UserNickName;
	string UserPhone;
	string UserMail;

public:
	//������
	UserType();
	//�Ҹ���
	~UserType();
	//���̵� �ޱ�
	void SetUserID(string inUserID);
	//�н����� �ޱ�
	void SetUserPW(string inUserPW);
	//�г��� �ޱ�
	void SetUserNickName(string inNickName);
	//�������� �ޱ�
	void SetUserPhone(string inUserPhone);
	//�������� �ޱ�
	void SetUserMail(string inUserMail);

	//�������̵� Ű����κ��� �ޱ�
	void SetUserIDFrKB();
	//���� �н����� Ű����κ��� �ޱ�
	void SetUserPWFrKB();
	//���� �г��� Ű����κ��� �ޱ�
	void SetNickNameFrKB();
	//���� �������� Ű����κ��� �ޱ�
	void SetUserPhoneFrKB();
	//���� �������� Ű����κ��� �ޱ�
	void SetUserMailFrKB();

	//�������̵� ���
	string GetUserID();
	//���� �н����� ���
	string GetUserPW();
	//���� �г��� ���
	string GetNickName();
	string GetUserPhone();
	string GetUserMail();
	//���� ���� ���
	void DisplayUserInfo();
	//������ = �����ε�
	void operator = (UserType &u);
	//������ == �����ε�
	bool operator == (UserType &u);
	//������ > �����ε�
	bool operator > (const UserType &u);
	//������ < �����ε�
	bool operator < (const UserType &u);
	//������ >= �����ε�
	bool operator >= (const UserType &u);
	//������ <= �����ε�
	bool operator <= (const UserType &u);
	friend ostream& operator<<(ostream& os, UserType& u);
	friend ofstream& operator<<(ofstream& of, UserType& u);

	//���� �о���̱�
	int ReadDataFromFile(ifstream& fin);
	//���� ����
	int WriteDataToFile(ofstream& fout);
};

#endif