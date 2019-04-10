// .... ... .... .., ....!

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

const int base = 727;
const int mod = 1000004023;
const int maxn = 200000 + 100;

int n, m;
string s;
int last[128];
vector<int> pos[128];
int prv[maxn];
ll hsh[maxn];
ll pw[maxn];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	cin >> s;

	fer(ch, 'a', 'z' + 1) last[ch] = -1;

	pw[0] = 1;
	rep(i, n) {
		pos[(int)s[i]].pb(i);
		prv[i] = i - last[(int)s[i]];
		last[(int)s[i]] = i;
		hsh[i+1] = hsh[i] * base + prv[i] % mod;
		pw[i+1] = pw[i] * base % mod;
	}

	rep(z, m) {
		int x, y, len;
		cin >> x >> y >> len;
		x--, y--;
		ll hash1 = hsh[x + len] - hsh[x] * pw[len] % mod;
		ll hash2 = hsh[y + len] - hsh[y] * pw[len] % mod;
		fer(ch, 'a', 'z' + 1) {
			auto it = lower_bound(all(pos[ch]), x);
			if(it < pos[ch].end() && *it < x + len)
				hash1 -= prv[*it] * pw[x + len - 1 - *it] % mod;
			it = lower_bound(all(pos[ch]), y);
			if(it < pos[ch].end() && *it < y + len)
				hash2 -= prv[*it] * pw[y + len - 1 - *it] % mod;
		}
		hash1 = (hash1 % mod + mod) % mod;
		hash2 = (hash2 % mod + mod) % mod;
		cerr << hash1 << ' ' << hash2 << endl;
		cout << (hash1 == hash2 ? "YES" : "NO") << endl;
	}

	return 0;
}

