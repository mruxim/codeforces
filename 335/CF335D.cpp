// .... .... .....!
// P..... C.....!

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int maxl = 3000 + 5;

int n;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];

int sum[maxl][maxl];
int sul[maxl][maxl];
int sur[maxl][maxl];
int sdl[maxl][maxl];
int sdr[maxl][maxl];

int hul[maxl][maxl];
int hdr[maxl][maxl];
int hur[maxl][maxl];
int hdl[maxl][maxl];

vector<int> _st[2*maxl], _ed[2*maxl];
vector<int> *st = _st + maxl, *ed = _ed + maxl;

int ok (int x1, int y1, int x2, int y2)
{
	int area = (x2-x1+1) * (y2-y1+1);
	if (area != sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]) return -1;
	if (area < sur[x2][y2] - sur[x2][y1-1] - sur[x1-1][y2] + sur[x1-1][y1-1]) return -1;

	if (area != sur[x2][y2] - sur[x2][y1-1] - sur[x1-1][y2] + sur[x1-1][y1-1]) return 0;
	if (area != sdl[x2][y2] - sdl[x2][y1-1] - sdl[x1-1][y2] + sdl[x1-1][y1-1]) return 0;

	area = sul[x2][y2] - sul[x2][y1-1] - sul[x1-1][y2] + sul[x1-1][y1-1];

	if (area != sul[x2][y2] - sul[x2][y1-1] - sul[x1-1][y2] + sul[x1-1][y1-1]) return 0;
	if (area != sdr[x2][y2] - sdr[x2][y1-1] - sdr[x1-1][y2] + sdr[x1-1][y1-1]) return 0;

	area = hul[x2][y2] - hul[x2][y1-1] - hul[x1-1][y2] + hul[x1-1][y1-1];

	if (area != hul[x2][y2] - hul[x2][y1-1] - hul[x1-1][y2] + hul[x1-1][y1-1]) return 0;
	if (area != hdr[x2][y2] - hdr[x2][y1-1] - hdr[x1-1][y2] + hdr[x1-1][y1-1]) return 0;
	if (area != hur[x2][y2] - hur[x2][y1-1] - hur[x1-1][y2] + hur[x1-1][y1-1]) return 0;
	if (area != hdl[x2][y2] - hdl[x2][y1-1] - hdl[x1-1][y2] + hdl[x1-1][y1-1]) return 0;

	return 1;
}

int main()
{
	ios::sync_with_stdio (false);

	cin  >> n;
	rep (i, n)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		x1[i]++, y1[i]++, x2[i]++, y2[i]++;
		st[x1[i]-y1[i]].pb (i);
		ed[x2[i]-y2[i]].pb (i);
	}
	fer (diff, -maxl, maxl)
	{
		sort (all (st[diff]), [](const int &r1, const int &r2) { return x1[r1] < x1[r2]; } );
		sort (all (ed[diff]), [](const int &r1, const int &r2) { return x2[r1] < x2[r2]; } );
	}

	rep (i, n)
	{
		fer (x, x1[i], x2[i]) fer (y, y1[i], y2[i]) sum[x][y]++;
		int sc = (x2[i] - x1[i]) * (y2[i] - y1[i]);
		int sc2 = (x2[i] - y1[i] + 305LL * i) % 457LL + (y2[i] - x1[i] + 305LL) % 3007LL;
		int sc3 = (13 * x2[i] - y1[i] + 305LL) % 457LL + (17 * y2[i] - x1[i] + 305LL * i) % 3007LL;

		sur[x2[i]-1][y2[i]-1] += sc;
		sdl[x1[i]][y1[i]] += sc;
		sul[x2[i]-1][y1[i]] += sc2;
		sdr[x1[i]][y2[i]-1] += sc2;

		hur[x2[i]-1][y2[i]-1] += sc3;
		hdl[x1[i]][y1[i]] += sc3;
		hul[x2[i]-1][y1[i]] += sc3;
		hdr[x1[i]][y2[i]-1] += sc3;
	}
	fer (x, 1, maxl) fer (y, 1, maxl)
	{
		sum[x][y] += sum[x][y-1] + sum[x-1][y] - sum[x-1][y-1];
		sul[x][y] += sul[x][y-1] + sul[x-1][y] - sul[x-1][y-1];
		sur[x][y] += sur[x][y-1] + sur[x-1][y] - sur[x-1][y-1];
		sdl[x][y] += sdl[x][y-1] + sdl[x-1][y] - sdl[x-1][y-1];
		sdr[x][y] += sdr[x][y-1] + sdr[x-1][y] - sdr[x-1][y-1];

		hul[x][y] += hul[x][y-1] + hul[x-1][y] - hul[x-1][y-1];
		hur[x][y] += hur[x][y-1] + hur[x-1][y] - hur[x-1][y-1];
		hdl[x][y] += hdl[x][y-1] + hdl[x-1][y] - hdl[x-1][y-1];
		hdr[x][y] += hdr[x][y-1] + hdr[x-1][y] - hdr[x-1][y-1];
	}

	int X1 = -1, Y1, X2, Y2;

	vector<int> vv;
	fer (diff, -maxl, maxl) vv.pb (diff);
	random_shuffle (all(vv));

//	fer (diff, -maxl, maxl)
	for (auto diff : vv)
	{
		vector<int> &S = st[diff], &E = ed[diff];
		int p = 0;
		rep (i, sz(S))
		{
			int x = x1[S[i]], y = y1[S[i]];
			while (p < sz(E) && x2[E[p]] <= x) p++;
			if (p >= sz(E)) break;
			fer (k, p, sz(E))
			{
				int ret = ok (x, y, x2[E[k]]-1, y2[E[k]]-1);
				if (ret == -1) break;
				if (ret)
				{
					X1 = x, Y1 = y, X2 = x2[E[k]], Y2 = y2[E[k]];
					goto end;
				}
			}
		}
	}

	end:;
	if (X1 != -1)
	{
		int cnt = 0;
		rep (i, n) if (X1 <= x1[i] && Y1 <= y1[i] && x2[i] <= X2 && y2[i] <= Y2) cnt++;

		cout << "YES " << cnt << endl;
		rep (i, n) if (X1 <= x1[i] && Y1 <= y1[i] && x2[i] <= X2 && y2[i] <= Y2)
			cout << i+1 << ' ';
		cout << endl;
	}
	else
		cout << "NO" << endl;

	{ int _; cin >> _; return 0; }
}
