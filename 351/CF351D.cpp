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

const int maxn = 100000 + 100;

int n, m;
int a[maxn];
vector<int> c[maxn];
vector<pii> q[maxn];
int id[maxn], pid[maxn];
int f1[maxn], f2[maxn];

int ans[maxn];

void add(int* f, int x, int v) { for(x++; x < maxn; x += x&-x) f[x] += v; }
int get(int* f, int x) { int r = 0; for(; x; x -= x&-x) r += f[x]; return r; }

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep(i, n) cin >> a[i], c[a[i]].pb(i);
	cin >> m;
	rep(i, m) { int l, r; cin >> l >> r; q[--l].pb({r, i}); }

	rep(i, maxn) if(sz(c[i])) {
		vector<int> &C = c[i]; int &P = pid[i];
		add(f1, C[0], 1);
		P = 2;
		while(P < sz(C) && C[P]-C[P-1] == C[P-1]-C[P-2]) P++;
		if(P < sz(C)) add(f2, C[P], 1);
	}

	rep (i, n) {
		for(auto qry: q[i])
			ans[qry.Y] = get(f1, qry.X) + (get(f2, qry.X) < get(f1, qry.X) ? 0 : 1);

		add(f1, i, -1);
		vector<int> &C = c[a[i]];
		int &I = id[a[i]], &P = pid[a[i]];
		I++;
		if(I < sz(C)) add(f1, C[I], 1);
		if(C[P-2] == i && P < sz(C)) {
			add(f2, C[P], -1);
			P++;
			while(P < sz(C) && C[P]-C[P-1] == C[P-1]-C[P-2]) P++;
			if(P < sz(C)) add(f2, C[P], 1);
		}
	}

	rep(i, m) cout << ans[i] << endl;

	{ return 0; }
}

