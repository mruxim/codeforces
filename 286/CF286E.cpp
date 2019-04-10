// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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
#include <bitset>

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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

typedef pair<double, double> point;

inline point operator + (const point &p, const point &q) { return point(p.X + q.X, p.Y + q.Y); }
inline point operator * (const point &p, const point &q) { return point(p.X * q.X - p.Y * q.Y, p.X * q.Y + p.Y * q.X); }

const int NN = 1<<21;

void FFT(point A[], point B[], bool inv = false)
{
	double arg = acos(-1.0);
	for (int k = NN / 2; k >= 1; k /= 2, arg /= 2)
	{
		point mul = point(1.0, 0.0), w = point(cos(arg), inv ? sin(arg) : -sin(arg));
		rep (j, NN / k)
		{
			rep (i, k) B[i+j*k] = A[i+(j*2*k)%NN] + mul * A[i+k+(j*2*k)%NN];
			mul = mul * w;
		}
		copy (B, B+NN, A);
	}
}

int n, m;
point A[NN], B[NN], C[NN];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	A[0].X = 1;
	rep (i, n) { int x; cin >> x; A[x].X = 1; }
	copy (A, A+NN, C);
	FFT (C, B, 0);
	rep (i, NN) B[i] = B[i] * B[i];
	FFT (B, C, 1);
	rep (i, NN) C[i].X /= NN;

	rep (i, m+1) cerr << i << ' ' << C[i].X << endl;
	rep (i, m+1) if (C[i].X > 0.5 && A[i].X < 0.5) { cout << "NO" << endl; return 0; }
	cout << "YES" << endl;

	int cnt = 0;
	rep (i, m+1) if (i && C[i].X > 0.5 && C[i].X < 2.5) cnt++;
	cout << cnt << endl;
	rep (i, m+1) if (i && C[i].X > 0.5 && C[i].X < 2.5) cout << i << ' ';
	cout << endl;




	{ return 0; }
}

