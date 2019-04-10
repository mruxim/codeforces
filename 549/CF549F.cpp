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
const int maxk = 1000000 + 100;

int n, k;
int a[maxn];
int sum[maxn];
vector<int> v[maxk];

int L[maxn], R[maxn];
int s[maxn], t;

inline int cnt(int l, int r, int m) {
	return lower_bound(all(v[m]), r) - lower_bound(all(v[m]), l);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;

	v[0].pb(0);
	rep(i, n) {
		cin >> a[i];
		sum[i+1] = (sum[i] + a[i]) % k;
		v[sum[i+1]].pb(i+1);
	}

	t = 0;
	rep(i, n) {
		while(t && a[s[t-1]] < a[i]) t--;
		L[i] = (t ? s[t-1] + 1 : 0);
		s[t++] = i;
	}

	t = 0;
	rof(i, n, 0) {
		while(t && a[s[t-1]] <= a[i]) t--;
		R[i] = (t ? s[t-1] : n);
		s[t++] = i;
	}

	ll ans = 0;

	rep(i, n) {
		if(i - L[i] < R[i] - i) {
			for(int j = L[i]; j <= i; j++)
				ans += cnt(i+1, R[i]+1, (a[i] % k + sum[j] + k) % k);
		} else {
			for(int j = i+1; j <= R[i]; j++)
				ans += cnt(L[i], i+1, (sum[j] - a[i] % k + k) % k);
		}
	}

	cout << ans - n << endl;

	return 0;
}
