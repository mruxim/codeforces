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

const int inf = 1 << 29;

int n, s;
int a, b, c;

int best = inf;
int ak, bk, ck;

void up (int AK, int BK, int CK)
{
//	cerr << AK << ' ' << BK << ' ' << CK << endl;
	if (AK > BK || BK > CK) return;
	int dd = abs (a*AK - b*BK) +  abs(b*BK - c*CK);
	if (dd < best)
		best = dd, ak = AK, bk = BK, ck = CK;
}

int main()
{
	cin >> n >> s;
	rep (i, n)
	{
		int tt; cin >> tt;
		if (tt == 3) a++;
		else if (tt == 4) b++;
		else c++;
	}
	
	rep (i, s+1)
	{
		if (i*n > s) break;
		int ss = s - a*i, j = i;
		while (i*a+(n-a)*j <= s && (ss-b*j) % c) j++;
//		cerr << " ^^ " << endl;
		if ((ss-b*j)%c) continue; if ((ss-b*j)/c < j) continue;
//		cerr << " ** " << endl;
		up (i, j, (ss - b*j) / c);
		int jj = j+1;
		while (i*a+(n-a)*jj <= s && (ss-b*jj) % c) jj++;
//		if (i == 2) cerr << i << ' ' << jj << endl;
		if ((ss-b*jj)%c) continue; if ((ss-b*jj)/c < jj) continue;
		up (i, jj, (ss - b*jj) / c);
		if (b*jj >= a*i || b*jj >= ss - b*jj) continue;

		int ul = (ss - i*a) / (n-a);
		int d = jj - j;
		ul = min (ul, a*i/b);
		if (jj + d > ul) continue;
		
		int x = (ul - jj) / d;
		x = x * d + jj;
		up (i, x, (ss - b*x) / c);
	}

/*	rep (i, s+1) fer (j, i, s-i+1)
	{
		if (n-i-j < j) continue;
		if (a*i + b*(n-i) > s) continue;
		int ss = s - a*i - b*j;
		int ZZ = best;
		if (ss % c == 0) up (i, j, ss / c);
		if (best != ZZ) cerr << " ** " << i << ' ' << j << ' ' << ss / c << endl;
	}
*/
	if (best == inf)
		cout << -1 << endl;
	else
		cout << ak << ' ' << bk << ' ' << ck << endl;
	{ int _; cin >> _; }
}
