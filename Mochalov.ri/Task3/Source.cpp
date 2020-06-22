#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
Menu::Menu() {
	x = 0;
	y = 0;
	count = 0;
	lenght = 0;
	height = 20;
	c = 0;
}
Menu::Menu(int nx, int ny, int l, int cou, const char* s) {
	x = nx; y = ny; lenght = l; count = cou; height = 3;
	c = new char* [count];
	int i, i1 = 0, i2, len;
	for (i = 0; i < cou; i++) {
		len = 0; i2 = i1;
		while (s[i2] != ' ') { len++; i2++; }
		c[i] = new char[len + 1];
		for (int z = 0; z < len + 1; z++) c[i][z] = 0;
		for (int j = 0; j < len; j++) {
			c[i][j] = s[i1];
			i1++;
			if (s[i1] == ' ') break;
		}
		i1++; c[i][len] = 0;
	}
}
Menu::Menu(const char* f) {
	FILE* F = fopen(f, "rt");
	fscanf(F, "%d %d %d \n %d \n", &x, &y, &lenght, &count);
	c = new char* [count];
	char* s;
	fscanf(F, "%s\n", &s);
	int i, i1 = 0, i2, len;
	for (i = 0; i < count; i++) {
		len = 0; i2 = i1;
		while (s[i2] != '\n') { len++; i2++; }
		c[i] = new char[len + 1];
		for (int z = 0; z < len + 1; z++) c[i][z] = 0;
		for (int j = 0; j < len; j++) {
			c[i][j] = s[i1];
			i1++;
		}
		i1++; c[i][len] = 0;
	}
	fclose(F);
}
Menu::~Menu() {
	int i;
	for (i = 0; i < count; i++) delete(c[i]);
	delete(c);
	x = 0;
	y = 0;
	count = 0;
	lenght = 0;
	height = 0;
	c = 0;
}
void Menu::Out(const Menu& m) {
	window(x, y, x + lenght, y + height);
	textbackground(1);
	gotoxy(1, 5);
	int dx = lenght / count, dx0 = 0;
	for (int i = 0; i < count; i++) {
		puttext(dx0, 0, dx, height, c[i]);
		dx += lenght / count; dx0 += lenght / count;
	}
}