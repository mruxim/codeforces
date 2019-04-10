#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#define ABS(X) ((X)>0?(X):-(X))

const int MAXn = 1000 + 10;

long long n, m;
char a[MAXn][MAXn];
long long x[MAXn], y[MAXn], t;
long long r[MAXn], c[MAXn];
long long nd, md, sum;

int main()
{
	memset (r, -1, sizeof r);
	memset (c, -1, sizeof c);
	ios::sync_with_stdio (false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < m; j++)
			if (a[i][j] == 'X')
			{
				r[i] = j, c[j] = i;
				x[t] = i, y[t] = j, t++;
			}
	}
	for (int i = 1; i < n; i++) nd += i * (n - i) * 2;
	for (int i = 1; i < m; i++) md += i * (m - i) * 2;
	sum = nd*m*m + md*n*n;
	for (int i = 0; i < t; i++)
	{
		long long s = 0;
		s += (x[i] * (x[i] + 1) / 2 + (n - x[i] - 1) * (n - x[i]) / 2) * m;
		s += (y[i] * (y[i] + 1) / 2 + (m - y[i] - 1) * (m - y[i]) / 2) * n;
		sum -= 2*s;
	}
	for (int i = 0; i < n; i++)
	{
		if (r[i] == -1) continue;
		for (int j = i; j < n && r[j] != -1 && r[j] >= r[i]; j++) sum += r[i] * (m - r[j] - 1) * 4;
		for (int j = i-1; j < n && r[j] != -1 && r[j] <= r[i]; j++) sum += (m - r[i] - 1) * r[j] * 4;
	}
	for (int i = 0; i < m; i++)
	{
		if (c[i] == -1) continue;
		for (int j = i; j < m && c[j] != -1 && c[j] >= c[i]; j++) sum += c[i] * (n - c[j] - 1) * 4;
		for (int j = i-1; j < m && c[j] != -1 && c[j] <= c[i]; j++) sum += (n - c[i] - 1) * c[j] * 4;
	}
	for (int i = 0; i < t; i++)
		for (int j = 0; j < t; j++)
			sum += (ABS (x[i] - x[j]) + ABS (y[i] - y[j]));
	cout << fixed << setprecision (8) << (double)sum / (double)((n*m-t)*(n*m-t)) << endl;
	{ int _; cin >> _; }
}
