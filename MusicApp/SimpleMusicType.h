#ifndef _SIMPLE_MUSIC_TYPE_
#define _SIMPLE_MUSIC_TYPE_
#include <iostream>
#include <string>
using namespace std;

class SimpleMusicType
{
public:
	//������
	SimpleMusicType();
	//�Ҹ���
	~SimpleMusicType();
	//������ = ����
	void operator = (SimpleMusicType &s);
	//������ == ����
	bool operator == (SimpleMusicType &s);
	//������ > ����
	bool operator > (const SimpleMusicType &s);
	//������ < ����
	bool operator < (const SimpleMusicType &s);
	//������ >= ����
	bool operator >= (const SimpleMusicType &s);
	//������ <= ����
	bool operator <= (const SimpleMusicType &s);

	bool operator !=(const SimpleMusicType &s);

	friend ostream& operator<<(ostream& os, SimpleMusicType &s);
	//�ѹ��ޱ�
	void SetID(string inID);
	//��� �ޱ�
	void SetTitle(string inTitle);
	//���ù���Ÿ�� �ޱ�
	void SetSimpleMusic(string inID, string inTitle);
	//�ѹ� Ű����κ��� �ޱ�
	void SetIDFromKB();
	//��� Ű����κ��� �ޱ�
	void SetTitleFromKB();
	//������ Ű����κ��� �ޱ�
	void SetSimpleMusicFromKB();
	//�ѹ� ���
	string GetID();
	//��� ���
	string GetTitle();
	//�ѹ� ���
	void DisplayIDOnScreen();
	//��� ���
	void DisplayTitleOnScreen();
	//���ڵ� ���
	void DisplayRecordOnScreen();

private:
	string s_ID;
	string s_Title;
};
#endif