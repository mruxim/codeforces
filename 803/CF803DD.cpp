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

int k;
string line;

int calc(int w) {
	int res = 1;
	int cut = 0, pos = 0;
	for(char c: line) {
		if(pos == w) {
			res++;
			pos -= cut;
			cut = 0;
			if(pos >= w) return 1e9;
		}
		if(c == '-') cut = pos+1;
		else if(c == ' ') cut = pos+1;
		pos++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> k;
	cin >> ws;
	getline(cin, line);

	int lo = 0, hi = 2000000 + 10;

	while(hi - lo > 1) {
		int md = (lo + hi) / 2;

		if(calc(md) <= k) hi = md;
		else lo = md;
	}

	cout << hi << endl;

	return 0;
}
