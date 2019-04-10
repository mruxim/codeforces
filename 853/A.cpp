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

const int maxn = 300000 + 100;

int n, k;
int c[maxn];
set<pii> s;
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) cin >> c[i];

	ll ans = 0;

	rep(i, k) s.insert(pii(c[i], i));

	rep(i, n) {
		if(i + k < n) s.insert(pii(c[i + k], i + k));
		pii p = *--s.end();
		s.erase(p);
		ans += (i + k - p.second) * (ll)p.first;
		a[p.second] = i;;
	}

	cout << ans << endl;
	rep(i, n) cout << (i ? " " : "") << a[i] + k + 1;
	cout << endl;

	return 0;
}

