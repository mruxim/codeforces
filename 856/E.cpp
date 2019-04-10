// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
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

point circumcircle(point p1, point p2, point p3) {
	p2 = (p1+p2) / 2, p3 = (p1+p3) / 2;
	return intersection (p2, rotate90(p1, p2), p3, rotate90(p1, p3));
}

point incircle(point p1, point p2, point p3) {
		double d12 = abs (p1, p2), d13 = abs (p1, p3), d23 = abs (p2, p3), perim = d12 + d13 + d23;
		return (p1*d23 + p2*d13 + p3*d12) / perim;
}

vector<point> linecircle(point p1, point p2, point c, double r) {
	point t = c + rotate90(p2 - p1);
	point h = intersection(p1, p2, c, t);
	double ch2 = norm(c, h);
	if(ch2 > r*r + EPS) return vector<point>();
	if(ch2 > r*r - EPS) return vector<point>(1, h);
	point mv = (p2-p1) / abs(p1, p2) * sqrt(r*r - ch2);
	return vector<point>({h - mv, h + mv});
}

const double eps = 1e-9;
const int maxq = 500000 + 100;

int r, q;
int qt[maxq], qx[maxq], qy[maxq];
double qa[maxq], qb[maxq];
double As[maxq], Bs[maxq];
int id[maxq], n, An, Bn;

multiset<int> fen[maxq];

void add(int x, int y, int f) {
	for(x++; x < maxq; x += x & -x)
		if(f == 1)
			fen[x].insert(y);
		else
			fen[x].erase(fen[x].find(y));
}

int get(int x) {
	int res = 1 << 25;
	for(; x; x -= x & -x)
		if(sz(fen[x]))
			smin(res, *fen[x].begin());
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> r >> q;
	point O(0, 0), A(-r, 0), B(r, 0);
	rep(i, q) {
		cin >> qt[i];
		if(qt[i] == 1) {
			id[n] = i;
			cin >> qx[i] >> qy[i];
			qa[i] = As[n] = -turnAngle(O, A, point(qx[i], qy[i]));
			qb[i] = Bs[n] = turnAngle(O, B, point(qx[i], qy[i]));
			n++;
		} else if(qt[i] == 2)
			cin >> qx[i], qx[i]--;
		else // qt[i] == 3
			cin >> qx[i] >> qy[i], qx[i]--, qy[i]--;
	}

	sort(As, As + n); An = unique(As, As + n) - As;
	sort(Bs, Bs + n); Bn = unique(Bs, Bs + n) - Bs;

	rep(i, q) {
		if(qt[i] == 1) {
			int apos = lower_bound(As, As + An, qa[i]) - As;
			int bpos = lower_bound(Bs, Bs + Bn, qb[i]) - Bs;
			add(apos, bpos, 1);
		} else if(qt[i] == 2) {
			int myid = id[qx[i]];
			int apos = lower_bound(As, As + An, qa[myid]) - As;
			int bpos = lower_bound(Bs, Bs + Bn, qb[myid]) - Bs;
			add(apos, bpos, -1);
		} else {
			int pid = id[qx[i]];
			int qid = id[qy[i]];
			if(qa[pid] > qa[qid]) swap(pid, qid);

			int xpos = lower_bound(As, As + An, max(qa[pid], qa[qid]) + eps) - As;
			int ypos = lower_bound(Bs, Bs + Bn, max(qb[pid], qb[qid]) + eps) - Bs;
	
			add(lower_bound(As, As + An, qa[pid]) - As, lower_bound(Bs, Bs + Bn, qb[pid]) - Bs, -1);
			add(lower_bound(As, As + An, qa[qid]) - As, lower_bound(Bs, Bs + Bn, qb[qid]) - Bs, -1);

			point inter = intersection(A, point(qx[pid], qy[pid]), B, point(qx[qid], qy[qid]));
			if(get(xpos) >= ypos && abs(inter) >= r - 1e-7) cout << "YES" << endl;
			else cout << "NO" << endl;

			add(lower_bound(As, As + An, qa[pid]) - As, lower_bound(Bs, Bs + Bn, qb[pid]) - Bs, 1);
			add(lower_bound(As, As + An, qa[qid]) - As, lower_bound(Bs, Bs + Bn, qb[qid]) - Bs, 1);
		}
	}

	return 0;
}

