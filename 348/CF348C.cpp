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

const int DTS = 500;
const int maxn = 100000 + 100;

int n, m, q;
ll arr[maxn];
ll start_sum[maxn];
vector<int> s[maxn];
vector<int>badj[maxn];
int bigs, bid[maxn];
int mul[maxn/DTS][maxn];
ll big_change[maxn/DTS], s2b[maxn/DTS];

int main()
{
	ios_base::sync_with_stdio (false);

	memset (bid, -1, sizeof bid);

	cin >> n >> m >> q;
	rep (i, n) cin >> arr[i];
	rep (i, m)
	{
		int t; cin >> t;
		s[i].resize (t);
		rep (j, sz(s[i])) cin >> s[i][j], s[i][j]--;
		for (int x: s[i]) start_sum[i] += arr[x];
		if (sz(s[i]) > DTS)
		{
			bid[i] = bigs++;
			for (int x: s[i]) badj[x].pb (bid[i]);
		}
	}
	fill (arr, arr+n, 0);
	rep (i, m) for (int x: s[i]) for (int big: badj[x]) mul[big][i]++;

	rep (z, q)
	{
		char tp; int k;
		cin >> tp >> k; k--;
		if (tp == '?')
		{
			ll ans = start_sum[k];
			rep (i, bigs) ans += big_change[i] * mul[i][k];
			if (bid[k] != -1) ans += s2b[bid[k]];
			else for (int x: s[k]) ans += arr[x];
			cout << ans << endl;
		}
		else
		{
			int val; cin >> val;
			if (bid[k] != -1) big_change[bid[k]] += val;
			else
			{
				for (int x: s[k]) arr[x] += val;
				rep (i, bigs) s2b[i] += val * mul[i][k];
			}
		}
	}

	{ return 0; }
}

