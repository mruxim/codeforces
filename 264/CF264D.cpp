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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000000 + 100;

int n, m;
string s, t;
int l[maxn], r[maxn];


int main()
{
	ios_base::sync_with_stdio (false);

	cin >> s >> t;
	n = sz(s), m = sz(t);

	int p;

	p = 0;
	rep (i, n)
	{
		l[i] = p;
		if (p < m && t[p] == s[i]) p++;
	}

	p = 0;
	rep (i, m)
	{
		r[p] = i;
		if (p < n && s[p] == t[i]) p++;
	}
	while (p < n) r[p++] = m-1;

	ll ans = 0;
	rep (i, n) ans += r[i] - l[i] + 1;

	vector<int> pos[111][111];
	rep (i, m-1) pos[t[i]][t[i+1]].pb (i);

	rep (i, n-1)
	{
		if (s[i] == s[i+1]) continue;
		vector<int> &v = pos[s[i+1]][s[i]];
		int tmp = lower_bound (all(v), r[i+1]) - lower_bound (all(v), l[i+1]);
		ans -= tmp;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
