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

int n;
set<pii> s[3];
int ans[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		int x; cin >> x;
		s[x % 3].insert(pii(x, i));
	}
	
	int prv = -1;
	rep(i, n) {
		int t = i;
		if(i) smin(t, prv + 1);
		auto it = s[i%3].lower_bound(pii(t+1, -1));
		if(it == s[i%3].begin()) prv = ans[i] = -n;
		else {
			it--;
			ans[i] = it -> second + 1;
			prv = it -> first;
			s[i%3].erase(it);
		}
	}

	if(ans[n-1] >= 0) {
		cout << "Possible" << endl;
		rep(i, n) cout << ans[i] << ' ';
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}

	return 0;
}

