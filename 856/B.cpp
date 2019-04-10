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

const int maxn = 1000000 + 100;
const int base = 747;
const ll mod = 115797848077099;

int n;
string str[maxn];
vector<ll> h0[maxn], h1[maxn];
set<pii> p;
set<ll> h;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while(t--) {
		h.clear();

		cin >> n;
		rep(i, n) {
			cin >> str[i];
			h0[i].resize(sz(str[i]));
			h1[i].resize(sz(str[i]));
			h0[i][0] = str[i][0];
			h1[i][0] = 0;
			fer(j, 1, sz(str[i]))
				h0[i][j] = (h0[i][j-1] * base + str[i][j]) % mod,
				h1[i][j] = (h1[i][j-1] * base + str[i][j]) % mod;
		}
		rep(i, n) p.insert(pii(sz(str[i]), i));

		int ans = 0;
		while(!p.empty()) {
			pii q = *--p.end(); p.erase(--p.end());
			q.X--;
			ll hash = h0[q.Y][q.X];
			if(h.find(hash) == h.end()) {
				h.insert(hash);
				h.insert(h1[q.Y][q.X]);
				ans++;
			}
			if(q.X != 0) p.insert(q);
		}
		cout << ans << endl;
	}

	return 0;
}

