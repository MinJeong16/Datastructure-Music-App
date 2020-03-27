#include "MusicType.h"
//������
MusicType::MusicType() {}
//�Ҹ���
MusicType::~MusicType() {}
//�ٹ��� �ޱ�
void MusicType::SetAlbum(string inAlbum)
{
	s_Album = inAlbum;
}
//Ÿ�� �ޱ�
void MusicType::SetType(string inType)
{
	s_Type = inType;
}
//�帣�� �ޱ�
void MusicType::SetGenre(string inGenre)
{
	s_Genre = inGenre;
}
//��� �ޱ�
void MusicType::SetTitle(string inTitle)
{
	s_Title = inTitle;
}
//������ �ޱ�
void MusicType::SetArtist(string inArtist)
{
	s_Artist = inArtist;
}
//�۰ �ޱ�
void MusicType::SetProducer(string inProducer)
{
	s_Producer = inProducer;
}
//�߸��� �ޱ�
void MusicType::SetReleaseDate(string inReleaseDate)
{
	s_ReleaseDate = inReleaseDate;
}
//�Ҽӻ� �ޱ�
void MusicType::SetEntertainment(string inEnt)
{
	s_Ent = inEnt;
}
// ���� �ޱ�
void MusicType::SetLylics(string inLylics)
{
	s_Lylics = inLylics;
}
//�ѹ� �ޱ�
void MusicType::SetID(string inID)
{
	s_ID = inID;
}
// ��� ���� �ޱ�
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
// �ѹ��� �ð��� ��¥�� �޾� �ڵ����� �ޱ�
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
//�ٹ����� Ű����κ��� �ޱ�
void MusicType::SetAlbumFromKB()
{
	cout << "\t�ٹ��� : ";
	cin >> s_Album;
}
// Ÿ���� Ű����κ��� �ޱ�
void MusicType::SetTypeFromKB()
{
	cout << "\tŸ��: ";
	cin >> s_Type;
}
//�帣�� Ű����κ��� �ޱ�
void MusicType::SetGenreFromKB()
{
	cout << "\t�帣 : ";
	cin >> s_Genre;
}
//����� Ű����κ��� �ޱ�
void MusicType::SetTitleFromKB()
{
	cout << "\t���: ";
	cin >> s_Title;
}
//������ Ű����κ��� �ޱ�
void MusicType::SetArtistFromKB()
{
	cout << "\t����: ";
	cin >> s_Artist;
}
//�۰�� Ű����κ��� �ޱ�
void MusicType::SetProducerFromKB()
{
	cout << "\t�۰�: ";
	cin >> s_Producer;
}
//�߸����� Ű����κ��� �ޱ�
void MusicType::SetReleaseDateFromKB()
{
	cout << "\t�߸���: ";
	cin >> s_ReleaseDate;
}
//�Ҽӻ縦 Ű����κ��� �ޱ�
void MusicType::SetEntertainmentFromKB()
{
	cout << "\t�Ҽӻ�: ";
	cin >> s_Ent;
}
//���縦 Ű����κ��� �ޱ�
void MusicType::SetLylicsFromKB()
{
	cout << "\t����: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //getline�� cin�� ' '�� �����ϱ� ���ؼ� ���
	getline(cin, s_Lylics);
}
// �ѹ��� Ű����κ��� �ޱ�
void MusicType::SetIDFromKB()
{
	cout << "\t�ѹ�: ";
	cin >> s_ID;
}
//���� ��� ������ Ű����κ��� �ޱ�, ���̵�� �ڵ��Է�
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
//���� ��� ������ Ű����κ��� �ޱ�
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
//�� �ѹ� ���
void MusicType::DisplayIDOnScreen()
{
	cout << "\t�ѹ�: " << s_ID;
}
//�ٹ��� ���
void MusicType::DisplayAlbumOnScreen()
{
	cout << "\t�ٹ���: " << s_Album;
}
//Ÿ�� ���
void MusicType::DisplayTypeOnScreen()
{
	cout << "\tŸ��: " << s_Type;
}
//�帣 ���
void MusicType::DisplayGenreOnScreen()
{
	cout << "\t�帣: " << s_Genre;
}
//��� ���
void MusicType::DisplayTitleOnScreen()
{
	cout << "\t���: " << s_Title;
}
//������ ���
void MusicType::DisplayArtistOnScreen()
{
	cout << "\t����: " << s_Artist;
}
//�۰�� ���
void MusicType::DisplayProducerOnScreen()
{
	cout << "\t�۰�: " << s_Producer;
}
//�߸��� ���
void MusicType::DisplayReleaseDateOnScreen()
{
	cout << "\t�߸���: " << s_ReleaseDate;
}
//�Ҽӻ�� ���
void MusicType::DisplayEntOnScreen()
{
	cout << "\t�Ҽӻ�: " << s_Ent;
}
//���� ���
void MusicType::DisplayLylicsOnScreen()
{
	cout << "\t����: " << s_Lylics;
}
// ��� ���� ���
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
//���Ϸκ��� �о���̱�
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
//���Ͽ� ����
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
//������ = �����ε�
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
// ������ == �����ε�
bool MusicType::operator==(MusicType & m)
{
	return s_ID == m.s_ID;
}
// ������ > �����ε�
bool MusicType::operator>(const MusicType & m)
{
	return s_ID > m.s_ID;
}
// ������ < �����ε�
bool MusicType::operator<(const MusicType & m)
{
	return s_ID < m.s_ID;
}
// ������ >= �����ε�
bool MusicType::operator>=(const MusicType & m)
{
	return s_ID >= m.s_ID;
}
// ������ <= �����ε�
bool MusicType::operator<=(const MusicType & m)
{
	return s_ID <= m.s_ID;
}

ostream& operator <<(ostream& os, MusicType& m) {
	m.DisplayMusicOnScreen();
	return os;
}

