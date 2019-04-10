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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const string t = "CODEFORCES";
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s;
	if(sz(s) < sz(t)) { cout << "NO" << endl; return 0; }
	int n = sz(s);

	int cnt = 0;
	rep(i, n) if(s[i] == t[i]) cnt++; else break;
	rep(i, n) if(s[sz(s)-i-1] == t[sz(t)-i-1]) cnt++; else break;

	cout << (cnt >= sz(t) ? "YES" : "NO") << endl;

	return 0;
}

