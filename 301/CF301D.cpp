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

const int maxn = 200000 + 100;
const int maxm = 200000 + 100;

int n, m;
int p[maxn], rp[maxn];
int l[maxm], r[maxm], id[maxm];

vector <int> v[maxn];
int f[maxn];

int ans[maxm];

void add (int x) { for (x++; x <= n; x += x & -x) f[x]++; }
int get (int x) { int r = 0; for (; x; x -= x & -x) r += f[x]; return r; }

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep(i, n) cin >> p[i], rp[p[i]] = i;
	rep(i, m) cin >> l[i] >> r[i], l[i]--, id[i] = i;

	sort(id, id+m, [](int x, int y) { return l[x] > l[y]; } );

	int pos = 0;

	rof(i, n, 0) {
		for(int k = 2*p[i]; k <= n; k += p[i])
			if(rp[k] > i) add(rp[k]);
			else v[rp[k]].pb(i);
		rep(j, sz(v[i])) add(v[i][j]);
		while(pos < m && l[id[pos]] == i) ans[id[pos]] = get(r[id[pos]]), pos++;
	}

	rep(i, m) cout << ans[i] + r[i] - l[i] << endl;

	{ int _; cin >> _; return 0; }
}
