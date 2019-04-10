// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
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

string s;
int cnt[2][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s;
	rep(i, sz(s)) cnt[s[i]-'a'][i%2]++;
	cout << cnt[0][0] * (ll)cnt[0][1] + cnt[1][0] * (ll)cnt[1][1] << ' ';
	cout << cnt[1][0] * (ll)(cnt[1][0]+1) / 2 + cnt[0][0] * (ll)(cnt[0][0]+1) / 2 +
			cnt[1][1] * (ll)(cnt[1][1]+1) / 2 + cnt[0][1] * (ll)(cnt[0][1]+1) / 2 << endl;

	{ return 0; }
}

