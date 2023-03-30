#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
const int maxn=1e3+5;
int m,n;
ll S = 0;
ll  a[maxn][maxn];
void Solve() {
    cin >> m >> n;
    memset(a,0,sizeof(a));
    for (int i = 1 ;i <= m;i++) {
        S = 0;
        for (int j = 1;j <= n;j++) {
            ll t; cin >> t;
            S+=t;
            a[i][j] = S;
        }
    }
    int t; cin >> t;
    while (t--) {
        S=0;
        int x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;
        //cout << a[x1][y2] << " " << a[x1][y1-1] << " | ";
        //cout << a[x2][y2] << " " << a[x2][y1-1] << endl;
        for (int i = x1;i<=x2;i++) S += a[i][y2] - a[i][y1-1];
        cout << S << endl;
    }
}
int main () {
    freopen("DP_A9.INP","r",stdin);
    freopen("DP_A9.OUT","w",stdout);
    iam;
    Solve();
}
