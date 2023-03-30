#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ll long long
const int maxn = 1e6 + 5;
ll n, ketqua[maxn];
struct Babylon {
    ll x,y,z;
};
Babylon Block[maxn];
void Solve() {
    while (1) {
        cin >> n;
        if (n == 0) return;
        for (int i = 0; i < n; ++i) {
            ll a,b,c; cin >> a >> b >> c;
            Block[3*i].x = a; Block[3*i].y = b; Block[3*i].z = c;
            Block[3*i + 1].x = b; Block[3*i + 1].y = c; Block[3*i + 1].z = a;
            Block[3*i + 2].x = c; Block[3*i + 2].y = a; Block[3*i + 2].z = b;
        }
        for (int i =0; i < 3*n; ++i) {
            for (int j = i + 1; j < 3*n; ++j) {
                if ((Block[i].x > Block[j].x && Block[i].y > Block[j].y) || (Block[i].x > Block[j].y && Block[i].y > Block[j].x)) {
                    swap(Block[i].x,Block[j].x);
                    swap(Block[i].y,Block[j].y);
                    swap(Block[i].z,Block[j].z);
                }
            }
        }
        for (int i = 0; i < 3*n; ++i) {
            ketqua[i] = Block[i].z;
            for (int j = 0; j < i; ++j) {
                if ((Block[i].x > Block[j].x && Block[i].y > Block[j].y) || (Block[i].x > Block[j].y && Block[i].y > Block[j].x)) {
                    ketqua[i] = max(ketqua[i],Block[i].z + ketqua[j]);
                }
            }
        }
        ll ans = LLONG_MIN/2;
        for (int i = 0; i < 3*n; ++i) ans = max(ans, ketqua[i]);
        cout << ans << endl;
    }
}
int main () {
    iam;
    Solve();
}
