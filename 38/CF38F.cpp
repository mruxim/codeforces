
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

const int maxn = 30 + 10;

int n, m;
string str[maxn];
vector<string> ss;
vector<int> adj[maxn*maxn*maxn];
pair<bool, pii> dp[maxn*maxn*maxn];
bool mark[maxn*maxn*maxn];
int score[maxn*maxn*maxn];

pair<bool, pii> go (int p)
{
	auto &ret = dp[p];
	if (mark[p]) return ret; mark[p] = 1;

	ret = {0, {0, 0}};
	for (int q: adj[p])
	{
		auto tmp = go (q);
		tmp.X ^= 1;
		swap (tmp.Y.X, tmp.Y.Y);
		tmp.Y.X *= -1, tmp.Y.Y *= -1;
		tmp.Y.X += score[q];
		smax (ret, tmp);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> str[i];
	rep (i, n) rep (ed, 1+sz(str[i])) rep (st, ed)
		ss.pb (str[i].substr (st, ed-st));
	ss.pb ("");
	sort (all(ss));
	ss.erase (unique (all(ss)), ss.end());
	m = sz(ss);

	rep (i, m) rep (j, m)
		if (sz(ss[j])==sz(ss[i])+1 && (ss[j].substr (0, sz(ss[i])) == ss[i] || ss[j].substr (1, sz(ss[i])) == ss[i]))
			adj[i].pb (j);

	rep (i, m)
	{
		string &t = ss[i];
		int sum = 0, mx = 0;
		rep (j, sz(t)) sum += t[j] - 'a' + 1, smax (mx, t[j] - 'a' + 1);
		int num = 0;
		rep (j, n) rep (k, sz(str[j])-sz(t)+1)
			if (equal (all(t), str[j].begin()+k))
			{
				num++;
				break;
			}
		score[i] = sum * mx + num;
	}

	auto ans = go (0);

	cout << (ans.X ? "First" : "Second") << endl;
	cout << ans.Y.X << ' ' << -ans.Y.Y << endl;

	{ return 0; }
}

