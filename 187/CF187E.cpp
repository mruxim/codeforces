// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 100 * 1000 + 100;

pair <ll, vi> solve (vi x, int ls)
{
	int n = sz (x);
	vi ret;

	if (n-1 == ls)
	{
		rep (i, n) ret.pb (n-1-i);
		return make_pair (2*(x[n-1] - x[0]), ret);
	}

	priority_queue <pair <int, int> > pq;

	fer (i, 1, n-1-ls)
		pq.push (pii (-(x[i] - x[i-1]), i));

	long long cur = (x[n-1] - x[0]) + (x[n-1] - x[n-1-ls]);
	long long sum[maxn], stp[maxn];

	sum[n-1-ls] = cur;
	fer (i, n-ls, n)
	{
		pq.push (pii (-(x[i-1] - x[i-2]), i-1));
		pii t = pq.top();
		pq.pop();
		cur = cur - (x[i] - x[i-1]) + 2*(-t.first);
		sum[i] = cur;
		stp[i] = t.second;
	}
	while (!pq.empty()) pq.pop();


	int ind = min_element (sum + (n-1-ls), sum + n) - sum;
	int back[maxn], sb = 0;
	fill (back, back + n, false);
	fer (i, n-ls, ind+1)
		back[sb++] = stp[i]-1;
	sort (back, back + sb);
	int pos = 0;
	rep (i, ind)
	{
		int j = i;
		while (pos < sb && back[pos] == i) pos++, i++;
		for (int k = i; k >= j; k--)
			ret.pb (k);
	}
	rof (i, n, ind)
		ret.pb (i);
	return make_pair (sum[ind], ret);
}

long long x[maxn];

int main()
{

	int n, ls, rs, st;
	cin >> n >> ls >> st;
	rs = n - 1 - ls;
	st--;
	rep (i, n) cin >> x[i];

	if ((ls == 0 && st != 0) || (rs == 0 && st != n-1))
	{
		cout << -1;
		return 0;
	}

	pair <ll, vi> R1, R2;
	R1.first = 1LL<<50;
	R2.first = 1LL<<50;

	if (st < n-1)
	{
		vi R (n - st - 1);
		rep (i, n - st - 1) R[i] = x[st+i+1] - x[st];

		pair <ll, vi> res = solve (R, max (ls - st, 0));

		R1.first = 2*(x[st]-x[0]) + x[st+1] - x[st] + res.first;
		int pos = st, tls = ls;
		while (pos && tls > 1) R1.second.pb (pos-1), pos--, tls--;
		if (pos != 0)
			rep (i, pos)
				R1.second.pb (i);
		rep (i, sz(res.second)) R1.second.pb (res.second[i] + st + 1);
	}

	if (st > 0)
	{
		rep (i, n/2) swap (x[i], x[n-1-i]);

		rep (i, n) x[i] = -x[i];
		st = n - st - 1;
		ls = rs;

		vi R (n - st - 1);
		rep (i, n - st - 1) R[i] = x[st+i+1] - x[st];

		pair <ll, vi> res = solve (R, max (ls - st, 0));
		R2.first = 2*(x[st]-x[0]) + (x[st+1]-x[st]) + res.first;
		int pos = st, tls = ls;
		while (pos && tls > 1) R2.second.pb (pos-1), pos--, tls--;
		if (pos != 0)
			rep (i, pos)
				R2.second.pb (i);
		rep (i, sz(res.second)) R2.second.pb (res.second[i] + st + 1);

		rep (i, n-1)
			R2.second[i] = n - 1 - R2.second[i];
	}

	pair <ll, vi> ans;
	if (R1.first < R2.first)
		ans = R1;
	else
		ans = R2;

	cout << ans.first << endl;
	rep (i, n-1)
		cout << ans.second[i] + 1 << ' ';
	cout << endl;

	{ int _; cin >> _; }
}
