
// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>
#include <list>
#include <forward_list>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int CTV = 800;

int n;
int a[maxn], c[maxn];
struct Block {
	forward_list<int> L;
	int len;
	int maxa;
	Block() { L.clear(); len = 0; maxa = -1; };
};
forward_list<Block> Q;

int ans[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i] >> c[i], smin (c[i], i);

	Q.push_front (Block());
	rep (i, n)
	{
		auto it = Q.begin();
		while (it->len < c[i] && it->maxa < a[i]) c[i] -= it->len, it++;
		auto &cur = *it;
		auto it2 = cur.L.before_begin();
		while (c[i]) {
			if (a[*next(it2)] < a[i]) it2++, c[i]--;
			else break;
		}
		cur.L.insert_after (it2, i);
		cur.len++;
		smax (cur.maxa, a[i]);
		if (cur.len > CTV)
		{
			auto nwit = Q.insert_after (it, Block());
			nwit->L.splice_after (nwit->L.before_begin(), it->L, next(it->L.begin(), CTV/2), it->L.end());
			int mx;
			int nwlen = 0;
			mx = 0; for (int x: nwit->L) smax (mx, a[x]), nwlen++;
			nwit->maxa = mx;
			nwit->len = nwlen;
			mx = 0; for (int x: it->L) smax (mx, a[x]);
			it->maxa = mx;
			it->len -= nwlen;
		}
	}

	int pos = n;
	for (auto cur: Q) for (int x: cur.L)
		ans[--pos] = x;
	
	rep (i, n) cout << 1+ans[i] << ' '; cout << endl;

	{ return 0; }
}

