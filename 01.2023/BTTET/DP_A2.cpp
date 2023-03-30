#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
const int maxn=1e6+5;
int n;
vector<ll> a(maxn);
ll mina = 0,maxa = 1e9;
ll kq = 0;
void Solve() {
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    mina = a[0];
    int itmin = 0, itmax = 0;
    for (int i = 1; i<n; i++) {
        if (a[i] <= mina) {
            mina = a[i];
            itmin = i;
        }
        else {
            kq = max(kq, a[i] - mina);
        }
    }
    cout << kq;
}
int main () {
    freopen("DP_A2.INP","r",stdin);
    freopen("DP_A2.OUT","w",stdout);
    iam;
    Solve();
}
