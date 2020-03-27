#include "UserType.h"


//생성자
UserType::UserType() {}

//소멸자
UserType::~UserType() {}
//아이디 받기
void UserType::SetUserID(string inUserID)
{
	UserID = inUserID;
}
//패스워드 받기
void UserType::SetUserPW(string inUserPW)
{
	UserPW = inUserPW;
}
//닉네임 받기
void UserType::SetUserNickName(string inNickName)
{
	UserNickName = inNickName;
}
void UserType::SetUserPhone(string inUserPhone)
{
	UserPhone = inUserPhone;
}
void UserType::SetUserMail(string inUserMail)
{
	UserMail = inUserMail;
}

//아이디 키보드로부터 받기
void UserType::SetUserIDFrKB()
{
	cout << "\t아이디: ";
	cin >> UserID;
}
//패스워드 키보드로부터 받기
void UserType::SetUserPWFrKB()
{
	cout << "\t패스워드: ";
	cin >> UserPW;
}
//닉네임 키보드로부터 받기
void UserType::SetNickNameFrKB()
{
	cout << "\t닉네임: ";
	cin >> UserNickName;
}
void UserType::SetUserPhoneFrKB()
{
	cout << "\t연락처: ";
	cin >> UserPhone;
}
void UserType::SetUserMailFrKB()
{
	cout << "\t메일주소: ";
	cin >> UserMail;
}
// 아이디 얻기
string UserType::GetUserID()
{
	return UserID;
}
//패스워드 얻기
string UserType::GetUserPW()
{
	return UserPW;
}
//닉네임 얻기
string UserType::GetNickName()
{
	return UserNickName;
}

string UserType::GetUserPhone()
{
	return UserPhone;
}

string UserType::GetUserMail()
{
	return UserMail;
}

//유저정보 출력
void UserType::DisplayUserInfo()
{
	cout << "\n\t--------------------------------" << endl;
	cout << "\t아이디: " << UserID << endl;
	cout << "\t닉네임: " << UserNickName << endl;
	cout << "\t연락처: " << UserPhone << endl;
	cout << "\t메일주소: " << UserMail << endl;
	cout << "\t--------------------------------" << endl;
}
//연산자 = 오버로딩
void UserType::operator=(UserType & u)
{
	UserID = u.UserID;
	UserPW = u.UserPW;
	UserNickName = u.UserNickName;
	UserPhone = u.UserPhone;
	UserMail = u.UserMail;
}
//연산자 == 오버로딩
bool UserType::operator==(UserType & u)
{
	if (this->UserID == u.UserID)
	{
		if (this->UserPW == u.UserPW)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
		return false;
}
//연산자 > 오버로딩
bool UserType::operator>(const UserType & u)
{
	return this->UserID > u.UserID;
}
//연산자 < 오버로딩
bool UserType::operator<(const UserType & u)
{
	return this->UserID < u.UserID;
}
// 연산자 >= 오버로딩
bool UserType::operator>=(const UserType & u)
{
	return this->UserID >= u.UserID;
}
// 연산자 <= 오버로딩
bool UserType::operator<=(const UserType & u)
{
	return this->UserID <= u.UserID;
}

ostream& operator<<(ostream& os, UserType& u)
{
	u.DisplayUserInfo();
	return os;
}

ofstream& operator <<(ofstream& of, UserType& u)
{
	u.WriteDataToFile(of);
	return of;
}

int UserType::ReadDataFromFile(ifstream & fin)
{
	fin >> UserID;
	fin >> UserPW;
	fin >> UserNickName;
	fin >> UserMail;
	fin >> UserPhone;
	return 1;
}

int UserType::WriteDataToFile(ofstream & fout)
{
	fout << UserID << ' ';
	fout << UserPW << ' ';
	fout << UserNickName << ' ';
	fout << UserMail << ' ';
	fout << UserPhone << ' ';
	return 1;
}
