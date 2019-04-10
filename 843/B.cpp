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

const int maxn = 50000 + 100;
const int bqs = 1000;

int n, start, x;
int arr[maxn];

pii ask(int ind) {
	cout << "? " << ind << endl;
	cout.flush();

	int value, nxt;
	cin >> value >> nxt;
	return pii(value, nxt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> start >> x;

	rep(i, n) arr[i] = i + 1;

	srand(747);
	rep(i, n) swap(arr[i], arr[rand() % (i + 1)]);

	int pos = start;
	pii t(-1, -1);

	rep(i, min(n, bqs)) {
		pii p = ask(arr[i]);

		if(p.X == x) {
			cout << "! " << p.X << endl;
			cout.flush();
			return 0;
		}

		if(p.X > x) continue;

		if(t.X < p.X) pos = arr[i], t = p;
	}

	if(pos == start) t = ask(pos);
	while(t.X < x && t.Y != -1) {
		pos = t.Y;
		t = ask(pos);
	}

	if(t.X < x) t.X = -1;
	cout << "! " << t.X << endl;

	return 0;
}

