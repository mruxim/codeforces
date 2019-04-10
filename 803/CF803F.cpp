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

const int mod = 1000000000 + 7;
const int maxn = 100000 + 100;

int n;
int p2[maxn];
int cnt[maxn], sp[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	p2[0] = 1;
	fer(i, 1, maxn) p2[i] = p2[i-1] * 2 % mod;

	cin >> n;
	rep(i, n) {
		int p; // cin >> p;
		p = i+1;
		for(int i = 1; i * i <= p; i++) if(p % i == 0)
			cnt[i]++, i*i < p ? cnt[p/i]++ : 0;
	}

	for(int i = 2; i < maxn; i++) {
		for(int j = i; j < maxn; j += i)
			if(sp[j] == 0) sp[j] = i;
	}

	ll ans = 0;
	for(int i = 1; i < maxn; i++) {
		int k = 0, x = i;
		while(x > 1) {
			int t = sp[x];
			x /= t;
			if(x % t == 0) break;
			k++;
		}
		if(x != 1) continue;
		k = (k % 2) * 2 - 1;
		ans = (ans - (p2[cnt[i]] - 1) * k + mod) % mod;
	}

	cout << ans << endl;

	return 0;
}

