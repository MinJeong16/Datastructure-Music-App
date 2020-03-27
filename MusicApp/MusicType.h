#ifndef _MUSIC_TYPE_
#define _MUSIC_TYPE_
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class MusicType
{
private:
	string s_Album; //�ٹ���
	string s_Type; //���� or �̱�
	string s_Genre; //�帣
	string s_Title; //���
	string s_Artist; //����
	string s_Producer; //���ε༭
	string s_ReleaseDate; //�߸���
	string s_Ent; //��ȹ��
	string s_Lylics; //����
	string s_ID; //Primary key

public:
	//default constructor.
	MusicType();

	//destructor.
	~MusicType();

	//�ٹ� �ޱ�
	void SetAlbum(string inAlbum);
	//Ÿ�� �ޱ�
	void SetType(string inType);
	//�帣 �ޱ�
	void SetGenre(string inGenre);
	//��� �ޱ�
	void SetTitle(string inTitle);
	//������ �ޱ�
	void SetArtist(string inArtist);
	// �۰ �ޱ�
	void SetProducer(string inProducer);
	//�߸��� �ޱ�
	void SetReleaseDate(string inReleaseDate);
	//�Ҽӻ� �ޱ�
	void SetEntertainment(string inEnt);
	//���� �ޱ�
	void SetLylics(string inLylics);
	//�ѹ� �ޱ�
	void SetID(string inID);
	//��� ���� �ޱ�
	void SetMusic(string inAlbum, string inType, string inGenre, string inTitle,
		string inArtist, string inProducer, string inReleaseDate, string inEnt, string inLylics,
		string inID);
	//�ѹ� ��¥�� �ð����� �ڵ����� �ޱ�
	void SetID_AUTO();

	//�ٹ� Ű����κ��� �Է¹ޱ�
	void SetAlbumFromKB();
	//Ÿ�� Ű����κ��� �Է¹ޱ�
	void SetTypeFromKB();
	//�帣�� Ű����κ��� �Է¹ޱ�
	void SetGenreFromKB();
	//��� Ű����κ��� �Է¹ޱ�
	void SetTitleFromKB();
	// ������ Ű����κ��� �Է¹ޱ�
	void SetArtistFromKB();
	//�۰ Ű����κ��� �Է¹ޱ�
	void SetProducerFromKB();
	//�߸��� Ű����κ��� �Է¹ޱ�
	void SetReleaseDateFromKB();
	//�Ҽӻ� Ű����κ��� �Է¹ޱ�
	void SetEntertainmentFromKB();
	//���� Ű����κ��� �Է¹ޱ�
	void SetLylicsFromKB();
	//�ѹ� Ű����κ��� �Է¹ޱ�
	void SetIDFromKB();
	//���� Ű����κ��� �Է¹ޱ�
	void SetMusicFromKB();
	//�ѹ��� ������ ���� Ű����κ��� �Է¹ޱ�
	void SetMusicFromKBincludeID();

	//�ٹ��� ���
	string GetAlbum() { return s_Album; }
	//Ÿ�� ���
	string GetType() { return s_Type; }
	//�帣 ���
	string GetGenre() { return s_Genre; }
	//��� ���
	string GetTitle() { return s_Title; }
	//������ ���
	string GetArtist() { return s_Artist; }
	//�۰ ���
	string GetProducer() { return s_Producer; }
	//�߸��� ���
	string GetReleaseDate() { return s_ReleaseDate; }
	//�Ҽӻ� ���
	string GetEntertainment() { return s_Ent; }
	//���� ���
	string GetLylics() { return s_Lylics; }
	//�ѹ� ���
	string GetID() { return s_ID; }

	//�ѹ� ���
	void DisplayIDOnScreen();
	//�ٹ� ���
	void DisplayAlbumOnScreen();
	//Ÿ�� ���
	void DisplayTypeOnScreen();
	//�帣 ���
	void DisplayGenreOnScreen();
	//��� ���
	void DisplayTitleOnScreen();
	//������ ���
	void DisplayArtistOnScreen();
	//�۰ ���
	void DisplayProducerOnScreen();
	//�Ҽӻ� ���
	void DisplayEntOnScreen();
	//�߸��� ���
	void DisplayReleaseDateOnScreen();
	//���� ���
	void DisplayLylicsOnScreen();
	//�������� ���
	void DisplayMusicOnScreen();
	//���� �о���̱�
	int ReadDataFromFile(ifstream& fin);
	//���� ����
	int WriteDataToFile(ofstream& fout);

	//������ = �����ε�
	void operator = (MusicType &m);
	//������ == �����ε�
	bool operator == (MusicType &m);
	//������ > �����ε�
	bool operator > (const MusicType &m);
	//������ < �����ε�
	bool operator < (const MusicType &m);
	//������ >= �����ε�
	bool operator >= (const MusicType &m);
	//������ <= �����ε�
	bool operator <= (const MusicType &m);
	friend ostream& operator<<(ostream& os, MusicType& m);
};
#endif

ostream& operator<<(ostream& os, MusicType& m);

