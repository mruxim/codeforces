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

int n;
pii p[maxn];
int fen[2*maxn];

void add(register int x) { for(; x <= 2*n; x += x & -x) fen[x]++; }
int get(register int x) { int ret = 0; for(; x; x -= x & -x) ret += fen[x]; return ret; }

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	rep(i, n) { cin >> p[i].X >> p[i].Y; if(p[i].X > p[i].Y) swap (p[i].X, p[i].Y); }

	sort(p, p+n, greater<pii>());

	ll ans = n * (ll)(n-1) * (n-2) / 6;
	ll bad = 0;

	rep(i, n) {
		int left = get (p[i].Y);
		int cut = p[i].Y - p[i].X - 1 - left * 2;
		int right = n - 1 - left - cut;
		add (p[i].Y);
		ans -= left * (ll)right;
		bad += (left + right) * (ll)cut;
	}

	cout << ans - bad/2 << endl;

	{ int _; cin >> _; return 0; }
}
