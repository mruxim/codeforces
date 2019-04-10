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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s, t;
	cin >> s >> t;

	bool aut = true;

	int pos = 0;
	rep(i, sz(t)) {
		while(pos < sz(s) && s[pos] != t[i]) pos++;
		if(pos >= sz(s)) aut = false;
		pos++;
	}

	if(aut) { cout << "automaton" << endl; return 0; }

	sort(all(s));
	sort(all(t));
	if(s == t) { cout << "array" << endl; return 0; }

	bool both = true;

	pos = 0;
	rep(i, sz(t)) {
		while(pos < sz(s) && s[pos] != t[i]) pos++;
		if(pos >= sz(s)) both = false;
		pos++;
	}

	if(both) { cout << "both" << endl; return 0; }
	
	cout << "need tree" << endl;

	{ return 0; }
}

