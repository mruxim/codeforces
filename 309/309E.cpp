// .... .... .... !

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

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2000 + 100;

int n;
pii s[maxn];
int p[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> s[i].X >> s[i].Y;
	rep (i, n) p[i] = i;
	sort (p, p+n, [](int a, int b) { return s[a].Y < s[b].Y; } );

	int lo = 1, hi = n;
	while (hi - lo > 1)
	{
		int md = (lo + hi) / 2;
		if (check (md))	hi = md;
		else		lo = md;
	}

	int k = 0;
	rep (i, n) fer (j, i+1, n) k = max (k, s[p[i]].X <= s[p[j]].Y && s[p[j]].X <= s[p[i]].Y ? j-i : 0);
	cerr << " %% " << k << endl;
	rep (i, n) cout << p[i] + 1 << endl;	

	{ int _; cin >> _; return 0; }
}
