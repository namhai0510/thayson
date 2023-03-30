#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL);
const long long maxn=1e6+5;
int t,n,S;
vector<int> a(maxn);
vector<bool> f(maxn);

void Solve() {
    cin >> t;
    while (t--) {
        a.clear(); f.clear();
        cin >> n >> S;
        for (int i = 1; i <= n; i++) cin >> a[i];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = S; j >= a[i]; j--) {
                if (f[j] == 0 || f[j - a[i]] == 1) f[i] = 1;
            }
        }
        if (f[S] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main() {
    iam;
    Solve();
}
