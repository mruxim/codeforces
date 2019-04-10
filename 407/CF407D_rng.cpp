#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int X,Y;
int a[410][410];
int b[410][410];
short last[410][160010];

int main(void){
	int ans=0,i,j,x,x1,x2,y;

	cin >> X >> Y;
	REP(i,X) REP(j,Y) scanf("%d", &a[i][j]);

	REP(i,X+1) REP(j,X+1) b[i][j] = Y;
	REP(i,X) REP(j,160010) last[i][j] = Y;

	for(y=Y-1;y>=0;y--){
		REP(x,X){
			b[x][x+1] = min(b[x][x+1], (int)last[x][a[x][y]]);
			ans = max(ans, b[x][x+1] - y);
		}
		REP(x,X) last[x][a[x][y]] = y;
		for(x1=X-2;x1>=0;x1--) for(x2=x1+2;x2<=X;x2++){
			b[x1][x2] = min(min(b[x1][x2], min(b[x1+1][x2], b[x1][x2-1])), min((int)last[x1][a[x2-1][y]], (int)last[x2-1][a[x1][y]]));
			ans = max(ans, (b[x1][x2] - y) * (x2 - x1));
		}
	}

	cout << ans << endl;

	return 0;
}
