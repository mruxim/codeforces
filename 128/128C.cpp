#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const unsigned int MOD = 1000 * 1000 * 1000 + 7;

int n, m, k;

unsigned int c[2005][2005];

int main()
{
	cin >> n >> m >> k;
	k = k * 2 + 1;
	n -= k;
	m -= k;
	if (n < 0 || m < 0)
	{
		cout << 0 << endl;
		return 0;
	}
	c[0][0] = 1;
	for (int i = 1; i < 2005; i++)
	{
		c[0][i] = 1;
		for (int j = 1; j <= i; j++)
			c[j][i] = (c[j][i-1] + c[j-1][i-1]) % MOD;
	}
	cout << (long long)c[n][n+k-1] * c[m][m+k-1] % (long long)MOD << endl;
	{ int _; cin >> _; }
}
