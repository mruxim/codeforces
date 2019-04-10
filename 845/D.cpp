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

const int maxn = 200000 + 100;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	int ans = 0, oc = 0;
	vector<int> sl;
	int sp;
	rep(i, n) {
		int t; cin >> t;
		if(t == 1) {
			cin >> sp;
			while(!sl.empty() && sl.back() < sp)
				sl.pop_back(), ans++;
		} else if(t == 2)
			ans += oc, oc = 0;
		else if(t == 3) {
			int s;
			cin >> s;
			sl.pb(s);
			while(!sl.empty() && sl.back() < sp)
				sl.pop_back(), ans++;
		} else if(t == 4)
			oc = 0;
		else if(t == 5)
			sl.clear();
		else if(t == 6)
			oc++;
	}

	cout << ans << endl;

	return 0;
}

