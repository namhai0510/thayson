#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
const int maxn=1e5+5;
ll n;
vector<pair<ll,ll> > a;
int it=0;
ll S = 0;
void Solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        ll b; cin >> b;
        a.push_back(make_pair(b,i));
    }
    sort(a.begin(),a.end());
    for (int i=0; i<n; i++) {

    }
}
int main () {
    freopen("DP_A6.INP","r",stdin);
    freopen("DP_A6.OUT","w",stdout);
    iam;
    Solve();
}
