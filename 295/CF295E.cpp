// .... .... .... !

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

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second.first
#define Z second.second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, pair <int, ll> > tri;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int maxm = 100000 + 100;

int n, m;
int a[maxn];
int t[maxm], p[maxm], d[maxm];

int N;
int val[maxn+maxm];
int cnt[4*(maxn+maxm)];
ll sum[4*(maxn+maxm)], dis[4*(maxn+maxm)];

void add (int x, int l, int r, int id, int v) // add (0, 0, N, id, +1 || -1) --> $
{
	if (id < l || r <= id) return;
	cnt[x] += v;
	sum[x] += v * val[id];
	if (r - l == 1) return;
	int mid = (l + r) / 2;
	add (2*x+1, l, mid, id, v);
	add (2*x+2, mid, r, id, v);
	dis[x] = dis[2*x+1] + dis[2*x+2] + sum[2*x+2] * cnt[2*x+1] - sum[2*x+1] * cnt[2*x+2];
}

tri ask (int x, int l, int r, int ql, int qr) // ask (0, 0, N, L, R) --> (dis, (cnt, sum))
{
	if (qr <= l || r <= ql) return tri (0, mp (0, 0));
	if (ql <= l && r <= qr) return tri (dis[x], mp(cnt[x], sum[x]));
	int mid = (l + r) / 2;
	tri A = ask (2*x+1, l, mid, ql, qr);
	tri B = ask (2*x+2, mid, r, ql, qr);
	tri ret = tri (A.X + B.X + B.Z * A.Y - A.Z * B.Y, mp(A.Y + B.Y, A.Z + B.Z));
	return tri (A.X + B.X + B.Z * A.Y - A.Z * B.Y, mp(A.Y + B.Y, A.Z + B.Z));
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i], val[N++] = a[i];
	cin >> m;
	rep (i, m)
	{
		cin >> t[i] >> p[i] >> d[i];
		if (t[i] == 1) a[p[i]-1] += d[i], val[N++] = a[p[i]-1];
	}
	rep (i, m) if (t[i] == 1) a[p[i]-1] -= d[i];

	sort (val, val+N); N = unique (val, val+N) - val;	

	#define ind(x) (lower_bound (val, val+N, x) - val)

	rep (i, n) add (0, 0, N, ind(a[i]), 1);

	rep (i, m)
	{
		if (t[i] == 1)
		{
			add (0, 0, N, ind(a[p[i]-1]), -1);
			a[p[i]-1] += d[i];
			add (0, 0, N, ind(a[p[i]-1]), 1);
		}
		else
			cout << ask (0, 0, N, ind(p[i]), ind(d[i]+1)).X << endl;
	}

	{ int _; cin >> _; return 0; }
}
