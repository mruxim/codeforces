// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxm = 200000 + 100;

int n, m;
bool bad[maxm];
vector<int> dv[maxm];
int dp[maxm], up[maxm];
vector<int> ans;

int powmod(int a, int b, int mod) {
	int res = 1;
	for( ; b; b >>= 1) {
		if(b & 1) res = res * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return res;
}

int phi(int x) {
	int ret = x;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
			ret = ret / i * (i - 1);
			while (x % i == 0) x /= i;
		}
	if (x > 1) ret = ret / x * (x - 1);
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) { int x; cin >> x; bad[x] = true; }

	rep(i, m) if(!bad[i]) dv[__gcd(m, i)].pb(i);

	int st = -1;
	rof(i, m, 1) if(m % i == 0) {
		up[i] = -1;
		for(int j = i + i; j < m; j += i) if(m % j == 0)
			if(up[i] == -1 || dp[j] > dp[up[i]])
				up[i] = j;
		dp[i] = sz(dv[i]) + (up[i] == -1 ? 0 : dp[up[i]]);
		if(st == -1 || dp[i] > dp[st]) st = i;
	}

	int cur = 1;
	while(st != -1) {
		for(int x: dv[st]) {
			int val = 1;
			if(x == dv[st].front()) {
				int mul = __gcd(x, m) / __gcd(cur, m);
				cur = cur * (ll)mul % m;
				val = val * (ll)mul % m;
			}
			val = val * ((x / st)  * (ll)(cur == 1 ? 1 : powmod(cur / st, phi(m / st) - 1, m / st)) % m) % m;
			cur = x;
			ans.pb(val);
		}
		st = up[st];
	}

	if(!bad[0]) ans.pb(0);

	cout << sz(ans) << endl;
	rep(i, sz(ans)) cout << (i ? " " : "") << ans[i];
	cout << endl;

	return 0;
}

