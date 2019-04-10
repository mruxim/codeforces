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

const int maxn = 200000 + 100;

int n, m;
int s[maxn], t[maxn];
int f[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, m) cin >> t[i];

	if(m == 1) { cout << n << endl; return 0; }

	n--, m--;

	rep(i, n) s[i] = s[i] - s[i+1];
	rep(i, m) t[i] = t[i] - t[i+1];

	f[0] = 0;
	for (int i = 1, k = 0; i < m; i++) {
		while (k > 0 && t[k] != t[i]) k = f[k - 1];
		if (t[i] == t[k]) k++;
		f[i] = k;
	}
	
	int ans = 0;
	for (int i = 0, k = 0; i < n; i++) {
		while (k > 0 && t[k] != s[i]) k = f[k - 1];
		if (s[i] == t[k]) k++;
		if (k == m) {
			ans++;
			k = f[k - 1];
		}
	}

	cout << ans << endl;

	return 0;
}

