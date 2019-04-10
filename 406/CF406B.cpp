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

const int s = 999999;

int n;
bool p[s+100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		int x; cin >> x; x--;
		p[x] = 1;
	}

	int cnt = 0;
	rep(i, (s+1)/2) if(p[i] && p[s-i]) cnt++;

	cout << n << endl;
	rep(i, s+1) if(p[i] && !p[s-i])
		cout << s-i+1 << ' ';
	rep(i, s+1) if(!p[i] && !p[s-i] && cnt)
		cout << i+1 << ' ' << s-i+1 << ' ', cnt--;
	cout << endl;

	{ return 0; }
}

