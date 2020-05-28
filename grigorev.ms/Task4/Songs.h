#pragma once
#include<iostream>
#include<string>
using namespace std;

class Song {
private:
	string name;
	string lyric;
	string music;
	string singer;
	string album;
	string release_date;
public:
	Song() {
		name = "none"; 
		lyric = "none"; 
		music = "none"; 
		singer = "none"; 
		album = "none"; 
		release_date = "none"; 
	}
	Song(string name_c, string lyric_c, string music_c, string singer_c, string album_c, string release_date_c) {
		name = name_c;
		lyric = lyric_c;
		music = music_c;
		singer = singer_c;
		album = album_c;
		release_date = release_date_c;
	}
	~Song() {
		name = "none";
		lyric = "none";
		music = "none";
		singer = "none";
		album = "none";
		release_date = "none";
	}
	Song& operator=(const Song& copy) {
		name = copy.name;
		lyric = copy.lyric;
		music = copy.music;
		singer = copy.singer;
		album = copy.album;
		release_date = copy.release_date;
		return(*this);
	}
	string Get_Name() {
		return(name);
	}
	void Set_Name(string name_c) { 
		name = name_c; 
	}
	string Get_Lyric() {
		return(lyric);
	}
	void Set_Lyric(string lyric_c) {
		lyric = lyric_c;
	}
	string Get_Music() {
		return(music);
	}
	void Set_Music(string music_c) {
		music = music_c;
	}
	string Get_Singer() {
		return(singer);
	}
	void Set_Singer(string singer_c) {
		singer = singer_c;
	}
	string Get_Album() {
		return(album);
	}
	void Set_Album(string album_c) {
		album = album_c;
	}
	string Get_Date() {
		return(release_date);
	}
	void Set_Date(string release_date_c) {
		release_date = release_date_c;
	}
	void Get_Info() {
		cout << endl << "    Название: " << name;
		cout << endl << "    Автор текста: " << lyric;
		cout << endl << "    Автор музыки: " << music;
		cout << endl << "    Исполнитель: " << singer;
		cout << endl << "    Альбом: " << album;
		cout << endl << "    Дата выхода: " << release_date << endl;
	}
};

class Songs {
private:
	int lim = 256;
	int sortedlist[256];
public:
	int size;
	Song list[256];
	Songs() {
		size = 0;
		Song copy;
		for (int i = 0; i < 256; i++) {
			list[i] = copy;
			sortedlist[i] = 0;
		}
	}
	void Add(string name_c, string lyric_c, string music_c, string singer_c, string album_c, string release_date_c);
	void Change(string name_c);
	void Find(string name_c, string singer_c);
	int Get_Size() {
		return(size);
	}
	void Delete(string name_c);
};