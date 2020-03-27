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
	*	@brief	������
	*/
	ArtistType();
	/**
	*	@brief	�Ҹ���
	*/
	~ArtistType();
	/**
	*	@brief	������ ���
	*	@return s_Name
	*/
	string GetName();
	/**
	*	@brief	�Ҽӻ� ���
	*	@return s_Ent
	*/
	string GetEnt();

	/**
	*	@brief	������ ����
	*	@param	inName ���ο� ��������
	*/
	void SetName(string inName);
	/**
	*	@brief	�Ҽӻ� ����
	*	@param	inEnt ���ο� ������ �Ҽӻ�����
	*/
	void SetEnt(string inEnt);
	/**
	*	@brief	�� ��� ����
	*	@param	inList ���ο� ������ ����
	*/
	void SetList(AvlTree<SimpleMusicType> inList);
	/**
	*	@brief	���� ��� ���� ����
	*/
	void SetRecord(string inName, string inEnt, AvlTree<SimpleMusicType> inList);

	//������ Ű����κ��� �ޱ�
	void SetNameFromKB();
	//���� �Ҽӻ� Ű����κ��� �ޱ�
	void SetEntFromKB();
	//������ ��� ���� Ű����κ��� �ޱ�
	void SetRecordFromKB();

	//������ �̸� ���
	void DisplayNameOnScreen();
	//������ �Ҽӻ� ���
	void DisplayEntOnScreen();
	//������ ��� ��� ���
	void DisplayRecordOnScreen();

	/**
	*	@brief	������ = ����
	*/
	void operator = (ArtistType &a);
	/**
	*	@brief	������ == ����
	*/
	bool operator == (ArtistType & a);
	/**
	*	@brief	������ > ����
	*/
	bool operator > (const ArtistType &a);
	/**
	*	@brief	������ < ����
	*/
	bool operator < (const ArtistType &a);
	/**
	*	@brief	������ >= ����
	*/
	bool operator >= (const ArtistType &a);
	/**
	*	@brief	������ <= ����
	*/
	bool operator <= (const ArtistType &a);

	friend ostream& operator <<(ostream& os, ArtistType& a);

	//������ �� ��Ͽ� ���� �߰�
	int AddList(SimpleMusicType& music);
	//������ �� ��Ͽ��� ���� ����
	int DeleteList(SimpleMusicType& music);
	//������ �� ����� ���̸� ���
	int GetLengthOfList();

	AvlTree<SimpleMusicType>* DetailInArtistList();

private:
	string s_Name;
	string s_Ent;
	AvlTree<SimpleMusicType> s_List;
};

#endif