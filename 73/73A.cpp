#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long x[3], k;
long long a, b, c, r;

int main()
{
	cin >> x[0] >> x[1] >> x[2] >> k;
	x[0]--, x[1]--, x[2]--;
	sort (x, x + 3);
	a = min ((k+2) / 3, x[0]), b = min ((k+1) / 3, x[1]), c = min (k / 3, x[2]);
	r = k - a - b - c;
	int z = min (x[1] - b, r/2);
	b += z, c += r - z;
	if (c > x[2])
		c = x[2];
	cout << (a+1) * (b+1) * (c+1) << endl;
	{ int _; cin >> _; }
}
