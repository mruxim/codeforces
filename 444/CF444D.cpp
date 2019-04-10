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

const int maxn = 50000 + 100;
const int maxl = 4;
const int cnts = 26 + 26*26 + 26*26*26 + 26*26*26*26;
const int thr = 200;
const int maxg = maxn / thr * maxl;
const int inf = 1<<29;

int n;

string ss;
int s[maxn];
vector<int> p[cnts];
vector<int> big;

int bid[cnts];
int last[cnts];
int ans[maxg][maxg];

int getid(int* st, int* ed) {
	int len = ed - st;
	int res = 0;
	if(len > 1) res += 26;
	if(len > 2) res += 26*26;
	if(len > 3) res += 26*26*26;
	int mul = 1;
	while(st < ed) res += mul * (*st), st++, mul *= 26;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> ss;
	n = sz(ss);
	rep(i, n) s[i] = ss[i] - 'a';

	rep(i, n) fer(len, 1, 5) if(i + len <= n)
		p[getid(s+i, s+i+len)].pb(i);

	memset(bid, -1, sizeof bid);

	rep(i, cnts) if(sz(p[i]) >= thr) {
		bid[i] = sz(big);
		big.pb(i);
	}

	memset(ans, 50, sizeof ans);
	memset(last, -50, sizeof last);
	rep(i, n) fer(len, 1, 5) if(i + len <= n) {
		int id = getid(s+i, s+i+len);
		if(bid[id] == -1) continue;
		for(int x: big) if(x != id && last[x] >= 0)
			smin(ans[bid[x]][bid[id]], i + len - last[x]);
		last[id] = i;
	}

	int qc;
	cin >> qc;
	while(qc--) {
		string ss1, ss2; cin >> ss1 >> ss2;
		int n1 = sz(ss1), n2 = sz(ss2);
		int s1[5], s2[5];
		rep(i, n1) s1[i] = ss1[i] - 'a';
		rep(i, n2) s2[i] = ss2[i] - 'a';

		int id1 = getid(s1, s1+n1);
		int id2 = getid(s2, s2+n2);

		if(sz(p[id1]) > sz(p[id2])) swap(id1, id2), swap(n1, n2);

		if(sz(p[id1]) >= thr) {
			if(id1 == id2) cout << n1 << endl;
			else cout << max(min(ans[bid[id1]][bid[id2]], ans[bid[id2]][bid[id1]]), max(n1, n2)) << endl;
		} else {
			int res = inf;
			vector<int> &v = p[id2];
			for(int pos1: p[id1]) {
				int tmp = lower_bound(all(v), pos1) - v.begin();
				if(tmp < sz(v)) smin(res, v[tmp] + n2 - pos1);
				if(tmp) tmp--, smin(res, pos1 + n1 - v[tmp]);
			}
			if(res == inf) cout << -1 << endl;
			else cout << max(res, max(n1, n2)) << endl;
		}
	}

	{ return 0; }
}

