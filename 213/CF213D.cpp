// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>

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
typedef pair <double, double> point;

///////////////////////////////////////////////

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const double INF = 1e18;

ostream &operator << (ostream &out, point p) { return out << p.X << ' ' << p.Y; }
istream &operator >> (istream &in, point &p) { return in >> p.X >> p.Y; }

inline bool equal (double v1, double v2) { return -EPS < v1 - v2 && v1 - v2 < EPS; }

point operator + (point p, point q) { return point (p.X + q.X, p.Y + q.Y); }
point operator - (point p, point q) { return point (p.X - q.X, p.Y - q.Y); }
point operator * (point p, double m) { return point (p.X * m, p.Y * m); }
point operator * (double m, point p) { return point (p.X * m, p.Y * m); }
point operator += (point &p, point q) { return p = p + q; }
point operator -= (point &p, point q) { return p = p - q; }
point operator *= (point &p, double m) { return p = p * m; }

inline double dot (point p, point q) { return p.X * q.X + p.Y * q.Y; }
inline double cross (point p, point q) { return p.X * q.Y - p.Y * q.X; }
//inline double cross (point p, point q1, point q2) { return (q1.X-p.X) * (q2.Y-p.Y) - (q1.Y-p.Y) * (q2.X-p.X); }
inline double abs (point p) { return sqrt (p.X*p.X + p.Y*p.Y); }

inline bool isParallel (point a, point b, point c, point d) { return equal (cross (b - a, d - c), 0); }

inline double getCos (point a, point b) { return dot (a, b) / (abs (a) * abs (b)); }
inline double getSin (point a, point b) { return cross (a, b) / (abs (a) * abs (b)); }

double turnAngle (point a, point b, point c) { double r = PI - atan2 (cross (c - b, a - b), dot (c - b, a - b)); return r <= PI ? r : r - 2*PI; }

bool inrange (double a, double b, double c) { if (a > c) swap (a, c); return b > a-EPS && b < c+EPS; }

inline bool onLine (point p, point q1, point q2) { return equal (cross (q1 - p, q2 - p), 0) && inrange (q1.X, p.X, q2.X) && inrange (q1.Y, p.Y, q2.Y); }
inline double distPL (point p, point q1, point q2) { return cross (q1 - p, q2 - p) / abs (q2 - q1); }

bool isInter (point p1, point p2, point q1, point q2) { return cross(p2-p1,q1-p1)*cross(p2-p1,q2-p1)<0 && cross(q2-q1,p1-q1)*cross(q2-q1,p2-q1)<0; }
point inter (point a, point b, point c, point d) { return c + cross (c - a, b - a) / cross (b - a, d - c) * (d - c); }
point rotate (point p, point q, double rad) { p -= q; double C = cos (rad), S = sin (rad); return q + point (C * p.X - S * p.Y, C * p.Y + S * p.X); }
point rotate90 (point p, point q) { p -= q; return q + point (-p.Y, p.X); }

//////////////////////////////////////////////////////////////////////

const double ang = 2*PI / 5;

const point pt[5] = {point (0, 0), point (-10-10*cos(ang), 10*sin(ang)), point (10*cos(ang), 10*sin(ang)), point (-10, 0), point (-5,10*sin(ang)+10*sin(ang/2))};

int n;

int main()
{
	cin >> n;
	cout << 4*n+1 << endl;
	cout << fixed << setprecision (12);
	cout << 0.0 << ' ' << 0.0 << endl;
	rep (i, n)
	{
		point p = pt[4] * i;
		cout << p + pt[1] << endl;
		cout << p + pt[2] << endl;
		cout << p + pt[3] << endl;
		cout << p + pt[4] << endl;
	}
	rep (i, n)
		cout << 4*i+1 << ' ' << 4*i+4 << ' ' << 4*i+2 << ' ' << 4*i+5 << ' ' << 4*i+3 << endl;
	cout << 1;
	rep (i, n)
		cout << ' ' << 4*i+2 << ' ' << 4*i+3 << ' ' << 4*i+4 << ' ' << 4*i+5;
	rof (i, n, 0)
		cout << ' ' << 4*i+1;
	cout << endl;
	{ int _; cin >> _; }
}


