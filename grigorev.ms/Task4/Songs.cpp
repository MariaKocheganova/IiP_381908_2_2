#pragma once
#include"Songs.h"
#include<iostream>

void Songs::Add(string name_c, string lyric_c, string music_c, string singer_c, string album_c, string release_date_c) {
	if (size < 256) {
		Song copy(name_c, lyric_c, music_c, singer_c, album_c, release_date_c);
		list[size] = copy;
		size++;
	}
}
void Songs::Change(string name_c) {
	int pos = 0;
	string name_c_c, lyric_c, music_c, singer_c, album_c, release_date_c;
	while (pos < size && list[pos].Get_Name() != name_c) { pos++; }
	cout << endl << "Если не требуется изменять параметр, введите none";
	cout << endl << "Введите название - ";
	cin >> name_c_c;
	cout << "Введите автора текста - ";
	cin >> lyric_c;
	cout << "Введите автора музыки - ";
	cin >> music_c;
	cout << "Введите исполнителя - ";
	cin >> singer_c;
	cout << "Введиете название альбома - ";
	cin >> album_c;
	cout << "Введите дату релиза - ";
	cin >> release_date_c;
	if (name_c_c != "none") { list[pos].Set_Name(name_c_c); }
	if (lyric_c != "none") { list[pos].Set_Lyric(lyric_c); }
	if (music_c != "none") { list[pos].Set_Music(music_c); }
	if (singer_c != "none") { list[pos].Set_Singer(singer_c); }
	if (album_c != "none") { list[pos].Set_Album(album_c); }
	if (release_date_c != "none") { list[pos].Set_Date(release_date_c); }
}
void Songs::Find(string name_c, string singer_c) {
	int pos = 0;
	while (pos < size && list[pos].Get_Name() != name_c && list[pos].Get_Singer() != singer_c) { pos++; }
	if (pos == size) { cout << endl << "Не найдено. Проверьте корректность запроса"; }
	else { cout << endl << "По вашему запросу найдена следующая информация:"; list[pos].Get_Info(); }
}
void Songs::Delete(string name_c) {
	int pos = 0;
	while (pos < size && list[pos].Get_Name() != name_c) { pos++; }
	for (int i = pos; i < size; i++) {
		list[i] = list[i + 1];
	}
	size--;
	cout << "Операция завершена" << endl;
}