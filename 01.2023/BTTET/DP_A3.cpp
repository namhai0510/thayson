#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
const int maxn=1e6+5;
int n;
vector<ll> a(maxn);
ll mina = 1e9,maxa = -1e9;
ll kq = 0;
void Solve() {
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    mina = a[n];
    int itmin = 0, itmax = 0;
    for (int i = n - 1; i>=0; i--) {
        if (a[i] >= maxa) {
            kq = max(kq, max(a[i] + maxa,a[i]));
        }
        else {
            maxa = a[i];
            itmin = i;
        }
    }
    for (int i = itmin - 1; i>=0; i--) {
        mina = min(mina, a[i]);
    }
    cout << kq << " " << mina << endl;
    kq -= mina;
    cout << itmin << " " << maxa << " " << kq;
}
int main () {
    //freopen("DP_A3.INP","r",stdin);
    //freopen("DP_A3.OUT","w",stdout);
    iam;
    Solve();
}
