#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

const int MAXn = 1000 + 100;

int n, k;
long long l[MAXn], r[MAXn];
double v[MAXn];
double dp[MAXn][MAXn];

long long cal (long long x)
{
	if (x == 0) return 0;
	long long r = x;
	long long p = 1;
	while (x != x % p) x -= x % p, p *= 10;
	p /= 10;
	if (x == p)
		return (r - x + 1) + (p-1) / 9;
	else
		return (p * 10 - 1) / 9;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
		l[i]--;
		v[i] = (double)(cal (r[i]) - cal (l[i])) / (r[i] - l[i]);
//		cerr << v[i] << endl;
	}
	cin >> k;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i-1][0] * (1.0 - v[i-1]);
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i-1][j] * (1.0 - v[i-1]) + dp[i-1][j-1] * v[i-1];
		}
	}
	double res = 0;
	int i;
	for (i = 0; i * 100 < k * n; i++);
	for (i; i <= n; i++)
		res += dp[n][i];
	printf ("%.12lf\n", res);
	{ int _; cin >> _; }
}
