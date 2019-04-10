// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
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
ll s[maxn], t[maxn];
ll sum[maxn];
int q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> s[i];
	sort(s, s+n);
	n = unique(s, s+n) - s;

	rep(i, n-1) t[i+1] = s[i+1] - s[i];
	sort(t, t+n);

	sum[0] = 0;
	fer(i, 1, n)
		sum[i] = sum[i-1] + (t[i] - t[i-1]) * (n - i + 1);

	vector<ll> ans;
	cin >> q;
	rep(i, q) {
		ll l, r;
		cin >> l >> r;
		r -= l;
		int p = upper_bound(t, t+n, r) - t - 1;
		ans.pb(sum[p] + (r - t[p] + 1) * (n - p));
	}

	rep(i, q) cout << (i ? " " : "") << ans[i];
	cout << endl;

	return 0;
}

