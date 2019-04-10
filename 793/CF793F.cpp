// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m, q;
pii rope[maxn];
pair<pii, int> query[maxn];
int ans[maxn];
set<int> s[4*maxn];
int nxt[maxn][20];

void add(int x, int xl, int xr, int qpos, int qval) {
	if(qpos < xl || xr <= qpos) return;
	if(xl <= qpos && qpos < xr) s[x].insert(qval);
	if(xr - xl == 1) return;

	int xm = (xl + xr) / 2;
	add(2*x+1, xl, xm, qpos, qval);
	add(2*x+2, xm, xr, qpos, qval);
}

int ask(int x, int xl, int xr, int qpos) {
	if(qpos <= xl) return n+1;
	if(xr <= qpos) {
		auto it = s[x].lower_bound(qpos);
		if(it == s[x].end()) return n+1;
		return *it;
	}

	int xm = (xl + xr) / 2;
	int res = ask(2*x+1, xl, xm, qpos);
	smin(res, ask(2*x+2, xm, xr, qpos));

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	cin >> m;
	rep(i, m) cin >> rope[i].X >> rope[i].Y;

	sort(rope, rope + m);

	cin >> q;
	rep(i, q) cin >> query[i].X.X >> query[i].X.Y, query[i].Y = i;

	sort(query, query+q);

	int rid = m;
	int qid = q;

	rep(i, n+2) rep(j, 20) nxt[i][j] = n+1;

	rof(pos, n+1, 1) {
		while(rid && rope[rid-1].X == pos) {
			rid--;
			add(0, 0, n+1, rope[rid].X, rope[rid].Y);
		}
		nxt[pos][0] = ask(0, 0, n+1, pos+1);
		fer(i, 1, 20) nxt[pos][i] = nxt[nxt[pos][i-1]][i-1];
		while(qid && query[qid-1].X.X == pos) {
			qid--;
			int t = 0;
			while(nxt[pos][t] <= query[qid].X.Y) t++;
			if(t == 0) {
				ans[query[qid].Y] = query[qid].X.X;
				continue;
			}
			t--;
			int tmp = nxt[pos][t];
			for(; t >= 0; t--) if(nxt[tmp][t] <= query[qid].X.Y) tmp = nxt[tmp][t];
			
			ans[query[qid].Y] = tmp;
		}
	}

	rep(i, q) cout << ans[i] << endl;

	return 0;
}

