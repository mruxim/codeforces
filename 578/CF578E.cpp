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

const int maxn = 100000 + 100;

int n;
string str;
vector<int> p[2];
set<int> s[2];

vector<int> solve(int x) {
	if(sz(p[x]) < sz(p[1-x])) return vector<int>();

	rep(i, 2) {
		s[i].clear();
		for(int pos: p[i])
			s[i].insert(pos);
	}

	int cur = -1;
	vector<int> res;

	rep(i, n) {
		auto it = s[x].lower_bound(cur);
		if(it != s[x].end()) {
			cur = *it;
			res.push_back(cur);
			s[x].erase(cur);
		} else {
			cur = -1;
			it = s[x].lower_bound(cur);
			cur = *it;
			res.push_back(cur);
			s[x].erase(cur);
		}
		x = 1 - x;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> str; n = sz(str);
	rep(i, n) p[str[i] == 'L'].pb(i);

	vector<int> a = solve(0);
	vector<int> b = solve(1);

	vector<int> ans;
	if(sz(a) == 0) ans = b;
	else if(sz(b) == 0) ans = a;
	else {
		int at = 0, bt = 0;
		rep(i, n-1) at += (a[i+1] < a[i]);
		rep(i, n-1) bt += (b[i+1] < b[i]);
		ans = (at < bt ? a : b);
	}

	int t = 0;
	rep(i, n-1) t += (ans[i+1] < ans[i]);
	cout << t << endl;
	rep(i, n) cout << (i ? " " : "") << ans[i] + 1; cout << endl;

	return 0;
}

