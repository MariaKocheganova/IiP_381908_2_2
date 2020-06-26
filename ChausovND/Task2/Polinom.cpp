#include "Polinom.h"
	
Polinom &Polinom::operator=(const Polinom& s)
{
	if (this != &s)
	{
		delete[]coeff;
		power = s.power;
		coeff = new double[power + 1];
		for (int i = 0; i <= power; i++)
			coeff[i] = s.coeff[i];
	}
	return *this;
}
Polinom Polinom::operator+(const Polinom& s)
{
	if (power >= s.power)
	{
		Polinom p = *this;
		for (int i = 0; i <= s.power; i++)
			p.coeff[i] = coeff[i] + s.coeff[i];
		return p.equalPowers(p);
	}
	else
	{
		Polinom p = s;
		for (int i = 0; i <= power; i++)
			p.coeff[i] = s.coeff[i] + coeff[i];
		return p.equalPowers(p);
	}
}
istream& operator>>(istream& s, Polinom& s2)
{
	for (int i = 0; i <= s2.power; i++)
	{
		cout << "Enter x" << i << "\n";
		s >> s2.coeff[i];
	}
	return s;
}
ostream& operator<<(ostream& s, const Polinom& s2)
{
	int q0 = 0;
	if (s2.coeff[s2.power] == 1)
		s << "x^" << s2.power;
	else if (s2.coeff[s2.power] == -1)
		s << "-x^" << s2.power;
	else if (s2.coeff[s2.power] != 0)
		s << s2.coeff[s2.power] << "x^" << s2.power;

	for (int i = 1; i <= s2.power; i++)
	{
		if (s2.coeff[i] != 0)
			q0++;
	}

	int q0_2 = q0;
	for (int i = s2.power - 1; i > 0; i--) 
	{
		if ((s2.coeff[i] > 0)) 
		{
			if ((s2.coeff[i] == 1) && (s2.coeff[i + 1] != 0) && (q0_2 != 1))
			{
				s << " + " << "x^" << i;
				q0_2--;
			}
			else
				if ((s2.coeff[i] == 1) && (s2.coeff[i + 1] == 0) && (q0_2 < 2))
				{
					s << "x^" << i;
					q0_2--;
				}
			else if (q0_2 < 2)
				s << s2.coeff[i] << "x^" << i;
			else
			{
				s << "+" << s2.coeff[i] << "x^" << i;
				q0_2--;
			}
		}
		else if ((s2.coeff[i] < 0))
		{
			if ((s2.coeff[i] == -1) && (s2.coeff[i + 1] != 0) && (q0_2 != 1))
			{
				s << " - " << "x^" << i;
				q0_2--;
			}
			else if ((s2.coeff[i] == -1) && (s2.coeff[i + 1] == 0) && (q0_2 < 2))
			{
				s << " - " << "x^" << i;
				q0_2--;
			}
			else
			{
				s << " - " << (-1) * s2.coeff[i] << "x^" << i;
				q0_2--;
			}
		}
	}
	if ((s2.coeff[0] > 0) && (q0 != 0))
		s << " + " << s2.coeff[0] << "\n";
	else if ((s2.coeff[0] < 0) && (q0 != 0))
		s << " - " << (-1) * s2.coeff[0] << "\n";
	else if ((s2.coeff[0] != 0) && (q0 == 0))
		s << s2.coeff[0] << '\n'; 
	else if (q0 == 0) s << s2.coeff[0] << '\n';
	return s; 
}
Polinom Polinom::OrigDeriv()
{
	Polinom p(power - 1);
	for (int i = 0; i <= power - 1; i++)
	{
		p.coeff[i] = (i + 1) * coeff[i + 1];
	}
	return p;
}
Polinom Polinom::equalPowers(Polinom s)
{
	int j = 0, q = 0;
	for (int i = power; q == 0; i--)
	{
		j = i;
		q = s.coeff[i];
	}

	if (j == 0 && s.coeff[0] != 0)
	{
		Polinom P(1);
		P.coeff[0] = s.coeff[0];
		return P;
	}
	else if (j > 0 && s.coeff[0] != 0)
	{
		Polinom P(j);
		for (int i = 0; i <= j; i++)
		{
			P.coeff[i] = s.coeff[i];
		}
		return P;
	}
	else return *this;
}
Polinom::Polinom()
{
	coeff = 0;
	power = 0;
}
double& Polinom::operator[](int xx)
{
	if (xx < 0 || xx > power)
		cout << "Exception: wrong index";
	else
	return coeff[xx];
}
double Polinom::xValue(double x)
{
	double res=0;
	for (int i = 0; i < power + 1; i++)
		res += coeff[i] * pow(x, i);
	return res;
}
Polinom::~Polinom()
{
	delete[]coeff;
}
Polinom::Polinom(int power2)
{
	power = power2;
	coeff = new double[unsigned int (power) + 1];
	for (int i = 0; i <= power; i++)
	{
		coeff[i] = 1;
	}
}
Polinom::Polinom(const Polinom& c)
{
	power = c.power;
	coeff = new double[unsigned int (power) + 1];
	for (int i = 0; i <= power; i++)
		coeff[i] = c.coeff[i];
}

//индексация...