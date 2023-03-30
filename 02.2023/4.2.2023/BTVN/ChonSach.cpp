#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define fi first
#define se second
const int maxn = 1e6+5;
ll n,kq = 0;
pair<ll,ll> a[maxn];
ll vitri[maxn];
void Solve() {
    vitri[0] = 0;
    for (int i = 1; i <= maxn; ++i) vitri[i] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pair<ll,ll> t;
        t.first = 0;
        t.second = a[i].second;
        ll it = upper_bound(a + i, a + 1 + n, t) - a;
        if (it <= n && vitri[i] == 1) {
            vitri[it] = vitri[i] + 1;
            kq = max(kq,vitri[it]);
            //cout << vitri[it] << endl;
        }
        vitri[i] = 0;
        //cout << it << endl;
        cout << kq << " " << it << " " << i << endl;
    }
    cout << kq;
}

int main () {
    iam;
    Solve();
}
