#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

typedef long long ll;

const int MAXN = 200 + 9;
const int MAXM = 50000 + 99;

struct E { int x, y, g, s; } e[MAXM];

int n, m, g, s, k;
int par[MAXN];
ll ans = 1LL<<62;

int root (int x) { return par[x] < 0 ? x : par[x] = root (par[x]); }
bool merge (int x, int y) { if ((x = root (x)) == (y = root (y))) return false; par[x] += par[y], par[y] = x; return true; }

int main()
{
	cin >> n >> m >> g >> s;
	rep (i, m) cin >> e[i].x >> e[i].y >> e[i].g >> e[i].s, e[i].x--, e[i].y--;
	
	sort (e, e + m, [] (const E& a, const E& b) { return a.g < b.g; } );
	rep (z, m)
	{
		e[k++] = e[z];
		inplace_merge (e, e + k - 1, e + k, [] (const E& a, const E& b) { return a.s < b.s; } );
		int gu = 0, su = 0, t = 0;
		fill (par, par + n, -1);
		rep (i, k) if (merge (e[i].x, e[i].y))
			gu = max (gu, e[i].g), su = max (su, e[i].s), e[t++] = e[i];
		k = t;
		if (k == n-1) ans = min(ans, g*(ll)gu + s*(ll)su);
	}
	cout << (ans < (1LL<<62) ? ans : -1) << endl;
}
