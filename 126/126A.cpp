#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

unsigned long long t1, t2, x1, x2, t0;
unsigned long long y1, y2;

void up (unsigned long long a, unsigned long long b)
{
	if ((t1 * a + t2 * b) * (y1 + y2) <= (t1 * y1 + t2 * y2) * (a + b))
		y1 = a, y2 = b;
}

int main()
{
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t2)
		cout << x1 << ' ' << x2 << endl;
	else if (t0 == t1)
		cout << x1 << ' ' << 0 << endl;
	else if (t0 == t2)
		cout << 0 << ' ' << x2 << endl;
	else
	{
		for (unsigned long long i = 0; i <= x1; i++)
		{
			unsigned long long z = i * (t0 - t1) / (t2 - t0);
			while (i * (t0 - t1) > z * (t2 - t0))
				z++;
			if (z >= 0 && z <= x2)
				up (i, z);
		}
		up (0, x2);
		cout << y1 << ' ' << y2 << endl;
	}
	{ int _; cin >> _; }
}
