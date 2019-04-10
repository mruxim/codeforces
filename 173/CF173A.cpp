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

ll n;
string s, t;
int m, k;
int a, b, x, y;

int main()
{
	cin >> n;
	cin >> s >> t;
	m = sz (s);
	k = sz (t);
	rep (i, m*k)
			 if (s[i%m] == 'R' && t[i%k] == 'S') b++;
		else if (s[i%m] == 'R' && t[i%k] == 'P') a++;
		else if (s[i%m] == 'S' && t[i%k] == 'P') b++;
		else if (s[i%m] == 'S' && t[i%k] == 'R') a++;
		else if (s[i%m] == 'P' && t[i%k] == 'R') b++;
		else if (s[i%m] == 'P' && t[i%k] == 'S') a++;
	rep (i, n % (m*k))
			 if (s[i%m] == 'R' && t[i%k] == 'S') y++;
		else if (s[i%m] == 'R' && t[i%k] == 'P') x++;
		else if (s[i%m] == 'S' && t[i%k] == 'P') y++;
		else if (s[i%m] == 'S' && t[i%k] == 'R') x++;
		else if (s[i%m] == 'P' && t[i%k] == 'R') y++;
		else if (s[i%m] == 'P' && t[i%k] == 'S') x++;
	cout << a * (n / (m*k)) + x << ' ' << b * (n / (m*k)) + y << endl;
	{ int _; cin >> _; }
}
