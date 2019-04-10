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

const vector<string> v({"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"});

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; string s;
	cin >> n >> s;
	for(string t: v) if(sz(s) == sz(t)) {
		bool ok = 1;
		rep(i, sz(s)) if(!(s[i] == '.' || t[i] == s[i]))
			ok = false;
		if(ok) {
			cout << t << endl;
			return 0;
		}
	}

	{ return 0; }
}

