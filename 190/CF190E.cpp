// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 5 * 100 * 1000 + 1000;
const int maxm = 1000 * 1000 + 1000;

int n, m;
vector <int> a[maxn];
int _prev[maxn], _next[maxn], *prev = _prev + 5, *next = _next + 5;
int k;
vector <int> ans[maxn];

void dfs (int x)
{
	next[prev[x]] = next[x];
	prev[next[x]] = prev[x];
	prev[x] = -9;
	ans[k].push_back (x+1);
	vector <int> &adj = a[x];

	for (int y = next[-1]; y < n; y = next[y])
		if (!binary_search (adj.begin(), adj.end(), y))
			dfs (y);
	
	while (prev[next[x]] == -9) next[x] = next[next[x]];
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x].pb (y), a[y].pb (x);
	}
	
	rep (i, n) sort (all (a[i]));
	rep (i, n+1) prev[i] = i-1, next[i-1] = i;

	rep (i, n) if (prev[i] != -9)
	{
		dfs (i);
		k++;
	}

	cout << k << endl;
	rep (i, k)
	{
		cout << sz(ans[i]);
		rep (j, sz(ans[i]))
			cout << ' ' << ans[i][j];
		cout << endl;
	}

	{ int _; cin >> _; }
}

/* // with mark array, more readable

// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 5 * 100 * 1000 + 1000;
const int maxm = 1000 * 1000 + 1000;

int n, m;
vector <int> a[maxn];
int _prev[maxn], _next[maxn], *prev = _prev + 5, *next = _next + 5;
int k;
vector <int> ans[maxn];

void dfs (int x)
{
	next[prev[x]] = next[x];
	prev[next[x]] = prev[x];
	ans[k].push_back (x+1);
	vector <int> &adj = a[x];

	for (int y = next[-1]; y < n; y = next[y])
		if (!binary_search (adj.begin(), adj.end(), y))
			dfs (y);
	
	while (mark[next[x]]) next[x] = next[next[x]];
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x].pb (y), a[y].pb (x);
	}
	
	rep (i, n) sort (all (a[i]));
	rep (i, n+1) prev[i] = i-1, next[i-1] = i;

	rep (i, n) if (!mark[i])
	{
		dfs (i);
		k++;
	}

	cout << k << endl;
	rep (i, k)
	{
		cout << sz(ans[i]);
		rep (j, sz(ans[i]))
			cout << ' ' << ans[i][j];
		cout << endl;
	}

	{ int _; cin >> _; }
}

*/
