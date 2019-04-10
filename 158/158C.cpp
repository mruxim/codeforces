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

int n;
string s;
vector <string> c;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> s;
		if (s == "pwd") { rep (i, sz(c)) cout << '/' << c[i]; cout << '/' << endl; continue; }
		cin >> s;
		if (s[0] == '/') c.resize (0), s = s.substr (1);
		s += "/";
		unsigned int p = 0;
		while ((p = s.find_first_of ("/")) != string::npos)
		{
			if (p == 2 && s[0] == '.' && s[1] == '.') c.pop_back();
			else c.push_back (s.substr (0, p));
			s = s.substr (p+1);
		}
	}
	{ int _; cin >> _; }
}
