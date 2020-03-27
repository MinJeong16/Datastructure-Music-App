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
	string s_Album; //앨범명
	string s_Type; //정규 or 싱글
	string s_Genre; //장르
	string s_Title; //곡명
	string s_Artist; //가수
	string s_Producer; //프로듀서
	string s_ReleaseDate; //발매일
	string s_Ent; //기획사
	string s_Lylics; //가사
	string s_ID; //Primary key

public:
	//default constructor.
	MusicType();

	//destructor.
	~MusicType();

	//앨범 받기
	void SetAlbum(string inAlbum);
	//타입 받기
	void SetType(string inType);
	//장르 받기
	void SetGenre(string inGenre);
	//곡명 받기
	void SetTitle(string inTitle);
	//가수명 받기
	void SetArtist(string inArtist);
	// 작곡가 받기
	void SetProducer(string inProducer);
	//발매일 받기
	void SetReleaseDate(string inReleaseDate);
	//소속사 받기
	void SetEntertainment(string inEnt);
	//가사 받기
	void SetLylics(string inLylics);
	//넘버 받기
	void SetID(string inID);
	//모든 정보 받기
	void SetMusic(string inAlbum, string inType, string inGenre, string inTitle,
		string inArtist, string inProducer, string inReleaseDate, string inEnt, string inLylics,
		string inID);
	//넘버 날짜와 시간으로 자동으로 받기
	void SetID_AUTO();

	//앨범 키보드로부터 입력받기
	void SetAlbumFromKB();
	//타입 키보드로부터 입력받기
	void SetTypeFromKB();
	//장르명 키보드로부터 입력받기
	void SetGenreFromKB();
	//곡명 키보드로부터 입력받기
	void SetTitleFromKB();
	// 가수명 키보드로부터 입력받기
	void SetArtistFromKB();
	//작곡가 키보드로부터 입력받기
	void SetProducerFromKB();
	//발매일 키보드로부터 입력받기
	void SetReleaseDateFromKB();
	//소속사 키보드로부터 입력받기
	void SetEntertainmentFromKB();
	//가사 키보드로부터 입력받기
	void SetLylicsFromKB();
	//넘버 키보드로부터 입력받기
	void SetIDFromKB();
	//음악 키보드로부터 입력받기
	void SetMusicFromKB();
	//넘버를 포함한 음악 키보드로부터 입력받기
	void SetMusicFromKBincludeID();

	//앨범명 얻기
	string GetAlbum() { return s_Album; }
	//타입 얻기
	string GetType() { return s_Type; }
	//장르 얻기
	string GetGenre() { return s_Genre; }
	//곡명 얻기
	string GetTitle() { return s_Title; }
	//가수명 얻기
	string GetArtist() { return s_Artist; }
	//작곡가 얻기
	string GetProducer() { return s_Producer; }
	//발매일 얻기
	string GetReleaseDate() { return s_ReleaseDate; }
	//소속사 얻기
	string GetEntertainment() { return s_Ent; }
	//가사 얻기
	string GetLylics() { return s_Lylics; }
	//넘버 얻기
	string GetID() { return s_ID; }

	//넘버 출력
	void DisplayIDOnScreen();
	//앨범 출력
	void DisplayAlbumOnScreen();
	//타입 출력
	void DisplayTypeOnScreen();
	//장르 출력
	void DisplayGenreOnScreen();
	//곡명 출력
	void DisplayTitleOnScreen();
	//가수명 출력
	void DisplayArtistOnScreen();
	//작곡가 출력
	void DisplayProducerOnScreen();
	//소속사 출력
	void DisplayEntOnScreen();
	//발매일 출력
	void DisplayReleaseDateOnScreen();
	//가사 출력
	void DisplayLylicsOnScreen();
	//음악정보 출력
	void DisplayMusicOnScreen();
	//파일 읽어들이기
	int ReadDataFromFile(ifstream& fin);
	//파일 쓰기
	int WriteDataToFile(ofstream& fout);

	//연산자 = 오버로딩
	void operator = (MusicType &m);
	//연산자 == 오버로딩
	bool operator == (MusicType &m);
	//연산자 > 오버로딩
	bool operator > (const MusicType &m);
	//연산자 < 오버로딩
	bool operator < (const MusicType &m);
	//연산자 >= 오버로딩
	bool operator >= (const MusicType &m);
	//연산자 <= 오버로딩
	bool operator <= (const MusicType &m);
	friend ostream& operator<<(ostream& os, MusicType& m);
};
#endif

ostream& operator<<(ostream& os, MusicType& m);

