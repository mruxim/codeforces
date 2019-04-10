// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

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

string s, t;
int n, m;

int main()
{
	cin >> s >> t;
	m = t.length();
	s = string (m, '#') + s + string (m, '#');
	n = s.length();
	int ans = 9999;
	rep (i, n - m)
	{
		int c = 0;
		rep (j, m) c += (s[i+j] == t[j]);
		cmn (ans, m - c);
	}
	cout << ans << endl;
	{ int _; cin >> _; }
}
