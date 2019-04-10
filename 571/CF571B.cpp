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

const int maxn = 300000 + 100;

int n, k;
int a[maxn];
int dp[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) cin >> a[i];
	sort(a, a+n);
	a[n] = a[n-1];

	fer(i, 1, n+1) {
		dp[i] = 0;
		if(i >= n/k) smax(dp[i], dp[i-n/k] + a[i] - a[i-1]);
		if(i >= n/k+1) smax(dp[i], dp[i-n/k-1] + a[i] - a[i-1]);
		cerr << i << " : " << dp[i] << endl;
	}

	cout << a[n-1] - a[0] - dp[n] << endl;

	return 0;
}

