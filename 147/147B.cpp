// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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
#include <bitset>

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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 300 + 10;
const int maxlg = 9 + 1;


int n, m;
int w[maxlg][maxn][maxn];
int cur[maxn][maxn], tmp[maxn][maxn];

void mul (int c[maxn][maxn], int a[maxn][maxn], int b[maxn][maxn])
{
	memset (c, -50, sizeof cur);
	rep (i, n) rep (j, n) rep (k, n) smax (c[i][k], a[i][j]+b[j][k]);
}

bool ok (int a[maxn][maxn])
{
	rep (i, n) if (a[i][i] > 0) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;

	memset (w[0], -50, sizeof w[0]);
	rep (i, n) w[0][i][i] = 0;

	rep (i, m)
	{
		int u, v, w1, w2;
		cin >> u >> v >> w1 >> w2;
		u--, v--;
		w[0][u][v] = w1;
		w[0][v][u] = w2;
	}

	fer (i, 1, maxlg) mul (w[i], w[i-1], w[i-1]);

	int ans = 0;
	memset (cur, -50, sizeof cur);
	rep (i, n) cur[i][i] = 0;

	rof (i, maxlg, 0)
	{
		mul (tmp, cur, w[i]);
		if (!ok (tmp))
			ans += 1<<i, memcpy (cur, tmp, sizeof tmp);
	}

	cout << (ans+1 <= n ? ans+1 : 0) << endl;

	{ int _; cin >> _; return 0; }
}
