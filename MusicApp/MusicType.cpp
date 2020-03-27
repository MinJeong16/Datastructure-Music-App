#include "MusicType.h"
//생성자
MusicType::MusicType() {}
//소멸자
MusicType::~MusicType() {}
//앨범명 받기
void MusicType::SetAlbum(string inAlbum)
{
	s_Album = inAlbum;
}
//타입 받기
void MusicType::SetType(string inType)
{
	s_Type = inType;
}
//장르명 받기
void MusicType::SetGenre(string inGenre)
{
	s_Genre = inGenre;
}
//곡명 받기
void MusicType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}
//가수명 받기
void MusicType::SetArtist(string inArtist)
{
	s_Artist = inArtist;
}
//작곡가 받기
void MusicType::SetProducer(string inProducer)
{
	s_Producer = inProducer;
}
//발매일 받기
void MusicType::SetReleaseDate(string inReleaseDate)
{
	s_ReleaseDate = inReleaseDate;
}
//소속사 받기
void MusicType::SetEntertainment(string inEnt)
{
	s_Ent = inEnt;
}
// 가사 받기
void MusicType::SetLylics(string inLylics)
{
	s_Lylics = inLylics;
}
//넘버 받기
void MusicType::SetID(string inID)
{
	s_ID = inID;
}
// 모든 정보 받기
void MusicType::SetMusic(string inAlbum, string inType, string inGenre, string inTitle, string inArtist, string inProducer, string inReleaseDate, string inEnt, string inLylics, string inID)
{
	SetAlbum(inAlbum);
	SetType(inType);
	SetGenre(inGenre);
	SetTitle(inTitle);
	SetArtist(inArtist);
	SetProducer(inProducer);
	SetReleaseDate(inReleaseDate);
	SetEntertainment(inEnt);
	SetLylics(inLylics);
	SetID(inID);
}
// 넘버를 시간과 날짜를 받아 자동으로 받기
void MusicType::SetID_AUTO()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	string Year = to_string(tm.tm_year + 1900);
	string Month = to_string(tm.tm_mon + 1);
	string Day = to_string(tm.tm_mday);
	string Sec = to_string(tm.tm_sec);

	string Time = Year + Month + Day + Sec;

	s_ID = Time;
}
//앨범명을 키보드로부터 받기
void MusicType::SetAlbumFromKB()
{
	cout << "\t앨범명 : ";
	cin >> s_Album;
}
// 타입을 키보드로부터 받기
void MusicType::SetTypeFromKB()
{
	cout << "\t타입: ";
	cin >> s_Type;
}
//장르를 키보드로부터 받기
void MusicType::SetGenreFromKB()
{
	cout << "\t장르 : ";
	cin >> s_Genre;
}
//곡명을 키보드로부터 받기
void MusicType::SetTitleFromKB()
{
	cout << "\t곡명: ";
	cin >> s_Title;
}
//가수명 키보드로부터 받기
void MusicType::SetArtistFromKB()
{
	cout << "\t가수: ";
	cin >> s_Artist;
}
//작곡가를 키보드로부터 받기
void MusicType::SetProducerFromKB()
{
	cout << "\t작곡: ";
	cin >> s_Producer;
}
//발매일을 키보드로부터 받기
void MusicType::SetReleaseDateFromKB()
{
	cout << "\t발매일: ";
	cin >> s_ReleaseDate;
}
//소속사를 키보드로부터 받기
void MusicType::SetEntertainmentFromKB()
{
	cout << "\t소속사: ";
	cin >> s_Ent;
}
//가사를 키보드로부터 받기
void MusicType::SetLylicsFromKB()
{
	cout << "\t가사: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //getline이 cin의 ' '를 무시하기 위해서 사용
	getline(cin, s_Lylics);
}
// 넘버를 키보드로부터 받기
void MusicType::SetIDFromKB()
{
	cout << "\t넘버: ";
	cin >> s_ID;
}
//곡의 모든 정보를 키보드로부터 받기, 아이디는 자동입력
void MusicType::SetMusicFromKB()
{
	SetAlbumFromKB();
	SetTypeFromKB();
	SetGenreFromKB();
	SetTitleFromKB();
	SetArtistFromKB();
	SetProducerFromKB();
	SetReleaseDateFromKB();
	SetEntertainmentFromKB();
	SetLylicsFromKB();
	SetID_AUTO();
}
//곡의 모든 정보를 키보드로부터 받기
void MusicType::SetMusicFromKBincludeID()
{
	SetIDFromKB();
	SetAlbumFromKB();
	SetTypeFromKB();
	SetGenreFromKB();
	SetTitleFromKB();
	SetArtistFromKB();
	SetProducerFromKB();
	SetReleaseDateFromKB();
	SetEntertainmentFromKB();
	SetLylicsFromKB();
}
//곡 넘버 출력
void MusicType::DisplayIDOnScreen()
{
	cout << "\t넘버: " << s_ID;
}
//앨범명 출력
void MusicType::DisplayAlbumOnScreen()
{
	cout << "\t앨범명: " << s_Album;
}
//타입 출력
void MusicType::DisplayTypeOnScreen()
{
	cout << "\t타입: " << s_Type;
}
//장르 출력
void MusicType::DisplayGenreOnScreen()
{
	cout << "\t장르: " << s_Genre;
}
//곡명 출력
void MusicType::DisplayTitleOnScreen()
{
	cout << "\t곡명: " << s_Title;
}
//가수명 출력
void MusicType::DisplayArtistOnScreen()
{
	cout << "\t가수: " << s_Artist;
}
//작곡가명 출력
void MusicType::DisplayProducerOnScreen()
{
	cout << "\t작곡: " << s_Producer;
}
//발매일 출력
void MusicType::DisplayReleaseDateOnScreen()
{
	cout << "\t발매일: " << s_ReleaseDate;
}
//소속사명 출력
void MusicType::DisplayEntOnScreen()
{
	cout << "\t소속사: " << s_Ent;
}
//가사 출력
void MusicType::DisplayLylicsOnScreen()
{
	cout << "\t가사: " << s_Lylics;
}
// 모든 정보 출력
void MusicType::DisplayMusicOnScreen()
{
	cout << "\n\t--------------------------------" << endl;
	DisplayIDOnScreen();
	cout << "\n";
	DisplayAlbumOnScreen();
	cout << "\n";
	DisplayTypeOnScreen();
	cout << "\n";
	DisplayGenreOnScreen();
	cout << "\n";
	DisplayTitleOnScreen();
	cout << "\n";
	DisplayArtistOnScreen();
	cout << "\n";
	DisplayProducerOnScreen();
	cout << "\n";
	DisplayReleaseDateOnScreen();
	cout << "\n";
	DisplayEntOnScreen();
	cout << "\n";
	DisplayLylicsOnScreen();
	cout << "\n\t--------------------------------" << endl;
}
//파일로부터 읽어들이기
int MusicType::ReadDataFromFile(ifstream & fin)
{
	fin >> s_ID;
	fin >> s_Album;
	fin >> s_Type;
	fin >> s_Genre;
	fin >> s_Title;
	fin >> s_Artist;
	fin >> s_Producer;
	fin >> s_Ent;
	fin >> s_ReleaseDate;
	getline(fin, s_Lylics);

	return 1;
}
//파일에 쓰기
int MusicType::WriteDataToFile(ofstream & fout)
{
	fout << endl;
	fout << s_ID << ' ';
	fout << s_Album << ' ';
	fout << s_Type << ' ';
	fout << s_Genre << ' ';
	fout << s_Title << ' ';
	fout << s_Artist << ' ';
	fout << s_Producer << ' ';
	fout << s_Ent << ' ';
	fout << s_ReleaseDate << ' ';
	fout << s_Lylics << ' ';
	return 1;
}
//연산자 = 오버로딩
void MusicType::operator=(MusicType & m)
{
	s_ID = m.s_ID;
	s_Album = m.s_Album;
	s_Type = m.s_Type;
	s_Genre = m.s_Genre;
	s_Title = m.s_Title;
	s_Artist = m.s_Artist;
	s_Producer = m.s_Producer;
	s_Ent = m.s_Ent;
	s_ReleaseDate = m.s_ReleaseDate;
	s_Lylics = m.s_Lylics;
}
// 연산자 == 오버로딩
bool MusicType::operator==(MusicType & m)
{
	return s_ID == m.s_ID;
}
// 연산자 > 오버로딩
bool MusicType::operator>(const MusicType & m)
{
	return s_ID > m.s_ID;
}
// 연산자 < 오버로딩
bool MusicType::operator<(const MusicType & m)
{
	return s_ID < m.s_ID;
}
// 연산자 >= 오버로딩
bool MusicType::operator>=(const MusicType & m)
{
	return s_ID >= m.s_ID;
}
// 연산자 <= 오버로딩
bool MusicType::operator<=(const MusicType & m)
{
	return s_ID <= m.s_ID;
}

ostream& operator <<(ostream& os, MusicType& m) {
	m.DisplayMusicOnScreen();
	return os;
}

