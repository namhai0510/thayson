#include <bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
const int maxn=1e6;
ll maxa=1e9+7;
map<ll,ll> a;
ll t[maxn];
ll m,n,s;
ll dem=0;

void Solve() {
    cin >> m >> n >> s;
    for (ll i=0;i<m*n;i++) {
        cin >> t[i];
        a[t[i]]++;
    }

    for (pair<ll,ll> k:a) {
        ll x = k.first;
        ll y = s-k.first;

        if (a[x] > 0 && a[y] > 0) {
            cout << x << " " << a[x] << " " << y << " " << a[y] << endl;
            if (x != y) dem = (dem + a[x]*a[y])%maxa;
                else /// x == y
                    dem = (dem + a[x]*(a[x] - 1)/2)%maxa;
            a.erase(y);
        }

    }
    cout << dem;
}
int main () {
    iam;
    Solve();
}
