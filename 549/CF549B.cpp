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

const int maxn = 100 + 10;

int n;
string s[maxn];
int a[maxn];
int is[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> a[i];

	int ans = 0;
	while(1) {
		int id = -1;
		rep(i, n) if(a[i] == 0) { id = i; break; }
		if(id == -1) break;
		rep(i, n) if(s[id][i] == '1') a[i]--;
		is[id] = 1;
		ans++;
	}

	cout << ans << endl;
	rep(i, n) if(is[i]) cout << i+1 << ' ';
	cout << endl;

	return 0;
}

