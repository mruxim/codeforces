#include <iostream>
#include <algorithm>

using namespace std;

const int MAXn = 10 + 2;

int k, n, m;
int y0, z0;
char s[MAXn][MAXn][MAXn];

int dfs (int x, int y, int z)
{
	if (x < 0 || y < 0 || z < 0 || x >= k || y >= n || z >= m)
		return 0;
	if (s[x][y][z] == '#')
		return 0;
	s[x][y][z] = '#';
	return	dfs (x+1, y, z) + dfs (x-1, y, z) +
			dfs (x, y+1, z) + dfs (x, y-1, z) + 
			dfs (x, y, z+1) + dfs (x, y, z-1) + 1;
}

int main()
{
	cin >> k >> n >> m;
	for (int x = 0; x < k; x++)
		for (int y = 0; y < n; y++)
			cin >> s[x][y];
	cin >> y0 >> z0;
	cout << dfs (0, y0 - 1, z0 - 1) << endl;
	{ int _; cin >> _; }
}
