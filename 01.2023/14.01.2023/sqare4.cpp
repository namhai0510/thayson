#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define fileio(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)

const int N = 1e6+11;
const i64 mod = 1e9+7;
int n, m, arr[N];
i64 s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // fileio("");

    map<int, int> f;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        f[arr[i]]++;
    }

    i64 res = 0;
    for (int i = 1; i <= n; i++) {
        int x = s-arr[i];
        res += (f[x]);

        if (arr[i] == x) {
            res=(res-1);
        }
    }
    cout << (res/2);

}
