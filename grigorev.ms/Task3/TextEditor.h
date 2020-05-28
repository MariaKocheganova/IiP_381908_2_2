#pragma once
#include<iostream>
#include<string>
using namespace std;
class TextEditor {
public:
	unsigned int left, top, right, bottom, size;
	string text;
	TextEditor() { left = 0; top = 0; right = 40; bottom = 1; size = 40; text = ""; }
	TextEditor(unsigned x, unsigned y, unsigned s);
	~TextEditor(){ left = 0; top = 0; right = 0; bottom = 0; size = 0; text = ""; }
	void SetSize(unsigned x, unsigned y, unsigned s);
	void InputText();
	//void CorrectText();
	string OutputText();
};