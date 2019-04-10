#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long a, b, x1, y1, x2, y2;

int main()
{
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	a *= 2, b *= 2;
	long long pa = (long long)1e12 / a * a;
	long long pb = (long long)1e12 / b * b;
	long long res = 0;
	if (abs (x1 + y1) % a == 0 && abs (x1 - y1) % b == 0)
	{
		res++;
		if (x1 + y1 <= x2 + y2) x1-y1<=x2-y2 ? x1++ : y1++; else x1-y1<=x2-y2 ? y1-- : x1--;
	}
	if (abs (x2 + y2) % a == 0 && abs (x2 - y2) % b == 0)
	{
		res++;
		if (x1 + y1 <= x2 + y2) x1-y1<=x2-y2 ? x2-- : y2--; else x1-y1<=x2-y2 ? y2++ : x2++;
	}
	if (abs (x1 + y1) % a == 0)
	{
		res++;
		if (x1 + y1 <= x2 + y2) x1++, y1++; else x1--, y1--;
	}
	if (abs (x2 + y2) % a == 0)
	{
		res++;
		if (x1 + y1 <= x2 + y2) x2--, y2--; else x2++, y2++;
	}
	if (abs (x1 - y1) % b == 0)
	{
		res++;
		if (x1 - y1 <= x2 - y2) x1++, y1--; else x1--, y1++;
	}
	if (abs (x2 - y2) % b == 0)
	{
		res++;
		if (x1 - y1 <= x2 - y2) x2--, y2++; else x2++, y2--;
	}
	long long r = abs ((x1+y1+2*pa) / a - (x2+y2+2*pa) / a);
	long long c = abs ((x1-y1+2*pb) / b - (x2-y2+2*pb) / b);
/*	cerr << r << ' ' << c << endl;
	for (int i = -20; i <= 20; i++)
	{
		for (int j = -20; j <= 20; j++)
			if (i == 0 && j == 0) cout << "0"; else
			if (i == x1 && j == y1) cout << "A"; else
			if (i == x2 && j == y2) cout << "B"; else
			cout << ((abs(i+j)%a==0 || abs(i-j)%b==0) ? "#" : ".");
		cout << endl;
	}*/
	cout << res + max (r, c) << endl;
	{ int _; cin >> _; }
}
