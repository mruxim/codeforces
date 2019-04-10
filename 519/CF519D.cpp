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

const int maxn = 100000 + 100;

int n;
string s;
int val[26];
ll p[maxn];
map<ll, int> m[26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	rep(i, 26) cin >> val[i];
	cin >> s;
	n = sz(s);
	rep(i, n) p[i+1] = p[i] + val[s[i] - 'a'];

	ll ans = 0;
	rep(i, n) {
		ans += m[s[i] - 'a'][p[i]];
		m[s[i] - 'a'][p[i+1]]++;
	}

	cout << ans << endl;

	return 0;
}

