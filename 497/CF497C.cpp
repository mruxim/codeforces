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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
pair<pii, int> part[maxn];
pair<pii, int> actor[maxn];
int limit[maxn];
int store[4*maxn], ct;

set<pii> fen[4*maxn];

int ans[maxn];

void add(int pos, pii p) {
	for( ; pos < 4*maxn; pos += pos & -pos)
		fen[pos].insert(p);
}

pii get(int pos) {
	pii res = {-1, -1};
	for( ; pos; pos -= pos & -pos)
		if(!fen[pos].empty())
			smax(res, *--fen[pos].end());
	if(res == pii(-1, -1)) return res;
	limit[res.Y]--;
	if(limit[res.Y] == 0)
		for(pos = res.X; pos < 4*maxn; pos += pos & -pos)
			fen[pos].erase(res);
	return res;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> part[i].X.Y >> part[i].X.X, part[i].Y = i;
	cin >> m;
	rep(i, m) cin >> actor[i].X.Y >> actor[i].X.X >> limit[i], actor[i].Y = i;

	rep(i, n) store[ct++] = part[i].X.X, store[ct++] = part[i].X.Y;
	rep(i, m) store[ct++] = actor[i].X.X, store[ct++] = actor[i].X.Y;

	sort(store, store+ct);
	ct = unique(store, store+ct) - store;
	rep(i, n)
		part[i].X.X = lower_bound(store, store+ct, part[i].X.X) - store + 1,
		part[i].X.Y = lower_bound(store, store+ct, part[i].X.Y) - store + 1;
	
	rep(i, m)
		actor[i].X.X = lower_bound(store, store+ct, actor[i].X.X) - store + 1,
		actor[i].X.Y = lower_bound(store, store+ct, actor[i].X.Y) - store + 1;

	sort(part, part+n); reverse(part, part+n);
	sort(actor, actor+m); reverse(actor, actor+m);

	int pos = 0;
	rep(i, n) {
		while(pos < m && actor[pos].X.X >= part[i].X.X)
			add(actor[pos].X.Y, {actor[pos].X.Y, actor[pos].Y}),
			pos++;

		pii performer = get(part[i].X.Y);
		if(performer == pii(-1, -1)) { cout << "NO" << endl; return 0; }

		ans[part[i].Y] = performer.Y;
	}

	cout << "YES" << endl;
	rep(i, n) cout << ans[i]+1 << ' ';
	cout << endl;

	return 0;
}

