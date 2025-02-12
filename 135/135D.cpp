#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXn = 1000 + 100;

int n, m;
string s[MAXn];
int a[MAXn][MAXn], b[MAXn][MAXn];
int col = 1;
int v[MAXn*MAXn], ok[MAXn*MAXn];
int rx, ry;

void dfs (int x, int y)
{
	if (a[x][y] != -1) return;
	a[x][y] = col;
	dfs (x, y-1);
	dfs (x, y+1);
	dfs (x-1, y);
	dfs (x+1, y);
	dfs (x-1, y-1);
	dfs (x+1, y+1);
	dfs (x-1, y+1);
	dfs (x+1, y-1);

	if (a[x-1][y] != col && a[x-1][y] != -2) ok[col] = 1;
	if (a[x+1][y] != col && a[x+1][y] != -2) ok[col] = 1;
	if (a[x][y-1] != col && a[x][y-1] != -2) ok[col] = 1;
	if (a[x][y+1] != col && a[x][y+1] != -2) ok[col] = 1;
	if (a[x-1][y-1] != col && a[x-1][y-1] != -2) ok[col] = 1;
	if (a[x-1][y+1] != col && a[x-1][y+1] != -2) ok[col] = 1;
	if (a[x+1][y-1] != col && a[x+1][y-1] != -2) ok[col] = 1;
	if (a[x+1][y+1] != col && a[x+1][y+1] != -2) ok[col] = 1;

	if (a[x][y-1] == -2 && b[x][y-1] != col) rx = x, ry = y-1, v[col]++, b[x][y-1] = col;
	if (a[x][y+1] == -2 && b[x][y+1] != col) v[col]++, b[x][y+1] = col;
	if (a[x-1][y] == -2 && b[x-1][y] != col) v[col]++, b[x-1][y] = col;
	if (a[x+1][y] == -2 && b[x+1][y] != col) v[col]++, b[x+1][y] = col;

	if (a[x-1][y-1] == -2 && b[x-1][y-1] != col) v[col]++, b[x-1][y-1] = col;
	if (a[x+1][y+1] == -2 && b[x+1][y+1] != col) v[col]++, b[x+1][y+1] = col;
	if (a[x-1][y+1] == -2 && b[x-1][y+1] != col) v[col]++, b[x-1][y+1] = col;
	if (a[x+1][y-1] == -2 && b[x+1][y-1] != col) v[col]++, b[x+1][y-1] = col;
}

int dfs2 (int x, int y)
{
	if (b[x][y] != col) return 0;
	int z = 0;
	b[x][y] = -col;
	if (abs(b[x][y-1]) == col) z++;
	if (abs(b[x][y+1]) == col) z++;
	if (abs(b[x-1][y]) == col) z++;
	if (abs(b[x+1][y]) == col) z++;
	if (z != 2)
		return -9999999;
	return 1 + dfs2 (x, y-1) + dfs2 (x, y+1) + dfs2 (x-1, y) + dfs2 (x+1, y);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i+1][j+1] = s[i][j]=='1' ? -2 : -1;

	int ans = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (a[i][j] == -2 && a[i][j+1] == -2 && a[i+1][j] == -2 && a[i+1][j+1] == -2)
				ans = 4;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == -1)
			{
				dfs (i, j);

				if (!ok[col])
				{
					int tmp = dfs2 (rx, ry);
					if (tmp == v[col])
						ans = max (ans, v[col]);
				}
				col++;
			}

	cout << ans << endl;
	{ int _; cin >> _; }
}
