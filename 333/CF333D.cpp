// .... .... .....!
// P..... C.....!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000 + 50;

int n, m;
int a[maxn][maxn];
int b[maxn][maxn];
int t[maxn];
int mark[maxn][maxn];

bool check ()
{
	memset (mark, 0, sizeof mark);
	rep (i, n)
	{
		rep (j, t[i]) fer (k, j+1, t[i])
		{
			if (mark[b[i][j]][b[i][k]])
				return true;
			mark[b[i][j]][b[i][k]] = 1;
		}
	}
	return false;
}


int main()
{
	scanf ("%d %d", &n, &m);
	rep (i, n) rep (j, m) scanf ("%d", &a[i][j]);

	int lo = 0, hi = 1e9+5;
	while (hi-lo > 1)
	{
		int md = (lo+hi) / 2;
		rep (i, n)
		{
			t[i] = 0;
			rep (j, m) if (a[i][j] >= md)
				b[i][t[i]++] = j;
		}
		if (check())
			lo = md;
		else
			hi = md;
	}

	printf ("%d\n", lo);

	{ int _; cin >> _; return 0; }
}
