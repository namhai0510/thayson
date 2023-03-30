#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
const int maxn=1e6+5;
int n,l,r,t;
ll S = 0;
ll a[maxn];
void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll t; cin >> t;
        S+=t;
        a[i]=S;
    }
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}
int main () {
    freopen("DP_A4.INP","r",stdin);
    freopen("DP_A4.OUT","w",stdout);
    iam;
    Solve();
}
