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

int n, m, volume;
ll initial[maxn], desired[maxn];
int graph[maxn][maxn];
ll trans[maxn][maxn];
bool mark[maxn];
vector<pair<pii, int>> ans;

ll dfs (int u)
{
	if (mark[u]) return 0; mark[u] = 1;

	ll my_need = desired[u] - initial[u];
	rep (v, n) if (graph[u][v])
	{
		ll need = dfs (v);
		trans[u][v] += need;
		my_need += need;
	}

	return my_need;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> volume >> m;
	rep (i, n) cin >> initial[i];
	rep (i, n) cin >> desired[i];
	rep (i, m) { int x, y; cin >> x >> y; x--, y--; graph[x][y] = graph[y][x] = 1; }

	rep (i, n) if (!mark[i])
	{
		ll need = dfs (i);
		if (need != 0) { cout << "NO" << endl; return 0; }
	}

	rep (i, n) rep (j, n) if (trans[i][j] < 0) trans[j][i] = -trans[i][j], trans[i][j] = 0;

	for (bool con = true; con; )
	{
		con = false;
		rep (i, n) rep (j, n) if (trans[i][j] && initial[i] && initial[j] < volume)
		{
			ll amount = min (trans[i][j], min (initial[i], volume - initial[j]));
			ans.pb ({{i, j}, amount});
			initial[i] -= amount;
			initial[j] += amount;
			trans[i][j] -= amount;
			con = true;
		}
	}

	cout << sz(ans) << endl;
	for (auto mv: ans) cout << mv.first.X+1 << ' ' << mv.first.Y+1 << ' ' << mv.second << endl;

	{ return 0; }
}

