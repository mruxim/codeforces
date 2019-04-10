// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define W first
#define X second.first
#define Y second.second.first
#define ID second.second.second

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <double, pair <int, pair <int, int> > > tri;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 5000 + 100;
const int maxm = 100000 + 100;

int n, m, k, m0, m1;
tri e[maxm], e0[maxm], e1[maxn];
tri ans[maxm];

int par[maxn];

int root (int x) { return par[x] < 0 ? x : par[x] = root (par[x]); }
int merge (int x, int y) { x = root (x), y = root (y); if (x == y) return 0; if (par[x] > par[y]) swap (x, y); par[x] += par[y], par[y] = x; return 1; }

int mst (double add)
{
	memset (par, -1, sizeof par);
	int p0 = 0, p1 = 0, com = n-1;
	int ret = 0;
	while (com >= 1 && (p0 < m0 || p1 < m1))
	{
//		cerr << " ^ " << p0 << ' ' << e0[p0].W << ' ' << p1 << ' ' << e1[p1].W << endl;
		if (p0 < m0 && e0[p0].W < e1[p1].W + add)
			ans[com] = e0[p0++];
		else
			ans[com] = e1[p1++];
		int tmp = merge (ans[com].X, ans[com].Y);
		if (tmp && ans[com].X == 0)
			ret++;
		com -= tmp;
	}
	return ret;
}

int perm[maxm];

int main()
{
	cin >> n >> m >> k;

	rep (i, m) perm[i] = i;
	random_shuffle (perm, perm+m);

	rep (i, m)
	{
		cin >> e[i].X >> e[i].Y >> e[i].W;
		e[i].W += 1e-6*perm[i];
		e[i].X--, e[i].Y--;
		if (e[i].X > e[i].Y) swap (e[i].X, e[i].Y);
		e[i].ID = i+1;
	}

	sort (e, e + m);
	rep (i, m)
		if (e[i].X != 0) e0[m0++] = e[i];
		else e1[m1++] = e[i];

	if ((n > 1 && k == 0) || k > m)
	{
		cout << -1 << endl;
		return 0;
	}

	double lo = -112345, hi = 112345;
	if (mst (lo) < k || k < mst (hi))
	{
		cout << -1 << endl;
		return 0;
	}
	while (true)
	{
		double md = (lo + hi) / 2;
		int tmp = mst (md);
//		cerr << fixed << setprecision (10) << lo << ' ' << hi << " --> " << md << " : " << tmp << endl; cin.get();
		if (tmp == k) break;
		if (tmp < k)
			hi = md;
		else
			lo = md;
	}

	cout << n-1 << endl;
	fer (i, 1, n)
		cout << ans[i].ID << ' ';
	cout << endl;
	{ int _; cin >> _; }
}
