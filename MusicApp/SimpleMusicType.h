#ifndef _SIMPLE_MUSIC_TYPE_
#define _SIMPLE_MUSIC_TYPE_
#include <iostream>
#include <string>
using namespace std;

class SimpleMusicType
{
public:
	//생성자
	SimpleMusicType();
	//소멸자
	~SimpleMusicType();
	//연산자 = 정의
	void operator = (SimpleMusicType &s);
	//연산자 == 정의
	bool operator == (SimpleMusicType &s);
	//연산자 > 정의
	bool operator > (const SimpleMusicType &s);
	//연산자 < 정의
	bool operator < (const SimpleMusicType &s);
	//연산자 >= 정의
	bool operator >= (const SimpleMusicType &s);
	//연산자 <= 정의
	bool operator <= (const SimpleMusicType &s);

	bool operator !=(const SimpleMusicType &s);

	friend ostream& operator<<(ostream& os, SimpleMusicType &s);
	//넘버받기
	void SetID(string inID);
	//곡명 받기
	void SetTitle(string inTitle);
	//심플뮤직타입 받기
	void SetSimpleMusic(string inID, string inTitle);
	//넘버 키보드로부터 받기
	void SetIDFromKB();
	//곡명 키보드로부터 받기
	void SetTitleFromKB();
	//곡정보 키보드로부터 받기
	void SetSimpleMusicFromKB();
	//넘버 얻기
	string GetID();
	//곡명 얻기
	string GetTitle();
	//넘버 출력
	void DisplayIDOnScreen();
	//곡명 출력
	void DisplayTitleOnScreen();
	//레코드 출력
	void DisplayRecordOnScreen();

private:
	string s_ID;
	string s_Title;
};
#endif