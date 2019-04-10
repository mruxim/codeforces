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

const int maxn = 100 + 10;
const int ctv = 32;

int n, t;
int a[maxn];
int cnt[999];
int ldp[3*maxn][maxn], rdp[3*maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> t;
	rep(i, n) cin >> a[i], cnt[a[i]]++;

	rep(i, 2*n+ctv) rep(j, n) {
		rep(k, j) if(a[k] <= a[j]) smax(ldp[i][j], ldp[i][k]);
		if(i) fer(k, j, n) if(a[k] <= a[j]) smax(ldp[i][j], ldp[i-1][k]);
		ldp[i][j]++;
	}

	rep(i, 2*n+ctv) rof(j, n, 0) {
		rof(k, n, j+1) if(a[j] <= a[k]) smax(rdp[i][j], rdp[i][k]);
		if(i) rof(k, j+1, 0) if(a[j] <= a[k]) smax(rdp[i][j], rdp[i-1][k]);
		rdp[i][j]++;
	}

	if(t <= 2*n+ctv) cout << *max_element(ldp[t-1], ldp[t-1] + n) << endl;
	else {
		int ans = 0;
		rep(i, n) rep(j, n) if(a[i] == a[j])
			smax(ans, ldp[n+ctv/2-1][i] + cnt[a[i]] * (t - 2*n - ctv) + rdp[n+ctv/2-1][j]);
		cout << ans << endl;
	}

	return 0;
}

