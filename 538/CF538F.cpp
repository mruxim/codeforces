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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2*100000 + 100;

int n;
int a[maxn];
int ans[maxn];
int v[20][maxn];

void make(int dep, int xl, int xr) {
	if(xr - xl == 1) {
		v[dep][xl] = a[xl];
		return;
	}

	int xm = (xl + xr) / 2;
	make(dep+1, xl, xm);
	make(dep+1, xm, xr);

	merge(v[dep+1] + xl, v[dep+1] + xm, v[dep+1] + xm, v[dep+1] + xr, v[dep] + xl);
}

int cnt(int dep, int xl, int xr, int ql, int qr, int qval) {
	if(qr <= xl || xr <= ql) return 0;
	if(ql <= xl && xr <= qr)
		return lower_bound(v[dep] + xl, v[dep] + xr, qval) - (v[dep] + xl);

	int xm = (xl + xr) / 2;
	return cnt(dep+1, xl, xm, ql, qr, qval) + cnt(dep+1, xm, xr, ql, qr, qval);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	make(0, 0, n);

	rep(i, n-1) ans[1] += (a[i] > a[i+1] ? 1 : 0);

	fer(k, 2, n)
		for(int i = 0; k*i+1 < n; i++)
			ans[k] += cnt(0, 0, n, k*i+1, k*i+k+1, a[i]);

	rep(i, n-1) cout << ans[i+1] << ' '; cout << endl;

	return 0;
}

