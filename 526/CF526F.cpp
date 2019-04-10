// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

#define I first.first
#define Y first.second
#define L second.first
#define D second.second

////////////////////////////////////////////////////////////////////////////////

const int maxn = 6*100000 + 100;

int n;
int p[maxn];
pair<pii, pii> st[maxn];
vector<int> child[2*maxn];
int sub[2*maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		int x, y; cin >> x >> y; x--, y--;
		p[x] = y;
	}
	n++;

	int nnode = n;
	int top = 0;
	rep(i, n) {
		st[top++] = {{i, p[i]}, {1, 0}};
		sub[i] = 1;
		for(; top >= 2 && (st[top-2].Y + st[top-2].L == st[top-1].Y || st[top-2].Y - st[top-1].L == st[top-1].Y); top--) {
			int nD = (st[top-1].Y - st[top-2].Y > 0 ? 1 : -1);
			if(st[top-2].D != nD) child[nnode].assign(1, st[top-2].I), sub[nnode] = sub[st[top-2].I], st[top-2].I = nnode++;
			child[st[top-2].I].pb(st[top-1].I);
			sub[st[top-2].I] += sub[st[top-1].I];
			st[top-2].L += st[top-1].L;
			st[top-2].D = nD;
			smin(st[top-2].Y, st[top-1].Y);
		}
	}

	cerr << " ## " << top << endl;

	ll ans = 0;
	fer(i, 0, nnode)
		ans += max(0ll, sz(child[i]) * (ll)(1+sz(child[i])) / 2 - sz(child[i]));

	if(top == 2) ans--;
	cout << ans+n << endl;

	return 0;
}

