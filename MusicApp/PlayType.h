#ifndef _PLAY_TYPE_
#define _PLAY_TYPE_
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PlayType
{
public:
	//생성자
	PlayType();
	//소멸자
	~PlayType();
	//넘버 받기
	void SetPlayID(string inid);
	//곡명 받기
	void SetTitle(string inTitle);
	//가수명 받기
	void SetArtist(string inArtist);
	//가사 받기
	void SetLylics(string inLylics);
	//넘버 얻기
	string GetPlayID() { return s_ID; }
	//곡명 얻기
	string GetTitle() { return s_Title; }
	//가수명 얻기
	string GetArtist() { return s_Artist; }
	//가사 얻기
	string GetLylics() { return s_Lylics; }

	int saveitem(ofstream& fout);
	void readitem(ifstream& fin);

	//아이템 출력
	void Display();
	//연산자 = 오버로딩
	void operator=(const PlayType &p);
	//연산자 == 오버로딩
	bool operator == (PlayType &p);
	//연산자 > 오버로딩
	bool operator > (const PlayType &p);
	//연산자 < 오버로딩
	bool operator < (const PlayType &p);
	//연산자 >= 오버로딩
	bool operator >= (const PlayType &p);
	//연산자 <= 오버로딩
	bool operator <= (const PlayType &p);

private:
	string s_ID;
	string s_Title;
	string s_Artist;
	string s_Lylics;
};
#endif
