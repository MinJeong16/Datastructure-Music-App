#include "UserType.h"


//������
UserType::UserType() {}

//�Ҹ���
UserType::~UserType() {}
//���̵� �ޱ�
void UserType::SetUserID(string inUserID)
{
	UserID = inUserID;
}
//�н����� �ޱ�
void UserType::SetUserPW(string inUserPW)
{
	UserPW = inUserPW;
}
//�г��� �ޱ�
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

//���̵� Ű����κ��� �ޱ�
void UserType::SetUserIDFrKB()
{
	cout << "\t���̵�: ";
	cin >> UserID;
}
//�н����� Ű����κ��� �ޱ�
void UserType::SetUserPWFrKB()
{
	cout << "\t�н�����: ";
	cin >> UserPW;
}
//�г��� Ű����κ��� �ޱ�
void UserType::SetNickNameFrKB()
{
	cout << "\t�г���: ";
	cin >> UserNickName;
}
void UserType::SetUserPhoneFrKB()
{
	cout << "\t����ó: ";
	cin >> UserPhone;
}
void UserType::SetUserMailFrKB()
{
	cout << "\t�����ּ�: ";
	cin >> UserMail;
}
// ���̵� ���
string UserType::GetUserID()
{
	return UserID;
}
//�н����� ���
string UserType::GetUserPW()
{
	return UserPW;
}
//�г��� ���
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

//�������� ���
void UserType::DisplayUserInfo()
{
	cout << "\n\t--------------------------------" << endl;
	cout << "\t���̵�: " << UserID << endl;
	cout << "\t�г���: " << UserNickName << endl;
	cout << "\t����ó: " << UserPhone << endl;
	cout << "\t�����ּ�: " << UserMail << endl;
	cout << "\t--------------------------------" << endl;
}
//������ = �����ε�
void UserType::operator=(UserType & u)
{
	UserID = u.UserID;
	UserPW = u.UserPW;
	UserNickName = u.UserNickName;
	UserPhone = u.UserPhone;
	UserMail = u.UserMail;
}
//������ == �����ε�
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
//������ > �����ε�
bool UserType::operator>(const UserType & u)
{
	return this->UserID > u.UserID;
}
//������ < �����ε�
bool UserType::operator<(const UserType & u)
{
	return this->UserID < u.UserID;
}
// ������ >= �����ε�
bool UserType::operator>=(const UserType & u)
{
	return this->UserID >= u.UserID;
}
// ������ <= �����ε�
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
