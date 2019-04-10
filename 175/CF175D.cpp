// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>

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

const int maxHP = 200 + 3;
const int maxDT = 30 + 2;

int hp1, dt1, l1, r1, p1;
int hp2, dt2, l2, r2, p2;

double P1, P2, T1, T2;
double dp[maxHP][maxHP][maxDT][2];

void fix (int &X, int &Y)
{
	int tmp = min (X, Y);
	X -= tmp;
	Y -= tmp;
}

double &DP (int h1, int h2, int d1, int d2)
{
	if (d1 == 0)
		return dp[h1][h2][d2][0];
	return dp[h1][h2][d1][1];
}

double calc (int h1, int h2, int d1, int d2)
{
	fix (d1, d2);
	if (h2 <= 0) return 1.0;
	if (h1 <= 0) return 0.0;

	double &ret = DP (h1, h2, d1, d2);
	double val = 0;

	if (ret > -9) return ret;
	ret = 0;

	int D1 = d1, D2 = d2;
	bool first = true;
	double PP = 1.0;
	while (first || D1 != d1 || D2 != d2)
	{
		double tmp = 0.0;
		if (D1 == 0)
		{
			fer (x, l1, r1+1)
				tmp += calc (h1, h2 - x, dt1, D2);
			tmp *= T1;
			D1 = dt1;
			fix (D1, D2);
			val += tmp * PP;
			PP *= 1 - P1;
		}
		else // if (D2 == 0)
		{
			fer (x, l2, r2+1)
				tmp += calc (h1 - x, h2, D1, dt2);
			tmp *= T2;
			D2 = dt2;
			fix (D1, D2);
			val += tmp * PP;
			PP *= 1 - P2;
		}
		first = false;
	}
cerr << h1 << ' ' << h2 << ' ' << d1 << ' ' << d2 << ' ' << val << endl;
	if (0 <= PP && PP < 1)
		val *= 1 + PP / (1 - PP);
	else
		val = 1;
	D1 = d1, D2 = d2;
	first = true;
	double TP = 1;
	while (first || D1 != d1 || D2 != d2)
	{
		double tmp = 0.0;
		if (D1 == 0)
		{
			fer (x, l1, r1+1)
				tmp += calc (h1, h2 - x, dt1, D2);
			tmp *= T1;
			DP (h1, h2, D1, D2) = val;
			D1 = dt1;
			fix (D1, D2);
			val -= tmp * TP;
			val /= 1 - P1;
			val += tmp * PP;
			TP *= 1 - P1;
		}
		else // if (D2 == 0)
		{
			fer (x, l2, r2+1)
				tmp += calc (h1 - x, h2, D1, dt2);
			tmp *= T2;
			DP (h1, h2, D1, D2) = val;
			D2 = dt2;
			fix (D1, D2);
			val -= tmp * TP;
			val /= 1 - P1;
			val += tmp * PP;
			TP *= 1 - P2;
		}
		first = false;
	}

	return ret;
}

int main()
{
	cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
	cin >> hp2 >> dt2 >> l2 >> r2 >> p2;

	rep (i, maxHP) rep (j, maxHP) rep (ii, maxDT) rep (jj, 2)
		dp[i][j][ii][jj] = -9999;

	P1 = (100.0 - p1) / 100.0;
	T1 = P1 / (r1 - l1 + 1);
	P2 = (100.0 - p2) / 100.0;
	T2 = P2 / (r2 - l2 + 1);

	cout << fixed << setprecision (6);
	if (p1 == 100 && p2 == 100)
		cout << 0.0 << endl;
	else if (p2 == 100)
		cout << 1.0 << endl;
	else if (p1 == 100)
		cout << 0.0 << endl;
	else
		cout << calc (hp1, hp2, 0, 0) << endl;

	{ int _; cin >> _; }
}
