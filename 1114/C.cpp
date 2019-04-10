// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
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

ll n, b;

ll f(ll a, ll p) {
	ll r = 0;
	while(a) r += a / p, a /= p;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> b;
	ll ans = n;

	for(int i = 2; i * (ll)i <= b; i++) if(b % i == 0) {
		int c = 0;
		while(b % i == 0) b /= i, c++;
		smin(ans, f(n, i) / c);
	}
	if(b > 1)
		smin(ans, f(n, b));

	cout << ans << endl;

	return 0;
}

