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

const int inf = 1<<25;
const int maxn = 100000 + 100;

int n, s, l;
int a[maxn];
int dp[maxn];
vector<int> up, dw;
vector<int> v;
int minval[4*maxn];

int getmin(int x, int xl, int xr, int ql, int qr) {
	if(xr <= ql || qr <= xl) return inf;
	if(ql <= xl && xr <= qr) return minval[x];
	int xm = (xl + xr) / 2;
	return min(getmin(2*x+1, xl, xm, ql, qr), getmin(2*x+2, xm, xr, ql, qr));
}

void setval(int x, int xl, int xr, int qpos, int qval) {
	if(qpos < xl || xr <= qpos) return;
	smin(minval[x], qval);
	if(xr - xl == 1) return;
	int xm = (xl + xr) / 2;
	setval(2*x+1, xl, xm, qpos, qval);
	setval(2*x+2, xm, xr, qpos, qval);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> s >> l;

	rep(i, n) cin >> a[i];

	memset(minval, 50, sizeof minval);

	dp[0] = 0; v.push_back(0);
	setval(0, 0, n, 0, 0);
	rep(i, n) {
		while(!up.empty() && a[up.back()] >= a[i]) up.pop_back();
		up.push_back(i);
		while(!dw.empty() && a[dw.back()] <= a[i]) dw.pop_back();
		dw.push_back(i);

		int lo = -1, hi = i;
		while(hi - lo > 1) {
			int md = (lo + hi) / 2;
			int mx = *lower_bound(all(dw), md);
			int mn = *lower_bound(all(up), md);
			if(a[mx] - a[mn] > s)
				lo = md;
			else
				hi = md;
		}

		if(hi > i+1-l)
			dp[i+1] = inf;
		else
			dp[i+1] = getmin(0, 0, n, hi, i+2-l) + 1;

		setval(0, 0, n, i+1, dp[i+1]);
	}

	cout << (dp[n] < inf ? dp[n] : -1) << endl;

	return 0;
}

