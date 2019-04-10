
// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n, m, k;
vector<pii> ans;

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> k;

	rep (i, n) rep (j, m) ans.pb ({i+j, j});
	sort (all(ans));
	ans.erase (ans.begin() + k, ans.end());

	int moves = 0;
	for (pii &p: ans) moves += p.X + 1, p.X -= p.Y;
	cout << moves << endl;
	rof (i, sz(ans), 0) {
		pii p = ans[i];
		pii cur = {0, 0};
		while (cur.Y <= p.Y)
			cout << '(' << cur.X+1 << ',' << cur.Y+1 << ") ", cur.Y++;
		cur.Y--, cur.X++;
		while (cur.X <= p.X)
			cout << '(' << cur.X+1 << ',' << cur.Y+1 << ") ", cur.X++;
		cout << endl;
	}

	{ return 0; }
}

