#include "AlbumType.h"



AlbumType::AlbumType()
{
}


AlbumType::~AlbumType()
{
}

void AlbumType::operator=(AlbumType & a)
{
	s_Album = a.s_Album;
	s_Artist = a.s_Artist;
	s_MusicList = a.s_MusicList;
}

bool AlbumType::operator>(AlbumType & a)
{
	return s_Album > a.s_Album;
}

bool AlbumType::operator<(AlbumType & a)
{
	return s_Album < a.s_Album;
}

bool AlbumType::operator>=(AlbumType & a)
{
	return s_Album >= a.s_Album;
}

bool AlbumType::operator<=(AlbumType & a)
{
	return s_Album <= a.s_Album;
}

bool AlbumType::operator==(AlbumType & a)
{
	return s_Album == a.s_Album;
}

bool AlbumType::operator!=(AlbumType & a)
{
	return s_Album != a.s_Album;
}

ostream& operator <<(ostream& os, AlbumType& a)
{
	cout << "\n\t--------------------------------" << endl;
	a.DisplayAlbumOnScreen();
	a.DisplayArtistOnScreen();
	cout << "\n\t--------------------------------" << endl;
	return os;
}

string AlbumType::GetAlbum()
{
	return s_Album;
}

string AlbumType::GetArtist()
{
	return s_Artist;
}

void AlbumType::SetAlbum(string inalbum)
{
	s_Album = inalbum;
}

void AlbumType::SetArtist(string inartist)
{
	s_Artist = inartist;
}

void AlbumType::SetAlbumFromKB()
{
	cout << "\t¾Ù¹ü¸í: ";
	cin >> s_Album;
}

void AlbumType::AddMusicInMusicList(SimpleMusicType & data)
{
	s_MusicList.Add(data);
}

int AlbumType::DeleteMusicInMusicList(SimpleMusicType & data)
{
	if (s_MusicList.DeleteItem(data))
	{
		if (s_MusicList.GetLength() == 0)
		{
			return 0;
		}
		return 1;
	}
	return -1;
}

void AlbumType::DisplayAlbumOnScreen()
{
	cout << "\t¾Ù¹ü¸í: " << s_Album << endl;
}

void AlbumType::DisplayArtistOnScreen()
{
	cout << "\t°¡¼ö: " << s_Artist << endl;
}

AvlTree<SimpleMusicType>* AlbumType::DetailInAlbumList()
{
	return &s_MusicList;
}
