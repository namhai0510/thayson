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
    if (a[cdb] < a[cdk]) return true;
        else return false;
}

void Solve() {
    for (int i = 1; i <= n; i++)
        f[i] = +oo;

    int j;
    f[1] = 1;
    cout << " ";
    for (int i = 2; i <= n; i++) {
        cout << endl << "F " << i-1 << ": " << f[i-1] << endl;

        int vt = lower_bound(f+1, f+(i-1)+1, i, TieuChiSoSanh) - f;
        cout << " " << vt;
        /// j can tim se la: j = vt - 1
        if (vt != i && vt > 1) {
            j = vt - 1;
            f[i] = max(f[i-1], f[j] + 1);
        }
        else f[i] = f[i-1];
    }
    cout << endl;
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
