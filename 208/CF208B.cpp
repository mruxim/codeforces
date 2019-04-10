// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
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

const int maxn = 52 + 5;

int n;
int a[maxn], s[maxn];
bool dp[maxn][15][5][15][5];

int main()
{
	cin >> n;
	rep (i, n)
	{
		string st;
		cin >> st;
		a[i+1] = string("23456789TJQKA").find (st[0]);
		s[i+1] = string("SDHC").find (st[1]);
	}
	if (n == 1)
	{
		cout << "YES" << endl;
		return 0;
	}
	if (n == 2 && (a[1] == a[2] || s[1] == s[2]))
	{
		cout << "YES" << endl;
		return 0;
	}
	dp[n][a[n-1]][s[n-1]][a[n]][s[n]] = 1;
	rof (i, n, 2)
	{
		int a1 = a[i-1], s1 = s[i-1];
		rep (a2, 13) rep (s2, 4) rep (a3, 13) rep (s3, 4)
		{
			if (dp[i+1][a2][s2][a3][s3] && (a1==a3||s1==s3))
			{
				dp[i][a3][s3][a2][s2] = 1;
				if (i == 2 && (a3==a2 || s3==s2))
				{
					cout << "YES" << endl;
					return 0;
				}
			}
			if (dp[i+1][a2][s2][a3][s3] && (a2==a3||s2==s3))
			{
				dp[i][a1][s1][a3][s3] = 1;
				if (i == 2 && (a1==a3 || s1==s3))
				{
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	{ int _; cin >> _; }
}
