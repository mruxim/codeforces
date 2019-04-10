#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int t;
unsigned long long f[100];
bool d[100];
int z[100];

int main()
{
	f[0] = 1; f[1] = 2;
	for (t = 2; f[t-1] < 1e19; t++)
		f[t] = f[t-1] + f[t-2];
	int tst;
	for (cin >> tst; tst--; )
	{
		unsigned long long n;
		cin >> n;
		int p;
		for (p = 0; f[p+1] <= n; p++);
		memset (d, false, sizeof d);
		for (int i = p; i >= 0; i--)
			if (n >= f[i])
				d[i] = true, n -= f[i];
		z[0] = z[1] = 0;
		int r = 1;
		for (int i = 2; i <= p; i++)
		{
			if (d[i-1])
				z[i] = 0;
			else
				z[i] = 1 + z[i - 2];
			if (d[i])
				r *= z[i] + 1;
		}
		cout << r << endl;
	}
	{ int _; cin >> _; }
}
