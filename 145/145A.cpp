// Author: MohammadReza Maleki (MrM)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) a = max(a,b)
#define cmn(a, b) a = min(a,b)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef vector <int> vi;

////////////////////////////////////////////////

int main()
{
	string a, b;
	cin >> a >> b;
	int n = sz(a);
	int fn = 0, fm = 0, d = 0;
	rep (i, n)
		d += (a[i] != b[i]), fn += (a[i] == '4'), fm += (b[i] == '4');
	int ans = abs (fn - fm);
	ans = ans + abs (d - ans) / 2;
	cout << ans << endl;
	{ int _; cin >> _; }
}
