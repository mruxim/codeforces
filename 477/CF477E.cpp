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
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 400000 + 100;
const int maxlg = 19 + 1;

int n, q;
int a[maxn];
int t[maxn];
int mn[maxlg][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	t[0] = -1;
	fer(i, 1, maxn) t[i] = t[i>>1] + 1;

	rep(l, maxlg) rep(i, maxn)
		if(l == 0) mn[l][i] = a[i];
		else {
			mn[l][i] = mn[l-1][i];
			if(i + (1 << (l-1)) < n)
				smin(mn[l][i], mn[l-1][i + (1 << (l-1))]);
		}

	for (cin >> q; q--; ) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, r2--;

		int dr = abs(r1 - r2) + 1;
		int p = min(mn[t[dr]][min(r1, r2)], mn[t[dr]][max(r1, r2) - (1 << t[dr]) + 1]);
		smin(p, c1);
		int add = min(abs(p - c2), 1 + min(c2, a[r2] - c2));

		cout << abs(r1 - r2) + add << endl;
	}

	return 0;
}

