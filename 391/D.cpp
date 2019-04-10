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
#define D first.first
#define P first.second
#define Q second

template<class T1, class T2> inline void smin(T1 &a, T2 b) { if (b < a) a = b; }
template<class T1, class T2> inline void smax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> tri;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 50000 + 100;

int n, m;
tri v[maxn], h[maxn];

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> v[i].D >> v[i].P >> v[i].Q, v[i].Q += v[i].P;
	rep (i, m) cin >> h[i].P >> h[i].D >> h[i].Q, h[i].Q += h[i].P;

	sort (v, v+n);
	sort (h, h+m);

	vector<pii> en, ex;
	rep (i, m) en.pb ({h[i].P, i});
	rep (i, m) ex.pb ({h[i].Q, i});
	sort (all(en));
	sort (all(ex));
	int pen = 0, pex = 0;

	set<pii> s;

	int ans = 0;
	rep (i, n) {
		while (pen < sz(en) && en[pen].first < v[i].D)
			s.insert ({h[en[pen].second].D, en[pen].second}), pen++;
		
		while (pex < sz(ex) && ex[pex].first <= v[i].D)
			s.erase ({h[ex[pex].second].D, ex[pex].second}), pex++;

		auto it1 = s.lower_bound ({v[i].P + ans + 1, -1});
		auto it2 = s.lower_bound ({v[i].Q - ans, -1});

		if (it1 == s.end() || it2 == s.begin()) continue;
		if (it2 != s.end()) if (it1->first > it2->first) continue;

		for (auto it = it1; it != it2; it++) {
			int j = it->second;
			int x = v[i].D, y = h[j].D;
			smax (ans, min (min (x-h[j].P, h[j].Q-x), min (y-v[i].P, v[i].Q-y)));
		}
		
	}

	cout << ans << endl;

	{ return 0; }
}

