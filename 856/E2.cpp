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

typedef pair<double, double> point;

inline point operator +(point p, point q) { return point (p.X + q.X, p.Y + q.Y); }
inline point operator -(point p, point q) { return point (p.X - q.X, p.Y - q.Y); }
inline point operator *(double m, point p) { return point (p.X * m, p.Y * m); }

inline double cross(point p, point q) { return p.X * q.Y - p.Y * q.X; } // O -> p -> q
inline double cross(point p, point q1, point q2) { return (q1.X-p.X) * (q2.Y-p.Y) - (q1.Y-p.Y) * (q2.X-p.X); }
inline double norm(point p) { return p.X*p.X + p.Y*p.Y; }

bool is_intersect(point p1, point p2, point q1, point q2) { return cross(p1,p2,q1)*cross(p1,p2,q2)<0 && cross(q1,q2,p1)*cross(q1,q2,p2)<0; } // checks strict line intersection
point intersection(point a, point b, point c, point d) { return c + cross (c - a, b - a) / cross (b - a, d - c) * (d - c); } // cross (b - a, d - c) != 0 OR ab !parallel cd

const int maxq = 500000 + 100;

int r, q;
int qt[maxq], qx[maxq], qy[maxq];
pii qp[maxq];
int id[maxq], n;
pii as[maxq], bs[maxq];

multiset<int> fen[maxq];

point O, A, B;

bool cmpa(pii a, pii b) { return cross(A, a, b) < 0; }
bool cmpb(pii a, pii b) { return cross(B, a, b) > 0; }

void add(int x, int y, int sign) {
	for(x++; x < maxq; x += x & -x)
		if(sign == 1)
			fen[x].insert(y);
		else
			fen[x].erase(fen[x].find(y));
}

void addpoint(int myid, int sign) {
	int xpos = lower_bound(as, as + n, qp[myid], cmpa) - as;
	int ypos = lower_bound(bs, bs + n, qp[myid], cmpb) - bs;
	add(xpos, ypos, sign);
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

	O = point(0, 0), A = point(-r, 0), B = point(r, 0);

	rep(i, q) {
		cin >> qt[i];
		if(qt[i] == 1) {
			cin >> qp[i].X >> qp[i].Y;
			id[n] = i;
			as[n] = qp[i];
			bs[n] = qp[i];
			n++;
		} else if(qt[i] == 2)
			cin >> qx[i], qx[i]--;
		else // qt[i] == 3
			cin >> qx[i] >> qy[i], qx[i]--, qy[i]--;
	}

	sort(as, as + n, cmpa);
	sort(bs, bs + n, cmpb);

	rep(i, q) {
		if(qt[i] == 1)
			addpoint(i, 1);
		else if(qt[i] == 2)
			addpoint(id[qx[i]], -1);
		else {
			int id1 = id[qx[i]];
			int id2 = id[qy[i]];

			addpoint(id1, -1);
			addpoint(id2, -1);

			int xpos = upper_bound(as, as + n, max(qp[id1], qp[id2], cmpa), cmpa) - as;
			int ypos = upper_bound(bs, bs + n, max(qp[id1], qp[id2], cmpb), cmpb) - bs;
	
			point inter = intersection(A, max(qp[id1], qp[id2], cmpa), B, max(qp[id1], qp[id2], cmpb));
			if(get(xpos) >= ypos && norm(inter) >= r*(ll)r - 1e-6) cout << "YES" << endl;
			else cout << "NO" << endl;

			addpoint(id1, 1);
			addpoint(id2, 1);
		}
	}

	return 0;
}

