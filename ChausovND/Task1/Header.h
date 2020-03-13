class Vector3D
{
private:
	double x, y, z;
public:
	Vector3D();
	Vector3D(double q, double w, double e);
	Vector3D(const Vector3D& temp);
	Vector3D operator* (int v1);
	Vector3D operator+(const Vector3D& temp);
	Vector3D operator-(const Vector3D& temp);
	double x(); double y(); double z();
	double mult(const Vector3D& v1);
	bool cmpr(Vector3D& v1, Vector3D& v2);
	void operator= (const Vector3D& temp);
	friend ostream& operator<< (ostream& cout, Vector3D& temp);
	friend istream& operator>> (istream& cin, Vector3D& temp);
};

Vector3D::Vector3D()
{
	x = 0.0; y = 0.0; z = 0.0;
}

Vector3D(double q, double w, double e)
{
	x = q; y = w; z = e;
}

Vector3D(const Vector3D& temp)
{
	x = temp.x; // c.x = a.x
	y = temp.y;
	z = temp.z;
}

Vector3D Vector3D::operator* (int v1)
{
	x = x * v1;
	y = y * v1;
	z = z * v1;
	return *this;
}

Vector3D Vector3D::operator+ (const Vector3D& temp)
{
	Vector3D new(0.0, 0.0, 0.0);
	new.x = x + temp.x;
	new.y = y + temp.y;
	new.z = z + temp.z;
	return new;
}

Vector3D Vector3D::operator- (const Vector3D& temp)
{
	Vector3D new(0.0, 0.0, 0.0);
	new.x = x - temp.x;
	new.y = y - temp.y;
	new.z = z - temp.z;
	return new;
}

double Vector3D::x()
{
	return x;
}

double Vector3D::y()
{
	return y;
}

double Vector3D::z()
{
	return z;
}

double Vector3D::mult(const Vector3D& v1)
{
	return (x * v1.x + y * v1.y + z * v1.z);
}

bool Vector3D::cmpr(Vector3D& v1, Vector3D& v2)
{
	if (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z) > sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z))
		return true;
	else
		return false;
}

void Vector3D::operator=(const Vector3D& temp)
{
	x = temp.x;
	y = temp.y;
	z = temp.z;
}

ostream& operator<<(ostream& cout, Vector3D& temp)
{
	cout << temp.x() << " " << temp.y() << " " << temp.z();
	return cout;
}

istream& operator>>(istream& cin, Vector3D& temp)
{
	cin >> temp.x;
	cin >> temp.y;
	cin >> temp.z;
	return cin;
}

//пытаюсь разобраться :с