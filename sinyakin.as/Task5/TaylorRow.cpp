#include"TaylorRow.h"

istream& operator>>(istream& is, Taylor& s)
{
	is >> s.n;
	is >> s.a;
	return is;
}
double Taylor::koeficienti() 
{

	int g = 1;
	cout << "_____________________________________________\n";
	
	koef = new  double[this->n]; 
	for (int i = 0; i <= this->n; i++)
	{
		if (i == 0)
		{
			koef[i] = sin(this->a);
			this->koef2[i] = koef[i];
		}
		else 
		{
			if (i % 2 == 0) 
			{
				if (i == 2 || i == 6)
				{
					g = g * i;
					koef[i] = -(sin(this->a) / g);
					this->koef2[i] = koef[i];

				}
				else 
				{

					g = g * i;
					koef[i] = sin(this->a) / g;
					this->koef2[i] = koef[i];

				}
			}
			else 
			{
				g = g * i;
				if (i == 3 || i == 7) {
					koef[i] = -(cos(this->a) / g);
					this->koef2[i] = koef[i];

				}
				else 
				{
					g = g * i;
					koef[i] = cos(this->a) / g;
					this->koef2[i] = koef[i];

				}
			}
		}
	}
	for (int i = 0; i <= this->n; i++) 
	{
		cout << koef[i] << " ";
	}
	for (int i = 0; i <= this->n; i++)
	{
		return koef[i];
	}
	cout << "***************************** \n";
}
void Taylor::OnTheScreen() 
{
	cout << "***************************** \n";

	for (int i = 0; i <= this->n; i++)
	{
		if (i == 1 || i == 5 || i == 0 || i == n || i == 2 || i == 6) {
			if (i == 0) {
				cout << this->koef2[i] << "(X-" << this->a << ")" << "+";
			}
			if (i == 1 || i == 5 || i == 2 || i == 6) { cout << this->koef2[i] << "(X-" << this->a << ")^" << i; }
			if (i == n) { cout << this->koef2[i] << "(X-" << this->a << ")^" << i; }
		}
		else { cout << this->koef2[i] << "(X-" << this->a << ")^" << i << "+"; }
	}

}
void Taylor::ElementAtTheBack()
{
	int i;
	cout << "\n";
	cin >> i;
	cout << this->koef2[i];
}



void Taylor::znach_riad() 
{
	int x;
	double s;
	s = 0.0;
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		s = s + koef2[i] * pow((x - this->a), i);
	}
	cout << s;
}

