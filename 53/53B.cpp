#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long h, w;
long long ax, ay, area;

int main()
{
	cin >> h >> w;
	long long x, y;
	for (x = 1; x <= h; x *= 2)
	{
		y = min (x * 5 / 4, w);
		if (y * 5 < x * 4)
			continue;
		if (x * y > area || (x * y == area && x > ax))
			ax = x, ay = y, area = x * y;
	}
	for (y = 1; y <= w; y *= 2)
	{
		x = min (y * 5 / 4, h);
		if (x * 5 < y * 4)
			continue;
		if (x * y > area || (x * y == area && x > ax))
			ax = x, ay = y, area = x * y;
	}
	cout << ax << ' ' << ay << endl;
	{ int _; cin >> _; }
}
