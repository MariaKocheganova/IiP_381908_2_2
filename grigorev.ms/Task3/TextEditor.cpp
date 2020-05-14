#include"TextEditor.h"
#include"coniow.h"
TextEditor::TextEditor(unsigned x, unsigned y, unsigned s) {
	left = x;
	top = y;
	right = x + s;
	bottom = y + 1;
	size = s;
	text = "";
	for (int i = 0; i < s; i++) { text = text + "_"; }
}
void TextEditor::SetSize(unsigned x, unsigned y, unsigned s) {
	left = x;
	top = y;
	right = x + s;
	bottom = y + 1;
	if (s > size) { for (int i = 0; i < s - size; i++) { text = text + "_"; } }
	else if (size > s) { text[s] = 0; }
}
void TextEditor::InputText() {
	gotoxy(left, top);
	cin >> text;
	text = text.substr(0, size);
}
/*void TextEditor::CorrectText() {

}*/
string TextEditor::OutputText() {
	gotoxy(left, top);
	cout << text;
	return(0);
}