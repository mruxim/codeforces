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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int maxm = 2000 + 100;

int n, m;
int p[maxn], s[maxm];
int lft[maxn], rgt[maxn];
int lx[maxn], rx[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> p[i];
	rep(i, m) cin >> s[i];
	
	sort(p, p+n);
	sort(s, s+m);

	int t = 0;
	rep(i, n) {
		while(t < m && s[t] < p[i]) t++;
		int cp = p[i] + 1;
		lft[i] = (i ? lx[i-1] : 0);
		lx[i] = max(lft[i], i ? lx[i-1] : 0);
		rof(j, t, 0) {
			if(i - cp + s[j] < -1) break;
			int v = (i - cp + s[j] == -1 ? 0 : lft[i - cp + s[j]]) + t - j;
			if(lft[i] < v) lft[i] = v;
		}
		if(s[t] == p[i]) lft[i]++;
	}

	reverse(p, p+n); rep(i, n) p[i] = -p[i];
	reverse(s, s+m); rep(i, m) s[i] = -s[i];
	t = 0;
	rep(i, n) {
		while(t < m && s[t] < p[i]) t++;
		int cp = p[i] + 1;
		rgt[i] = (i ? rx[i-1] : 0);
		rx[i] = max(rgt[i], i ? rx[i-1] : 0);
		rof(j, t, 0) {
			if(i - cp + s[j] < -1) break;
			int v = (i - cp + s[j] == -1 ? 0 : rgt[i - cp + s[j]]) + t - j;
			if(rgt[i] < v) rgt[i] = v;
		}
	}

	int ans = 0;
	rep(i, n) smax(ans, lft[i] + rgt[n-i-1]);

	cout << ans << endl;

	{ return 0; }
}

