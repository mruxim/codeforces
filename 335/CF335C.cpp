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

const int maxr = 100 + 100;

int r, n;
pii p[maxr];
int nim[maxr][4];
bool mark[5*maxr];

int main()
{
	ios::sync_with_stdio (false);

	cin >> r >> n;
	rep (i, n) cin >> p[i].X >> p[i].Y, p[i].Y--;
	sort (p, p+n);

	fer (i, 1, r+2) rep (j, 4)
	{
//		if (i == 1) { nim[i][j] = 0; continue; }
		memset (mark, false, sizeof mark);
		fer (k, 1, i) rep (d, 2)
		{
			int x, y;
			if (j >= 2) x = 2 + d; else x = 1;
			if (j==0) y = 1; else if (j==1 || j==2) y = 2+d; else y = 3-d;
			if (k == 1 && x == 3) continue;
			if (i-k == 1 && y == 3) continue;
			mark[nim[k][x] ^ nim[i-k][y]] = true;
		}
		nim[i][j] = 0;
		while (mark[nim[i][j]]) nim[i][j]++;
	//	cerr << i << ' ' << j << " = " << nim[i][j] << endl;
	}

	int f = 0;
	if (n)
	{
		fer (i, 1, n) f ^= nim[p[i].X - p[i-1].X][2 + (p[i].Y ^ p[i-1].Y)];
		f ^= nim[p[0].X][1];
		f ^= nim[r-p[n-1].X+1][1];
	}
	else
		f = nim[r+1][0];

	cout << (f ? "WIN" : "LOSE") << endl;

	{ int _; cin >> _; return 0; }
}
