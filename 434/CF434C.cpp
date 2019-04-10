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

const int mod = 1000000000+7;
const int maxn = 200 + 10;
const int maxl = 200 + 10;
const int maxk = 500 + 10;
const int maxm = 20 + 1;

typedef vector<int> num;

int n, m, k;
num L, R;
num str[maxn];
int val[maxn];

num store[maxn+maxn]; // +maxn needed, before unique
int add[maxn];
int ct;
int ff[maxn][maxm];

int dp[maxl][maxn][maxk][2];

bool cmp(const num &v1, const num &v2) {
	return sz(v1) != sz(v2) ? sz(v1) < sz(v2) : lexicographical_compare(all(v1), all(v2));
}

void read(num &v) {
	int len; cin >> len;
	v.resize(len);
	rof(i, len, 0) cin >> v[i];
}

int solve(num &v, int pos = -1, int state = 0, int value = 0, bool is_less = false) {
	if(pos == -1) memset(dp, -1, sizeof dp), pos = 0;

	if(value > k) return 0;
	if(pos == sz(v)) return (is_less && (sz(store[state]) == 0 || store[state].back() > 0)) ? 1 : 0;

	int &res = dp[pos][state][value][is_less];
	if(res != -1) return res;

	res = (sz(store[state]) == 0 || store[state].back() > 0);

	rep(d, m) {
		int next_state = ff[state][d];
		res += solve(v, pos + 1, next_state, value + add[next_state], d < v[pos] ? 1 : d > v[pos] ? 0 : is_less);
		if(res >= mod) res -= mod;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	read(L);
	read(R);
	rep(i, n) read(str[i]), cin >> val[i];

	store[ct++] = num({0});
	rep(i, n) rep(j, sz(str[i]) + 1) store[ct++] = num(str[i].begin(), str[i].begin() + j);

	sort(store, store+ct, cmp); // w. cmp
	ct = unique(store, store+ct) - store; // wo. cmp

	rep(i, ct) rep(d, m) rof(j, ct, 1)
		if(sz(store[j]) <= sz(store[i]) + 1 && store[j].back() == d && equal(store[i].end() - (sz(store[j]) - 1), store[i].end(), store[j].begin()))
			{ ff[i][d] = j; break; }

	rep(i, ct) rep(j, n) if(sz(str[j]) <= sz(store[i]) && equal(all(str[j]), store[i].end() - sz(str[j]))) add[i] += val[j];

	// R++;
	for(int pos = 0; 1; pos++) {
		if(pos == sz(R)) R.pb(0);
		if(++R[pos] == m) R[pos] = 0;
		else break;
	}

	cout << (solve(R) - solve(L) + mod) % mod << endl;

	{ return 0; }
}

