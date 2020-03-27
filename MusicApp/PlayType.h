#ifndef _PLAY_TYPE_
#define _PLAY_TYPE_
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PlayType
{
public:
	//������
	PlayType();
	//�Ҹ���
	~PlayType();
	//�ѹ� �ޱ�
	void SetPlayID(string inid);
	//��� �ޱ�
	void SetTitle(string inTitle);
	//������ �ޱ�
	void SetArtist(string inArtist);
	//���� �ޱ�
	void SetLylics(string inLylics);
	//�ѹ� ���
	string GetPlayID() { return s_ID; }
	//��� ���
	string GetTitle() { return s_Title; }
	//������ ���
	string GetArtist() { return s_Artist; }
	//���� ���
	string GetLylics() { return s_Lylics; }

	int saveitem(ofstream& fout);
	void readitem(ifstream& fin);

	//������ ���
	void Display();
	//������ = �����ε�
	void operator=(const PlayType &p);
	//������ == �����ε�
	bool operator == (PlayType &p);
	//������ > �����ε�
	bool operator > (const PlayType &p);
	//������ < �����ε�
	bool operator < (const PlayType &p);
	//������ >= �����ε�
	bool operator >= (const PlayType &p);
	//������ <= �����ε�
	bool operator <= (const PlayType &p);

private:
	string s_ID;
	string s_Title;
	string s_Artist;
	string s_Lylics;
};
#endif
