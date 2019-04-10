// .... .... .... !

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

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

typedef pair <double, double> point;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const double INF = 1e18;

ostream &operator << (ostream &out, point p) { return out << p.X << ' ' << p.Y; }
istream &operator >> (istream &in, point &p) { return in >> p.X >> p.Y; }

inline bool equal (double v1, double v2) { return -EPS < v1 - v2 && v1 - v2 < EPS; }
inline bool isZero (double v) { return -EPS < v && v < EPS; }

inline point operator + (point p, point q) { return point (p.X + q.X, p.Y + q.Y); }
inline point operator - (point p, point q) { return point (p.X - q.X, p.Y - q.Y); }
inline point operator * (point p, double m) { return point (p.X * m, p.Y * m); }
inline point operator / (point p, double m) { return point (p.X / m, p.Y / m); }
inline point operator * (double m, point p) { return point (p.X * m, p.Y * m); }
inline point operator += (point &p, point q) { return p = p + q; }
inline point operator -= (point &p, point q) { return p = p - q; }
inline point operator *= (point &p, double m) { return p = p * m; }

inline double dot (point p, point q) { return p.X * q.X + p.Y * q.Y; } // O -> p -> q
inline double cross (point p, point q) { return p.X * q.Y - p.Y * q.X; } // O -> p -> q
//inline double cross (point p, point q1, point q2) { return (q1.X-p.X) * (q2.Y-p.Y) - (q1.Y-p.Y) * (q2.X-p.X); }
inline double abs (point p) { return sqrt (p.X*p.X + p.Y*p.Y); }

inline bool isParallel (point a, point b, point c, point d) { return isZero (cross (b - a, d - c)); } // ab || cd

inline double getCos (point p, point q) { return dot (p, q) / (abs (p) * abs (q)); } // angle: Op -> Oq
inline double getSin (point p, point q) { return cross (p, q) / (abs (p) * abs (q)); } // angle: Op -> Oq

double turnAngle (point a, point b, point c) { double r = PI - atan2 (cross (c - b, a - b), dot (c - b, a - b)); return r <= PI ? r : r - 2*PI; } // = PI - ^abc

bool inRange (double a, double b, double c) { if (a > c) swap (a, c); return b > a-EPS && b < c+EPS; }

inline bool onLine (point p, point q1, point q2) { return equal (cross (q1 - p, q2 - p), 0) && inRange (q1.X, p.X, q2.X) && inRange (q1.Y, p.Y, q2.Y); }
inline double getDist (point p, point q1, point q2) { return cross (q1 - p, q2 - p) / abs (q2 - q1); } // point & line : signed

bool isInter (point p1, point p2, point q1, point q2) { return cross(p2-p1,q1-p1)*cross(p2-p1,q2-p1)<0 && cross(q2-q1,p1-q1)*cross(q2-q1,p2-q1)<0; }
point inter (point a, point b, point c, point d) { return c + cross (c - a, b - a) / cross (b - a, d - c) * (d - c); } // cross (b - a, d - c) != 0
point rotate (point p, point q, double rad) { p -= q; double C = cos (rad), S = sin (rad); return q + point (C * p.X - S * p.Y, C * p.Y + S * p.X); }
point rotate90 (point p) { return point (-p.Y, p.X); } // p about O
point rotate90 (point p, point q) { p -= q; return q + point (-p.Y, p.X); } // p about q
point reflect (point p, point q1, point q2) { point q3 = rotate90 (q2 - q1); return 2 * inter (p, p + q3, q1, q2) - p; }

////////////////////////////////////////////////////////////////////////////////

int n, m;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	if (m * 2 == n) { cout << 0 << endl; return 0; }

	point p = mp (-(n+1)/2, 0);
	point q = mp ((n+1)/2, 0);
	point r = mp (0, (n+1) * sin (PI / 3));

	point pq = (q-p) / (n+1), pr = (r-p) / (n+1), qr = (r-q) / (n+1);

	ll ans = 0;

	fer (i, m+1, (n+1)/2+1)
	{
		point s = p + i * pq;
		int u = n - m;
		ll add = 0;
		fer (j, m+1, n+1-m)
		{
			point t = p + j * pr;
			while (u > m && dot (t - s, q + u * qr - s) >= -EPS) u--;
			if (u == m) break;
			add += u - m;
//			cerr << "$$ " << dot (t - s, q + u * qr - s) << endl;
			cerr << i << ' ' << j << ' ' << u << ' ' << add << endl;
		}
		cerr << endl;
		ans += add;
		if (i*2-1 != n) ans += add;
	}

	cout << ans*3 << endl;

	{ int _; cin >> _; return 0; }
}
