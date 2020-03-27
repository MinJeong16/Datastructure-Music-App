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
	//생성자
	UserType();
	//소멸자
	~UserType();
	//아이디 받기
	void SetUserID(string inUserID);
	//패스워드 받기
	void SetUserPW(string inUserPW);
	//닉네임 받기
	void SetUserNickName(string inNickName);
	//음악취향 받기
	void SetUserPhone(string inUserPhone);
	//가수취향 받기
	void SetUserMail(string inUserMail);

	//유저아이디 키보드로부터 받기
	void SetUserIDFrKB();
	//유저 패스워드 키보드로부터 받기
	void SetUserPWFrKB();
	//유저 닉네임 키보드로부터 받기
	void SetNickNameFrKB();
	//유저 음악취향 키보드로부터 받기
	void SetUserPhoneFrKB();
	//유저 가수취향 키보드로부터 받기
	void SetUserMailFrKB();

	//유저아이디 얻기
	string GetUserID();
	//유저 패스워드 얻기
	string GetUserPW();
	//유저 닉네임 얻기
	string GetNickName();
	string GetUserPhone();
	string GetUserMail();
	//유저 정보 출력
	void DisplayUserInfo();
	//연산자 = 오버로딩
	void operator = (UserType &u);
	//연산자 == 오버로딩
	bool operator == (UserType &u);
	//연산자 > 오버로딩
	bool operator > (const UserType &u);
	//연산자 < 오버로딩
	bool operator < (const UserType &u);
	//연산자 >= 오버로딩
	bool operator >= (const UserType &u);
	//연산자 <= 오버로딩
	bool operator <= (const UserType &u);
	friend ostream& operator<<(ostream& os, UserType& u);
	friend ofstream& operator<<(ofstream& of, UserType& u);

	//파일 읽어들이기
	int ReadDataFromFile(ifstream& fin);
	//파일 쓰기
	int WriteDataToFile(ofstream& fout);
};

#endif