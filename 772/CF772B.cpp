// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const double INF = 1e18;

typedef pair <double, double> point;

ostream &operator <<(ostream &out, point p) { return out << p.X << ' ' << p.Y; }
istream &operator >>(istream &in, point &p) { return in >> p.X >> p.Y; }

inline bool equal(double v1, double v2) { return -EPS < v1 - v2 && v1 - v2 < EPS; }
inline bool is_zero(double v) { return -EPS < v && v < EPS; }

inline point operator +(point p, point q) { return point (p.X + q.X, p.Y + q.Y); }
inline point operator -(point p, point q) { return point (p.X - q.X, p.Y - q.Y); }
inline point operator *(point p, double m) { return point (p.X * m, p.Y * m); }
inline point operator *(double m, point p) { return point (p.X * m, p.Y * m); }
inline point operator /(point p, double m) { return point (p.X / m, p.Y / m); }
inline point operator +=(point &p, point q) { return p = p + q; }
inline point operator -=(point &p, point q) { return p = p - q; }
inline point operator *=(point &p, double m) { return p = p * m; }
inline point operator /=(point &p, double m) { return p = p / m; }

inline double dot(point p, point q) { return p.X * q.X + p.Y * q.Y; } // O -> p -> q
inline double cross(point p, point q) { return p.X * q.Y - p.Y * q.X; } // O -> p -> q
inline double cross(point p, point q1, point q2) { return (q1.X-p.X) * (q2.Y-p.Y) - (q1.Y-p.Y) * (q2.X-p.X); }
inline double abs(point p) { return sqrt (p.X*p.X + p.Y*p.Y); }
inline double norm(point p) { return p.X*p.X + p.Y*p.Y; }
inline double abs(point p, point q) { return sqrt ((p.X-q.X)*(p.X-q.X) + (p.Y-q.Y)*(p.Y-q.Y)); }
inline double norm(point p, point q) { return (p.X-q.X)*(p.X-q.X) + (p.Y-q.Y)*(p.Y-q.Y); }

inline bool isParallel(point a, point b, point c, point d) { return is_zero (cross (b - a, d - c)); } // ab || cd

inline double getCos(point p, point q) { return dot (p, q) / (abs (p) * abs (q)); } // angle: Op -> Oq
inline double getSin(point p, point q) { return cross (p, q) / (abs (p) * abs (q)); } // angle: Op -> Oq

double turnAngle(point a, point b, point c) { double r = PI - atan2 (cross (c - b, a - b), dot (c - b, a - b)); return r <= PI ? r : r - 2*PI; } // = PI - ^abc

bool inRange(double a, double b, double c) { if (a > c) swap (a, c); return b > a-EPS && b < c+EPS; }

inline bool onLine(point p, point q1, point q2) { return equal (cross (q1 - p, q2 - p), 0) && inRange (q1.X, p.X, q2.X) && inRange (q1.Y, p.Y, q2.Y); }
inline double getDist(point p, point q1, point q2) { return cross (q1 - p, q2 - p) / abs (q2 - q1); } // point & line : signed

bool is_intersect(point p1, point p2, point q1, point q2) { return cross(p1,p2,q1)*cross(p1,p2,q2)<0 && cross(q1,q2,p1)*cross(q1,q2,p2)<0; } // checks strict line intersection
point intersection(point a, point b, point c, point d) { return c + cross (c - a, b - a) / cross (b - a, d - c) * (d - c); } // cross (b - a, d - c) != 0 OR ab !parallel cd
point rotate(point p, point q, double rad) { p -= q; double C = cos (rad), S = sin (rad); return q + point (C * p.X - S * p.Y, C * p.Y + S * p.X); }
point rotate90(point p) { return point (-p.Y, p.X); } // p about O
point rotate90(point p, point q) { p -= q; return q + point (-p.Y, p.X); } // p about q
point reflect(point p, point q1, point q2) { point q3 = rotate90 (q2 - q1); return 2 * intersection (p, p + q3, q1, q2) - p; }

const int maxn = 1000 + 100;

int n;
point p[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> p[i].X >> p[i].Y;

	double min_dis = 1e10;
	rep(i, n) rep(j, i) smin(min_dis, abs(p[i], p[j]));

	rep(i, n) {
		int j = (i + 1) % n;
		int k = (i + 2) % n;

		smin(min_dis, getDist(p[j], p[i], p[k]));
	}

	cout.setf(ios::fixed);
	cout.precision(8);
	cout << min_dis / 2 << endl;

	return 0;
}

