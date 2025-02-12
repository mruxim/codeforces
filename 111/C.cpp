#include <iostream>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

int n, m, r = 99999;
int a[45][64][64];

int main()
{
	cin >> n >> m;
	if (n < m) swap (n, m);
	memset (a, 50, sizeof a);
	a[0][(1<<m)-1][0] = 0;
	#define ok(mask) (((mask) & ((1<<m)-1)) == ((1<<m)-1))
	rep (i, n) rep (x, 1<<m) rep (y, 1<<m) if (a[i][x][y] < 9999)
		rep (z, 1<<m)
			if (ok (x | y | z | (y<<1) | (y>>1)))
				a[i+1][y][z] = min (a[i+1][y][z], a[i][x][y] + __builtin_popcount (z));
	rep (x, 1<<m) rep (y, 1<<m)
		if (ok (x | y | (y<<1) | (y>>1)) && a[n][x][y] < r)
			r = a[n][x][y];
	cout << n * m - r << endl;
}
