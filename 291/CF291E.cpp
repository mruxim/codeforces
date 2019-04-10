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
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
int p[maxn];
vector <int> ch[maxn];
string s[maxn];
string t;
int f[3*maxn];
int fp[maxn];
int fs[3*maxn][26];
int ans;

void dfs (int v)
{
	int k = (v ? fp[p[v]] : 0);

	for (int i = 0; i < sz(s[v]); i++)
	{
		k = fs[k][s[v][i]-'a'];
		if (k == sz(t)) ans++, k = f[k - 1];
	}
	fp[v] = k;

	for (auto c : ch[v]) dfs (c);
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	fer (i, 1, n) cin >> p[i] >> s[i], p[i]--, ch[p[i]].pb (i);
	cin >> t;

	f[0] = 0;
	for (int i = 1, k = 0; i < sz(t); i++)
	{
		while (k > 0 && t[k] != t[i]) k = f[k - 1];
		if (t[i] == t[k]) k++;
		f[i] = k;
	}
	rep (k, sz(t))
		rep (c, 26)
			if (k > 0 && t[k] != char(c+'a')) fs[k][c] = fs[f[k-1]][c];
			else if (char(c+'a') == t[k]) fs[k][c] = k+1;

	dfs (0);
	
	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
