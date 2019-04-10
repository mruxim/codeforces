#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n = 8;
char s[10][10];
bool p[10][10][10];

bool check (int r, int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	if (p[r][x][y])
		return true;
	return false;
}

int main()
{
	for (int i = 0; i < n; i++)
		cin >> s[i];
	p[0][7][0] = true;
	for (int r = 1; r <= n+1; r++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
			{
				if ((x - r + 1 >= 0 && s[x-r+1][y] == 'S') || (x - r >= 0 && s[x-r][y] == 'S'))
					continue;
				if (check (r-1, x-1, y) ||
					check (r-1, x+1, y) ||
					check (r-1, x, y-1) ||
					check (r-1, x, y+1) ||
					check (r-1, x-1, y-1) ||
					check (r-1, x+1, y+1) ||
					check (r-1, x+1, y-1) ||
					check (r-1, x-1, y+1) ||
					check (r-1, x, y))
					p[r][x][y] = true;
			}
	bool ok = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ok |= p[n+1][i][j];
	cout << (ok ? "WIN" : "LOSE") << endl;
	{ int _; cin >> _; }
}
