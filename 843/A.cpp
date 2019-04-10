// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
int a[maxn], b[maxn];
vector<vector<int>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i], b[i] = a[i];
	sort(b, b + n);
	rep(i, n) a[i] = lower_bound(b, b + n, a[i]) - b;

	rep(i, n) if(a[i] != -1) {
		v.pb(vector<int>());
		for(int t = i, p; a[t] != -1; p = t, t = a[t], a[p] = -1)
			v.back().pb(t);
	}

	cout << sz(v) << endl;
	for(auto t: v) {
		cout << sz(t);
		for(int x: t) cout << ' ' << x + 1;
		cout << endl;
	}

	return 0;
}

