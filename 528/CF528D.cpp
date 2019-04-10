// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

typedef pair<double, double> point;

inline point operator + (const point &p, const point &q) { return point(p.X + q.X, p.Y + q.Y); }
inline point operator * (const point &p, const point &q) { return point(p.X * q.X - p.Y * q.Y, p.X * q.Y + p.Y * q.X); }

const int NN = 1<<19;

void FFT(point A[], bool inv) {
	static point B[NN];
	double arg = acos(-1.0);
	for(int len = NN / 2; len >= 1; len /= 2, arg /= 2) {
		point mul = point(1.0, 0.0), w = point(cos(arg), inv ? sin(arg) : -sin(arg));
		rep(j, NN / len) {
			point *TA = A + (j*2*len) % NN;
			rep(i, len) B[i+j*len] = TA[i] + mul * TA[i+len];
			mul = mul * w;
		}
		copy(B, B+NN, A);
	}
}

void multiply(point A[], point B[], point C[]) {
	FFT(A, false); FFT(B, false);
	rep(i, NN) C[i] = A[i] * B[i];
    FFT(C, true);
    rep(i, NN) C[i].X /= NN, C[i].Y /= NN;
}

int n, m, k;
string s, t;
point S[NN], T[NN], R[NN];
int bad[NN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	cin >> s >> t;

	for(char ch: "ATGC") {
		memset(S, 0, sizeof S);
		memset(T, 0, sizeof T);
		rep(i, n) if(s[i] == ch) S[n-i-1].X = 1;

		int cnt = 0;
		rep(i, m) if(t[i] == ch) T[i].X = 1, cnt++;

		rof(i, n, 0) if(S[i].X > 0.5)
			for(int j = i+1; j < n && j <= i+k && S[j].X < 0.5; j++)
				S[j].X = 1;
		rep(i, n) if(S[i].X > 0.5)
			for(int j = i-1; j >= 0 && j >= i-k && S[j].X < 0.5; j--)
				S[j].X = 1;
		multiply(S, T, R);
		rep(i, n) if(R[i].X+0.5 < cnt) bad[i]++;
	}

	cout << count(bad, bad+n, 0) << endl;

	return 0;
}

