#include "PedometerHeader.h"

Date::Date() {
	h_s = new int[2];
	h_e = new int[2];
	for (int i = 0; i < 2; i++) {
		h_s[i] = 0;
		h_e[i] = 0;
	}
	data = new int[3];
	for (int i = 0; i < 3; i++) {
		data[i] = 0;
	}
	st = 0;
}

Date::Date(int* _h_s, int* _h_e, int* _data, int _st) {
	h_s = new int[2];
	h_e = new int[2];
	data = new int[3];
	for (int i = 0; i < 2; i++) {
		h_s[i] = _h_s[i];
		h_e[i] = _h_e[i];
	}
	for (int i = 0; i < 3; i++) {
		data[i] = _data[i];
	}
	st = _st;
}

Date::Date(const Date& c) {
	h_s = new int[2];
	h_e = new int[2];
	data = new int[3];
	for (int i = 0; i < 2; i++) {
		h_s[i] = c.h_s[i];
		h_e[i] = c.h_e[i];
	}
	for (int i = 0; i < 3; i++) {
		data[i] = c.data[i];
	}
	st = c.st;
}

Date::~Date() {
	delete[] h_s;
	delete[] h_e;
	delete[] data;

	st = 0;
}

Pedometer::Pedometer() {
	count = 0;
}

Pedometer::Pedometer(int* _h_s, int* _h_e, int* _data, int _st) {
	num = new Date[1];
	for (int i = 0; i < 2; i++) {
		num[0].h_s[i] = _h_s[i];
		num[0].h_e[i] = _h_e[i];
	}
	for (int i = 0; i < 3; i++) {
		num[0].data[i] = _data[i];
	}
	num[0].st = _st;
}

Pedometer::Pedometer(const Pedometer& c) {
	count = c.count;
	num = new Date[count];
	for (int j = 0; j < c.count; ++j) {
		for (int i = 0; i < 2; i++) {
			num[j].h_s[i] = c.num[j].h_s[i];
			num[j].h_e[i] = c.num[j].h_e[i];
		}
		for (int i = 0; i < 3; i++) {
			num[j].data[i] = c.num[j].data[i];
		}
		num[j].st = c.num[j].st;
	}
}

Date Date::operator=(Date& c) {
	for (int i = 0; i < 2; i++) {
		h_s[i] = c.h_s[i];
		h_e[i] = c.h_e[i];
	}
	for (int i = 0; i < 3; i++) {
		data[i] = c.data[i];
	}
	st = c.st;
	return *this;
}

Pedometer::~Pedometer() {
	if (count != 0) {
		count = 0;
		delete[] num;
	}
}

Pedometer Pedometer::operator=(Pedometer& c) {
	if (count != c.count) {
		if (count != 0) delete[] num;
		num = new Date[count];
		count = c.count;
	}

	for (int i = 0; i < count; i++) {
		num[i] = c.num[i];
	}
	for (int i = 0; i < count; i++) {
		num[i].h_s[i] = c.num[i].h_s[i];
		num[i].h_e[i] = c.num[i].h_e[i];
		num[i].st = c.num[i].st;
		for (int j = 0; j < 3; j++)
			num[i].data[j] = c.num[i].data[j];
	}
	return *this;
}

void Pedometer::menu() {
	int w = 0;
	Date first_data;

	first_data.getdate();
	(*this).setdate(first_data);
	first_data.inpsetdate();

	infile();
	while (w != 8) {
		do {
			cout << "Ìåíþ óïðàâëåíèÿ âàøèì øàãîìåðîì:" << endl;
			cout << "'1' Äîáàâèòü ïîäñ÷¸ò øàãîâ." << endl;
			cout << "'2' Èíôîðìàöèÿ î äîáàâëåííûõ ïîäñ÷¸òàõ." << endl;
			cout << "'3' Íàéòè ñðåäíåå ÷èñëî øàãîâ â âûáðàííîì ìåñÿöå çà âñþ èñòîðèþ íàáëþäåíèé." << endl;
			cout << "'4' Íàéòè ìàêñèìàëüíîå ÷èñëî øàãîâ â âûáðàííîì ìåñÿöå çà âñþ èñòîðèþ íàáëþäåíèé." << endl;
			cout << "'5' Ñîõðàíèòü èñòîðèþ ïîäñ÷¸òîâ â ôàéë." << endl;
			cout << "'6' Ñ÷èòàòü èç ôàéëà èñòîðèþ ïîäñ÷¸òîâ." << endl;
			cout << "'7' Óçíàòü èíôîðìàöèþ î ïåðâîì ïîäñ÷¸òå øàãîìåðà." << endl;
			cout << "'8' Çàâåðøèòü ïðîãðàììó." << endl;
			cout << "Âûáîð: ";
			cin >> w;
			if (w < 1 || w>8) {
				cout << endl << "Âû ââåëè íåïðàâèëüíûé íîìåð äåéñòâèÿ. Ïîâòîðèòå:" << endl << endl;
			}
		} while (w < 1 || w>8);
		if (w == 1) {
			first_data.getdate();
			(*this).setdate(first_data);
			first_data.inpsetdate();
		}
		if (w == 2) {
			info();
		}
		if (w == 3) {
			show_srmonth();
		}
		if (w == 4) {
			show_maxmonth();
		}
		if (w == 5) {
			infile();
		}
		if (w == 6) {
			outfile();
		}
		if (w == 7) {
			onedate();
		}
		if (w == 8) {
			system("pause");
		}
	}
}

void Pedometer::onedate() {

	cout << endl << "Íà÷àëüíàÿ äàòà ïåðâîãî ïîäñ÷¸òà: ";
	if (num[0].data[0] < 10) {
		cout << "0" << num[0].data[0];
	}
	else {
		cout << num[0].data[0];
	}
	if (num[0].data[1] < 10) {
		cout << ":" << "0" << num[0].data[1];
	}
	else {
		cout << ":" << num[0].data[1];
	}
	cout << ":" << num[0].data[2] << endl;
	if (num[0].h_s[0] < 10) {
		cout << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << "0" << num[0].h_s[0];
	}
	else {
		cout << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << num[0].h_s[0];
	}
	if (num[0].h_s[1] < 10) {
		cout << ":" << "0" << num[0].h_s[1] << " | ";
	}
	else {
		cout << ":" << num[0].h_s[1] << " | ";
	}
	if (num[0].h_e[0] < 10) {
		cout << "0" << num[0].h_e[0] << ":";
	}
	else {
		cout << num[0].h_e[0] << ":";
	}
	if (num[0].h_e[1] < 10) {
		cout << "0" << num[0].h_e[1] << endl;
	}
	else {
		cout << num[0].h_e[1] << endl;
	}
	cout << "Øàãîâ ñäåëàíî çà äàííûé ïåðèîä: " << num[0].st << endl << endl;
}

void Pedometer::infile() {
	ofstream in;
	in.open("Info.txt");
	for (int i = 0; i < count; i++) {
		if (count == 1) {
			in << endl << "Íà÷àëüíàÿ äàòà: ";
		}
		else {
			in << endl;
			in << "Äàòà: ";
		}
		if (num[i].data[0] < 10) {
			in << "0" << num[i].data[0];
		}
		else {
			in << num[i].data[0];
		}
		if (num[i].data[1] < 10) {
			in << ":" << "0" << num[i].data[1];
		}
		else {
			in << ":" << num[i].data[1];
		}
		in << ":" << num[i].data[2] << endl;
		if (num[i].h_s[0] < 10) {
			if (count == 1)
				in << "Íà÷àëüíîå âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << "0" << num[i].h_s[0];
			else in << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << "0" << num[i].h_s[0];
		}
		else {
			if (count == 1)
				in << "Íà÷àëüíîå âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << num[i].h_s[0];
			else in << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << num[i].h_s[0];
		}
		if (num[i].h_s[1] < 10) {
			in << ":" << "0" << num[i].h_s[1] << " | ";
		}
		else {
			in << ":" << num[i].h_s[1] << " | ";
		}
		if (num[i].h_e[0] < 10) {
			in << "0" << num[i].h_e[0] << ":";
		}
		else {
			in << num[i].h_e[0] << ":";
		}
		if (num[i].h_e[1] < 10) {
			in << "0" << num[i].h_e[1] << endl;
		}
		else {
			in << num[i].h_e[1] << endl;
		}
		in << "Øàãîâ ñäåëàíî çà äàííûé ïåðèîä: " << num[i].st << endl << endl;
	}
	in.close();
	if (count > 1)
		cout << endl << "Ïîäñ÷¸ò ñîõðàíåí â ôàéë" << endl << endl;
}

void Pedometer::outfile() {
	string str;
	ifstream out("Info.txt");
	if (!out.is_open()) {
		throw logic_error("not find file");
		cout << "Íå óäàëîñü îòêðûòü ôàéë" << endl;
	}
	else {
		while (!out.eof()) {
			str = "";
			getline(out, str);
			cout << str << endl;
		}
	}
	out.close();
}

int Pedometer::inpmonth() {
	Date mon;
	do {
		cout << endl << "Ââåäèòå ìåñÿö, ïî êîòîðîìó íàéäåòñÿ ñðåäíåå êîë-âî øàãîâ çà âåñü ïåðèîä âðåìåíè äàííîãî ìåñÿöà:" << endl;
		cout << "Ìåñÿö[1-12]: ";
		cin >> mon.data[1];
		if (mon.data[1] < 1 || mon.data[1] > 12) {
			cout << "Âñåãî 12 êàëåíäàðíûõ ìåñÿöåâ. Ââåäèòå ìåñÿö îò 1 äî 12:" << endl;
		}
	} while (mon.data[1] < 1 || mon.data[1] > 12);
	cout << endl;
	return mon.data[1];
}

int Pedometer::srmonth() {
	int k = 0;
	int res = 0;
	int rez = 0;
	int f;
	int month = inpmonth();
	int* steep = new int;
	for (int i = 0; i < count; i++) {
		if (month == num[i].data[1]) {
			steep[k] = num[i].st;
			k++;
			f = i;
		}
	}
	if (count >= 2) {
		for (int i = 0; i < k; i++) {
			res = res + steep[i];
		}
		if (k > 1) {
			res = res / k;
			rez = res;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (month == num[i].data[1]) {
					rez = num[i].st;
				}
				else {
					if (month != num[i].data[1] && i == count - 1) {
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			if (month == num[i].data[1]) {
				rez = num[i].st;
			}
			else {
				if (month != num[i].data[1] && i == count - 1) {
				}
			}
		}
	}
	return rez;
}

void Pedometer::show_srmonth() {
	int ress = srmonth();
	if (ress != 0) {
		cout << "Ñðåäíåå êîëè÷åñòâî øàãîâ: " << ress << endl << endl;
	}
	else {
		cout << "Íå íàéäåíî ïîäñ÷¸òîâ â ýòîì ìåñÿöå." << endl << endl;
	}
}

int Pedometer::maxmonth() {
	int* steep = new int;
	int k = 0;
	int f;
	int ress = 0;
	int month = inpmonth();
	if (count >= 2) {
		for (int i = 0; i < count; i++) {
			if (month == num[i].data[1]) {
				steep[k] = num[i].st;
				k++;
				f = i;
			}
		}
		if (k > 1) {
			int max = steep[0];
			for (int i = 1; i < k; i++) {
				if (steep[i] > max) {
					max = steep[i];
				}
			}
			ress = max;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (month == num[i].data[1]) {
					ress = num[i].st;
				}
				else {
					if (month != num[i].data[1] && i == count - 1) {
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			if (month == num[i].data[1]) {
				ress = num[i].st;
			}
			else {
				if (month != num[i].data[1] && i == count - 1) {
				}
			}
		}
	}
	return ress;
}

void Pedometer::show_maxmonth() {
	int rezz = maxmonth();
	if (rezz != 0) {
		cout << "Ìàêñèìàëüíîå êîëè÷åñòâî øàãîâ: " << rezz << endl << endl;
	}
	else {
		cout << "Íå íàéäåíî ïîäñ÷¸òîâ â ýòîì ìåñÿöå." << endl << endl;
	}
}

int Pedometer::inpinfoday() {
	Date get;
	cout << "Ââåäèòå äàòó, ÷òîáû ïîëó÷èòü èíôîðìàöèþ î ïîäñ÷¸òàõ. Äåíü,Ìåñÿö,Ãîä:" << endl;
	do {
		cout << "Äåíü[1-31]: ";
		cin >> get.data[0];
		if (get.data[0] < 1 || get.data[0] > 31) {
			cout << "Âñåãî 31 êàëåíäàðíûõ äíåé. Ââåäèòå äåíü îò 1 äî 31:" << endl;
		}
	} while (get.data[0] < 1 || get.data[0] > 31);
	return get.data[0];
}

int Pedometer::inpinfomonth() {
	Date get;
	do {
		cout << "Ìåñÿö[1-12]: ";
		cin >> get.data[1];
		if (get.data[1] < 1 || get.data[1] > 12) {
			cout << "Âñåãî 12 êàëåíäàðíûõ ìåñÿöåâ. Ââåäèòå ìåñÿö îò 1 äî 12:" << endl;
		}
	} while (get.data[1] < 1 || get.data[1] > 12);
	return get.data[1];
}

int Pedometer::inpinfoyear() {
	Date get;
	do {
		cout << "Ãîä[Ôîðìàò YYYY]: ";
		cin >> get.data[2];
		if (get.data[2] < 1000 || get.data[2] > 9999) {
			cout << "Ââåäåííûé âàìè ôîðìàò íå ñîîòâåòñòâóåò ñ ôîðìàòîì äëèíû YYYY, ïîâòîðèòå:" << endl;
		}
	} while (get.data[2] < 1000 || get.data[2] > 9999);
	return get.data[2];
}

int Pedometer::inpinfoh_s0() {
	Date get;
	cout << "Ââåäèòå èíòåðâàë âðåìåíè àêòèâíîñòè. ×àñ, ìèíóòà (íà÷àëà äâèæåíèÿ)" << endl;
	do {
		cout << "×àñ[0-23]: ";
		cin >> get.h_s[0];
		if (get.h_s[0] < 0 || get.h_s[0] > 23) {
			cout << "Ââåäåííîå âðåìÿ(×àñ) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 23, ïîâòîðèòå:" << endl;
		}
	} while (get.h_s[0] < 0 || get.h_s[0] > 23);
	return get.h_s[0];
}

int Pedometer::inpinfoh_s1() {
	Date get;
	do {
		cout << "Ìèíóòà[0-59]: ";
		cin >> get.h_s[1];
		if (get.h_s[1] < 0 || get.h_s[1] > 59) {
			cout << "Ââåäåííîå âðåìÿ(Ìèíóòà) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 59, ïîâòîðèòå:" << endl;
		}
	} while (get.h_s[1] < 0 || get.h_s[1] > 59);
	return get.h_s[1];
}

int Pedometer::inpinfoh_e0() {
	Date get;
	cout << "Ââåäèòå èíòåðâàë âðåìåíè àêòèâíîñòè. ×àñ, ìèíóòà (îêîí÷àíèÿ äâèæåíèÿ)" << endl;
	do {
		cout << "×àñ[0-23]: ";
		cin >> get.h_e[0];
		if (get.h_e[0] < 0 || get.h_e[0] > 23) {
			cout << "Ââåäåííîå âðåìÿ(×àñ) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 23, ïîâòîðèòå:" << endl;
		}
	} while (get.h_e[0] < 0 || get.h_e[0] > 23);
	return get.h_e[0];
}

int Pedometer::inpinfoh_e1() {
	Date get;
	do {
		cout << "Ìèíóòà[0-59]: ";
		cin >> get.h_e[1];
		if (get.h_e[1] < 0 || get.h_e[1] > 59) {
			cout << "Ââåäåííîå âðåìÿ(Ìèíóòà) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 59, ïîâòîðèòå:" << endl;
		}
	} while (get.h_e[1] < 0 || get.h_e[1] > 59);
	return get.h_e[1];
}

void Pedometer::info() {

	cout << endl;
	int* arr = new int[count];
	int day = inpinfoday();
	int month = inpinfomonth();
	int year = inpinfoyear();
	int hs0 = inpinfoh_s0();
	int hs1 = inpinfoh_s1();
	int he0 = inpinfoh_e0();
	int he1 = inpinfoh_e1();
	cout << endl;
	for (int i = 0, j = 1; i < count; i++) {
		if (day == num[i].data[0] && month == num[i].data[1] && year == num[i].data[2]) {
			if (hs0 <= num[i].h_s[0] && he0 >= num[i].h_e[0] && hs0 <= num[i].h_e[0] && he0 >= num[i].h_s[0] &&
				hs1 <= num[i].h_s[1] && he0 >= num[i].h_e[1] && hs1 <= num[i].h_e[1] && he1 >= num[i].h_s[1]) {
				cout << "Ïîäñ÷¸ò ¹" << j << endl;
				if (num[i].h_s[0] < 10) {
					cout << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << "0" << num[i].h_s[0];
				}
				else {
					cout << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << num[i].h_s[0];
				}
				if (num[i].h_s[1] < 10) {
					cout << ":" << "0" << num[i].h_s[1] << " | ";
				}
				else {
					cout << ":" << num[i].h_s[1] << " | ";
				}
				if (num[i].h_e[0] < 10) {
					cout << "0" << num[i].h_e[0] << ":";
				}
				else {
					cout << num[i].h_e[0] << ":";
				}
				if (num[i].h_e[1] < 10) {
					cout << "0" << num[i].h_e[1] << endl;
				}
				else {
					cout << num[i].h_e[1] << endl;
				}
				cout << "Øàãîâ ñäåëàíî çà äàííûé ïåðèîä: " << num[i].st << endl << endl;
			}
			else {
				cout << endl << "Ïîäñ÷¸òîâ íå íàéäåíî." << endl;
			}
		}
	}
}

void Date::getdate() {
	cout << "Ââåäèòå äàòó. Äåíü,Ìåñÿö,Ãîä:" << endl;
	do {
		cout << "Äåíü[1-31]: ";
		cin >> data[0];
		if (data[0] < 1 || data[0] > 31) {
			cout << "Âñåãî 31 êàëåíäàðíûõ äíåé. Ââåäèòå äåíü îò 1 äî 31:" << endl;
		}
	} while (data[0] < 1 || data[0] > 31);
	do {
		cout << "Ìåñÿö[1-12]: ";
		cin >> data[1];
		if (data[1] < 1 || data[1] > 12) {
			cout << "Âñåãî 12 êàëåíäàðíûõ ìåñÿöåâ. Ââåäèòå ìåñÿö îò 1 äî 12:" << endl;
		}
	} while (data[1] < 1 || data[1] > 12);
	do {
		cout << "Ãîä[Ôîðìàò YYYY]: ";
		cin >> data[2];
		if (data[2] < 1000 || data[2] > 9999) {
			cout << "Ââåäåííûé âàìè ôîðìàò íå ñîîòâåòñòâóåò ñ ôîðìàòîì äëèíû YYYY, ïîâòîðèòå:" << endl;
		}
	} while (data[2] < 1000 || data[2] > 9999);

	cout << "Ââåäèòå âðåìÿ àêòèâíîñòè. ×àñ, ìèíóòà (íà÷àëà äâèæåíèÿ)" << endl;

	do {
		cout << "×àñ[0-23]: ";
		cin >> h_s[0];
		if (h_s[0] < 0 || h_s[0] > 23) {
			cout << "Ââåäåííîå âðåìÿ(×àñ) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 23, ïîâòîðèòå:" << endl;
		}
	} while (h_s[0] < 0 || h_s[0] > 23);
	do {
		cout << "Ìèíóòà[0-59]: ";
		cin >> h_s[1];
		if (h_s[1] < 0 || h_s[1] > 59) {
			cout << "Ââåäåííîå âðåìÿ(Ìèíóòà) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 59, ïîâòîðèòå:" << endl;
		}
	} while (h_s[1] < 0 || h_s[1] > 59);

	cout << "Ââåäèòå âðåìÿ àêòèâíîñòè. ×àñ, ìèíóòà (îêîí÷àíèÿ äâèæåíèÿ)" << endl;
	do {
		cout << "×àñ[0-23]: ";
		cin >> h_e[0];
		if (h_e[0] < 0 || h_e[0] > 23) {
			cout << "Ââåäåííîå âðåìÿ(×àñ) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 23, ïîâòîðèòå:" << endl;
		}
	} while (h_e[0] < 0 || h_e[0] > 23);
	do {
		cout << "Ìèíóòà[0-59]: ";
		cin >> h_e[1];
		if (h_e[1] < 0 || h_e[1] > 59) {
			cout << "Ââåäåííîå âðåìÿ(Ìèíóòà) íå ñîîòâåòñòâóåò ôîðìàòó îò 0 äî 59, ïîâòîðèòå:" << endl;
		}
	} while (h_e[1] < 0 || h_e[1] > 59);
	cout << "Ââåäèòå êîëè÷åñòâî ïðîéäåííûõ øàãîâ çà óêàçàííûé ïåðèîä âðåìåíè:" << endl;
	do {
		cin >> st;
		if (st < 0) {
			cout << "Ââåäåííîå âàìè êîëè÷åñòâî øàãîâ íå ìîæåò áûòü îòðèöàòåëüíûì, ïîâòîðèòå:" << endl;
		}
	} while (st < 0);
	system("CLS");
}

void Date::inpsetdate() {
	cout << "Ââåäåííûå âàìè äàííûå:" << endl;
	cout << "Äàòà: ";
	if (data[0] < 10) {
		cout << "0" << data[0];
	}
	else {
		cout << data[0];
	}
	if (data[1] < 10) {
		cout << ":" << "0" << data[1];
	}
	else {
		cout << ":" << data[1];
	}
	cout << ":" << data[2] << endl;
	if (h_s[0] < 10) {
		cout << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << "0" << h_s[0];
	}
	else {
		cout << "Âðåìÿ íà÷àëà|îêîí÷àíèÿ äâèæåíèÿ: " << h_s[0];
	}
	if (h_s[1] < 10) {
		cout << ":" << "0" << h_s[1] << " | ";
	}
	else {
		cout << ":" << h_s[1] << " | ";
	}
	if (h_e[0] < 10) {
		cout << "0" << h_e[0] << ":";
	}
	else {
		cout << h_e[0] << ":";
	}
	if (h_e[1] < 10) {
		cout << "0" << h_e[1] << endl;
	}
	else {
		cout << h_e[1] << endl;
	}
	cout << "Øàãîâ ñäåëàíî çà äàííûé ïåðèîä: " << st << endl << endl;
}

void Pedometer::setdate(Date new_data) {
	Pedometer copy(*this);
	if (count != 0) {
		delete[] num;
	}
	num = new Date[count + 1];
	count = count + 1;
	for (int i = 0; i < count - 1; ++i) {
		num[i] = copy.num[i];
	}
	num[count - 1] = new_data;
}