#include "ArtistType.h"

//������
ArtistType::ArtistType() {}

//�Ҹ���
ArtistType::~ArtistType() {}

//������ ���
string ArtistType::GetName()
{
	return s_Name;
}

//�Ҽӻ� ���
string ArtistType::GetEnt()
{
	return s_Ent;
}

void ArtistType::SetName(string inName)
{
	s_Name = inName;
}

//�Ҽӻ� �ޱ�
void ArtistType::SetEnt(string inEnt)
{
	s_Ent = inEnt;
}

//���� �ޱ�
void ArtistType::SetList(AvlTree<SimpleMusicType> inList)
{
	s_List = inList;
}

//���ڵ� �ޱ�
void ArtistType::SetRecord(string inName, string inEnt, AvlTree<SimpleMusicType> inList)
{
	SetName(inName);
	SetEnt(inEnt);
	SetList(inList);
}

//�̸� Ű����κ��� �ޱ�
void ArtistType::SetNameFromKB()
{
	cout << "\t����: ";
	cin >> s_Name;
}
//�Ҽӻ� Ű����κ��� �ޱ�
void ArtistType::SetEntFromKB()
{
	cout << "\t�Ҽӻ�: ";
	cin >> s_Ent;
}
//���ڵ� Ű����κ��� �ޱ�
void ArtistType::SetRecordFromKB()
{
	SetNameFromKB();
	SetEntFromKB();
}
//������ ���
void ArtistType::DisplayNameOnScreen()
{
	cout << "\t����: " << s_Name;
}
//�Ҽӻ� ���
void ArtistType::DisplayEntOnScreen()
{
	cout << "\t�Ҽӻ�: " << s_Ent;
}
//���ڵ� ���
void ArtistType::DisplayRecordOnScreen()
{
	DisplayNameOnScreen();
	cout << endl;
	DisplayEntOnScreen();
	cout << endl;
}
//������ = �����ε�
void ArtistType::operator=(ArtistType & a)
{
	s_Name = a.s_Name;
	s_Ent = a.s_Ent;
	s_List = a.s_List;
}
//������ ==�����ε�
bool ArtistType::operator==(ArtistType & a)
{
	return this->s_Name == a.s_Name;
}
// ������ > �����ε�
bool ArtistType::operator>(const ArtistType & a)
{
	return this->s_Name > a.s_Name;
}
// ������ < �����ε�
bool ArtistType::operator<(const ArtistType & a)
{
	return this->s_Name < a.s_Name;
}
// ������ >= �����ε�
bool ArtistType::operator>=(const ArtistType & a)
{
	return this->s_Name >= a.s_Name;
}
// ������ <= �����ε�
bool ArtistType::operator<=(const ArtistType & a)
{
	return this->s_Name <= a.s_Name;
}
// �� ��Ͽ� ���� �߰�
int ArtistType::AddList(SimpleMusicType& music)
{
	s_List.Add(music);
	return 1;
}
//�� ��Ͽ��� ���� ����
int ArtistType::DeleteList(SimpleMusicType & music)
{
	if (s_List.DeleteItem(music))
	{
		if (s_List.GetLength() == 0)
		{
			return 1;
		}
		return 0;
	}
	return -1;
}

// �� ����� ���̸� ���
int ArtistType::GetLengthOfList()
{
	return s_List.GetLength();
}

AvlTree<SimpleMusicType>* ArtistType::DetailInArtistList()
{
	return &s_List;
}

ostream& operator <<(ostream& os, ArtistType& a)
{
	cout << "\n\t--------------------------------" << endl;
	a.DisplayRecordOnScreen();
	cout << "\n\t--------------------------------" << endl;
	return os;
}
