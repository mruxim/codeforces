// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
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

string s;
int n;

int toI(const string &X){istringstream ISS(X);int Y;ISS>>Y;return Y;}

int main()
{
	cin >> s;
	n = sz (s);
	int ans = -1;
	fer (i, 1, n) fer (j, i+1, n)
	{
		string a = s.substr (0, i);
		string b = s.substr (i, j-i);
		string c = s.substr (j, n-j);
		if (a[0] == '0' && sz(a) > 1) continue;
		if (b[0] == '0' && sz(b) > 1) continue;
		if (c[0] == '0' && sz(c) > 1) continue;
		if (sz(a) > 7) continue;
		if (sz(b) > 7) continue;
		if (sz(c) > 7) continue;
		int ta = toI (a);
		int tb = toI (b);
		int tc = toI (c);
		if (ta > 1000000) continue;
		if (tb > 1000000) continue;
		if (tc > 1000000) continue;
//		cout << a << ' ' << b << ' ' << c << endl;
		cmx (ans, ta+tb+tc);
	}
	
	cout << ans << endl;
	
	{ int _; cin >> _; }
}
