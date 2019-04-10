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

const int maxn = 100000 + 100;
const int maxm = 100000 + 100;

int n, m;
int a[maxn];
vector <int> pos[maxn];
int l[maxm], r[maxm];
int id[maxm], ans[maxm];
int cnt[maxn];
int fen[maxn];

void add (int x, int val) // 0..x
{
	for (x++; x; x -= x&-x) fen[x] += val;
}

int get (int x)
{
	int ret = 0;
	for (x++; x <= n; x += x&-x) ret += fen[x];
	return ret;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;

	rep (i, n) pos[i+1].pb (-1);

	rep (i, n)
	{
		cin >> a[i];
		if (a[i] <= n) pos[a[i]].pb (i);
	}

	rep (i, m) cin >> l[i] >> r[i], l[i]--, r[i]--;

	rep (i, m) id[i] = i;

	sort (id, id+m, [](const int &x, const int &y) { return r[x] < r[y]; } );

	int k = 0;

	rep (i, n)
	{
		if (a[i] > n) continue;

		cnt[a[i]]++;

		int x = max (0, cnt[a[i]]-a[i]-1), y = max (0, cnt[a[i]]-a[i]), z = max (0, cnt[a[i]]-a[i]+1);

		add (pos[a[i]][y], -1);
		add (pos[a[i]][x], 1);

		add (pos[a[i]][z], 1);
		add (pos[a[i]][y], -1);

		for ( ; k < m && r[id[k]] <= i; k++)
			ans[id[k]] = get (l[id[k]]);
	}

	rep (i, m) cout << ans[i] << endl;

	{ int _; cin >> _; }
	return 0;
}
