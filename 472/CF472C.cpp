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
string a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i] >> b[i];

	bool yes = true;
	string prev = "";

	rep(i, n) {
		int x; cin >> x; x--;
		if(prev < a[x] && prev < b[x]) prev = min(a[x], b[x]);
		else if(prev < a[x]) prev = a[x];
		else if(prev < b[x]) prev = b[x];
		else yes = false;
	}

	cout << (yes ? "YES" : "NO") << endl;

	return 0;
}

