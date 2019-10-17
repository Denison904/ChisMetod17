
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double  h = 0.1;


double f1(double z, double y)
{
	return (z - 1);
}

double f2(double z, double y)
{
	return (-y - 2 * z);
}

double p1(double X)
{
	return (3 + X) * exp(-X) - 2;
}
double p2(double X)
{
	return (-2 - X) * exp(-X) + 1;
}

void analit()
{
	double x = 0;
	while (x >= 0 && x < 0.9)
	{
		x += h;
		cout << "Аналитическое решение при х = : " << fixed << setprecision(1) << x << setw(20) << fixed << setprecision(6) << p1(x) << setw(20) << p2(x) << endl;
	}
	cout << endl;
}

void eil_neyav()
{
	double x = 0, y = 1, z = -1, t = 0, dy = 0, dz = 0, maxy = 0, maxz = 0;
	int i = 0;
	cout << "Неявный метод Эйлера:" << endl;
	while (x >= 0 && x < 0.9)
	{
		i++;
		x = x + h;
		t = y;
		y = -(-y * (1 + 2 * h) - h * z + h + 2 * h * h) / (h * h + 1 + 2 * h);
		dy = fabs(p1(x) - y);
		if (maxy < dy)
			maxy = dy;
		z = (h * h + z - h * t) / (h * h + 1 + 2 * h);
		if (maxz < dz)
			maxz = dz;
		dz = fabs(p2(x) - z);
		cout << "x[" << i << "]=" << fixed << setprecision(1) << x << fixed << setprecision(6) << setw(20) << "y[" << i << "]=" << y << fixed << setprecision(6) << setw(20) << "z[" << i << "]=" << z << endl;
		//cout << fixed << setprecision(6) << setw(20) << "dy["<<i<<"]=" << dy << fixed << setprecision(6) << setw(20) << "dz["<<i<<"]=" << dz << endl;
	}
	cout << "Максимальная погрешность y = " << maxy << endl;
	cout << "Максимальная погрешность z = " << maxz << endl;
	cout << endl;
}

void eil_usover()
{
	double x = 0, y = 1, z = -1, t[2], k = 0, dy = 0, dz = 0, maxy = 0, maxz = 0;
	int i = 0;
	cout << "Усовершенствованный метод Эйлера:" << endl;
	while (x >= 0 && x <= 1)
	{
		i++;
		k = y;
		t[0] = y + h / 2 * f1(z, y);
		t[1] = z + h / 2 * f2(z, y);
		x = x + h / 2;
		y = y + h * f1(t[1], t[0]);
		x = x + h / 2;
		dy = fabs(p1(x) - y);
		if (maxy < dy)
			maxy = dy;
		z = z + h * f2(t[1], t[0]);
		dz = fabs(p2(x) - z);
		if (maxz < dz)
			maxz = dz;
		cout << "x[" << i << "]=" << fixed << setprecision(1) << x << fixed << setprecision(6) << setw(20) << "y[" << i << "]=" << y << fixed << setprecision(6) << setw(20) << "z[" << i << "]=" << z << endl;
		//cout << fixed << setprecision(6) << setw(20) << "dy["<<i<<"]=" << dy << fixed << setprecision(6) << setw(20) << "dz["<<i<<"]=" << dz << endl;	
	}
	cout << "Максимальная погрешность y = " << maxy << endl;
	cout << "Максимальная погрешность z = " << maxz << endl;
	cout << endl;
}

void EK_neyav()
{
	double x = 0, y = 1, z = -1, t = 0, dy = 0, dz = 0, maxy = 0, maxz = 0;
	int i = 0;
	cout << "Неявный метод Эйлера-Коши:" << endl;
	while (x >= 0 && x < 0.9)
	{
		i++;
		x = x + h;
		t = y;
		y = -(-4 * h * z + t * h * h - 4 * t - 4 * h * t + 4 * h + 4 * h * h) / (4 + 4 * h + h * h);
		dy = fabs(y - p1(x));
		if (maxy < dy)
			maxy = dy;
		z = -(-4 * z + 4 * h * t + 4 * h * z + h * h * z - 2 * h * h) / (4 + 4 * h + h * h);
		dz = fabs(z - p2(x));
		if (maxz < dz)
			maxz = dz;
		cout << "x[" << i << "]=" << fixed << setprecision(1) << x << fixed << setprecision(6) << setw(20) << "y[" << i << "]=" << y << fixed << setprecision(6) << setw(20) << "z[" << i << "]=" << z << endl;
		//cout << fixed << setprecision(6) << setw(20) << "dy["<<i<<"]=" << dy << fixed << setprecision(6) << setw(20) << "dz["<<i<<"]=" << dz << endl;	
	}
	cout << "Максимальная погрешность y = " << maxy << endl;
	cout << "Максимальная погрешность z = " << maxz << endl;
	cout << endl;
}

void A_B3()
{
	int i = 1;
	double x = 0, y[20], z[20], p[20], dy = 0, dz = 0, maxy = 0, maxz = 0;
	y[0] = 1;
	z[0] = -1;
	cout << "Неявный метод Эйлера:" << endl;
	for (i; i < 3; i++)
	{
		x = x + h;
		y[i] = -(-4 * h * z[i - 1] + y[i - 1] * h * h - 4 * y[i - 1] - 4 * h * y[i - 1] + 4 * h + 4 * h * h) / (4 + 4 * h + h * h);
		dy = fabs(y[i] - p1(x));
		if (maxy < dy)
			maxy = dy;
		z[i] = -(-4 * z[i - 1] + 4 * h * y[i - 1] + 4 * h * z[i - 1] + h * h * z[i - 1] - 2 * h * h) / (4 + 4 * h + h * h);
		dz = fabs(z[i] - p2(x));
		if (maxz < dz)
			maxz = dz;
		cout << "x[" << i << "]=" << fixed << setprecision(1) << x << fixed << setprecision(6) << setw(20) << "y[" << i << "]=" << y[i] << fixed << setprecision(6) << setw(20) << "z[" << i << "]=" << z[i] << endl;
	}
	i = 2;
	cout << "Метод Адамса-Бошфорта 3го порядка точности:" << endl;
	while (x >= 0 && x < 0.9)
	{
		x = x + h;
		i++;
		y[i] = y[i - 1] + h / 12 * (23 * f1(z[i - 1], y[i - 1]) - 16 * f1(z[i - 2], y[i - 2]) + 5 * f1(z[i - 3], y[i - 3]));
		dy = fabs(p1(x) - y[i]);
		if (maxy < dy)
			maxy = dy;
		z[i] = z[i - 1] + h / 12 * (23 * f2(z[i - 1], y[i - 1]) - 16 * f2(z[i - 2], y[i - 2]) + 5 * f2(z[i - 3], y[i - 3]));
		dz = fabs(p2(x) - z[i]);
		if (maxz < dz)
			maxz = dz;
		cout << "x[" << i << "]=" << fixed << setprecision(1) << x << fixed << setprecision(8) << setw(20) << "y[" << i << "]=" << y[i] << fixed << setprecision(8) << setw(20) << "z[" << i << "]=" << z[i];
		cout << fixed << setprecision(6) << setw(20) << "dy[" << i << "]=" << dy << fixed << setprecision(6) << setw(20) << "dz[" << i << "]=" << dz << endl;
	}
	cout << "Максимальная погрешность y = " << maxy << endl;
	cout << "Максимальная погрешность z = " << maxz << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "russian");
	int v;
	cout << "Неявный метод Эйлера - 1" << endl << "Усовершенствованный метод Эйлера - 2" << endl << "Неявный метод Эйлера-Коши - 3" << endl << "Метод Адамса-Бошфорта 3го порядка точности - 4" << endl << "Аналитическое решение - 5" << endl;
	while (true)
	{
		cin >> v;
		if (v == 1)
			eil_neyav();
		if (v == 2)
			eil_usover();
		if (v == 3)
			EK_neyav();
		if (v == 4)
			A_B3();
		if (v == 5)
			analit();
	}
	return 0;
}
