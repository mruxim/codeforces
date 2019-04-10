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

const int maxn = 100000 + 100;
const int maxk = 10000 + 100;

ll h;
int n, m, k;

ll cell[maxn];
int cost[maxn];

vector <int> pos[maxk];
int rid[maxk];
ll start[maxk];

int heap[maxn], heapPos[maxn], heapSize;

int perm[maxk];

bool better(int x, int y) { return cost[x] > cost[y] || (cost[x] == cost[y] && x < y); }

void push(int ind) {
	heap[heapSize++] = ind;
	int x = heapSize - 1;
	heapPos[ind] = x;
	while(x && better(heap[x], heap[(x-1)/2]))
		swap(heap[x], heap[(x-1)/2]), swap(heapPos[heap[x]], heapPos[heap[(x-1)/2]]), x = (x-1)/2;
}

void bubbleDown(int x) {
	if(x == -1) return;
	while(2*x+1 < heapSize) {
		int y = 2*x+1;
		if(y+1 < heapSize && better(heap[y+1], heap[y]))
			y++;
		if(better(heap[y], heap[x]))
			swap(heap[x], heap[y]), swap(heapPos[heap[x]], heapPos[heap[y]]), x = y;
		else
			break;
	}
}

int exMin() {
	if(heapSize == 0) return 0;
	int ret = cost[heap[0]];
	cost[heap[0]] = 0;
	heapSize--;
	swap(heap[0], heap[heapSize]);
	swap(heapPos[heap[0]], heapPos[heap[heapSize]]);
	bubbleDown(0);
	return ret;
}

bool update(ll newstart) {
	int mod = newstart % k;
	if(newstart >= start[mod]) return false;
	start[mod] = newstart;
	while(rid[mod] && cell[pos[mod][rid[mod]-1]] >= newstart)
		rid[mod]--, push(pos[mod][rid[mod]]);
	return true;
}

void addMove(ll dis) {
	sort(perm, perm+k, [](const int &x, const int &y) { return start[x] < start[y]; } );
	rep(i, k) {
		ll now = start[perm[i]] + dis;
		while(update(now)) now += dis;
	}
}

int main() {
	ios::sync_with_stdio (false);

	cin >> h >> n >> m >> k;

	rep (i, n) {
		cin >> cell[i] >> cost[i];
		cell[i]--;
		pos[cell[i] % k].pb(i);
		rid[cell[i] % k]++;
	}

	rep(i, k) sort(all(pos[i]), [] (const int &x, const int &y) { return cell[x] < cell[y]; } );

	fill(start, start+k, h+1);
	fill(heapPos, heapPos+n, -1);

	update(0);

	rep(i, k) perm[i] = i;

	rep(z, m) {
		int com;
		cin >> com;
		if(com == 1) { // P.I.T.A.
			ll x;
			cin >> x;
			addMove(x);
		}
		else if(com == 2) {
			int x, y;
			cin >> x >> y;
			x--;
			cost[x] -= y;
			bubbleDown(heapPos[x]);
		}
		else // com == 3
			cout << exMin() << endl;
	}

	{ int _; cin >> _; return 0; }
}
