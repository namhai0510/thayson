#include<bits/stdc++.h>

using namespace std;
const int maxn=3e4+5;
const int oo = INT_MAX/2;
long long f[maxn], a[maxn], Truoc[maxn], b[maxn];
int n, res=0;

int max(int a, int b) {
    if (a > b) return a;
        else return b;
}

void Nhap() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
}

bool TieuChiSoSanh(int cdb, int cdk) {
    if (a[cdb] < a[b[n+1]]) return true;
        else return false;
}

void Solve() {

    for (int i = 1; i <= n; i++)
        b[i] = +oo;
    b[0] = -1;
    for (int i = 1; i <= n; i++) {
        b[n+1] = i;
        int vt = lower_bound(b+1, b+n+1, i, TieuChiSoSanh) - b;
        f[i] = vt;
        b[vt] = i;
        Truoc[i] = b[vt - 1];
    }

}

void TruyVet(int i) {
    if (Truoc[i] == -1) cout << a[i];
        else {
            TruyVet(Truoc[i]);
            cout << " " << a[i];
        }
}

void InKQ() {
    int k;
    for (int i=1; i<=n; i++){
        ///res=max(res, f[i]);
        if (res < f[i]) {
            k = i;
            res = f[i];
        }
    }
    cout << res << endl;
    ///TruyVet(k);

    int m = res;
    int ma = +oo;

    /*
    vector<int> T;
    for (int i = n; i >= 1; i--)
        if (f[i] == m)
            if (a[i] < ma) {
                T.push_back(a[i]);
                m--;
                ma = a[i];
            }

    for (int i = T.size() - 1; i >= 0; i--)
        cout << T[i] << " ";
    */
}

int main(){
    Nhap();
    Solve();
    InKQ();
    return 0;
}
