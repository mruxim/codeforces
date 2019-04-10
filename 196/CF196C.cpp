// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

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
#define X first.first
#define Y first.second
#define ID second

typedef long long ll;
typedef pair <pair <int, int>, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 1500;

int n;
vi adj[maxn];
vi ch[maxn];
bool mark[maxn];
int sub[maxn];
int ans[maxn];

void dfs (int x)
{
	mark[x] = 1;
	sub[x] = 1;
	fch (it, adj[x])
	{
		int y = *it;
		if (!mark[y])
		{
			ch[x].pb(y);
			dfs (y);
			sub[x] += sub[y];
		}
	}
}

pii pv;

bool cmp (const pii &A, const pii& B)
{
	return (A.X-pv.X)*(ll)(B.Y-pv.Y) > (A.Y-pv.Y)*(ll)(B.X-pv.X);
//	return A.Y!=B.Y ? A.Y<B.Y : A.X<B.X;
}

void go (int v, vector <pii> p)
{
	sort (all (p));
	ans[p[0].ID] = v+1;
	pv = p[0];
	reverse (all (p));
	p.resize (p.size()-1);
	sort (all (p), cmp);
	vector <pii> t;
	int pos = 0;
	rep (i, sz(ch[v]))
	{
		int u = ch[v][i];
		rep (j, sub[u])
			t.pb (p[pos++]);
		go (u, t);
		t.clear();
	}
}

int main()
{
	cin >> n;
	rep (i, n-1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs (0);

	vector <pii> p(n);
	rep (i, n) cin >> p[i].X >> p[i].Y, p[i].ID = i;

	go (0, p);

	rep (i, n)
		cout << ans[i] << ' ';
	cout << endl;
}
