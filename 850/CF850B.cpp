// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 500000 + 100;
const int maxa = 2000000 + 100;

int n, x, y;
ll s0[maxa], s1[maxa];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> x >> y;
	rep(i, n) {
		int a; cin >> a;
		s0[a] += 1;
		s1[a] += a;
	}

	fer(i, 1, maxa)
		s0[i] += s0[i-1],
		s1[i] += s1[i-1];

	ll ans = 1LL << 60;

	int t = x / y + 1;

	fer(i, 2, maxa) {
		ll cur = 0;
		int f = min(i, t);
		for(int j = i; j < maxa; j += i) {
			cur += (s0[j - f] - s0[j - i]) * x;
			cur += ((s0[j] - s0[j - f]) * j - (s1[j] - s1[j - f])) * y;
		}
		smin(ans, cur);
	}

	cout << ans << endl;

	return 0;
}

