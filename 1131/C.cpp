// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
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

const int maxn = 100 + 10;

int n;
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];
	sort(a, a+n);

	rep(i, (n+1)/2)
		cout << a[i*2] << ' ';
	rof(i, n/2, 0)
		cout << a[i*2+1] << ' ';
	cout << endl;

	return 0;
}

