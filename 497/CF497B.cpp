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

const int maxn = 100000 + 100;

int n;
int a[maxn], b[maxn];
vector<pii> ans;

int bs(int f[maxn], int pos, int t) {
	int lo = pos, hi = n+1;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		if(f[md]-f[pos] >= t)
			hi = md;
		else
			lo = md;
	}
	return hi;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	fer(i, 1, n+1) {
		int x; cin >> x;
		a[i] = a[i-1];
		b[i] = b[i-1];
		if(x == 1)
			a[i]++;
		else
			b[i]++;
	}

	fer(t, 1, n+1) {
		int pos = 0;
		int s = 0, sa = 0, sb = 0;
		int last = -1;
		while(pos < n) {
			int apos = bs(a, pos, t);
			int bpos = bs(b, pos, t);
			int minpos = min(apos, bpos);
			int cnt = 0;
			if(a[minpos] - a[pos] == t) cnt++, sa++, last = 0;
			if(b[minpos] - b[pos] == t) cnt++, sb++, last = 1;
			if(cnt != 1) { s = -1; break; }
			s++;
			pos = minpos;
		}
		if(s != -1 && sa != sb && (last ^ (sb < sa)))
			ans.pb({max(sa, sb), t});
	}

	sort(all(ans));
	
	cout << sz(ans) << endl;
	rep(i, sz(ans)) cout << ans[i].X << ' ' << ans[i].Y << endl;

	return 0;
}

