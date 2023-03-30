#include<bits/stdc++.h>

using namespace std;
const int maxn=3e4+5;
const int oo = INT_MAX/2;
long long f[maxn], a[maxn], Truoc[maxn], v[maxn];
int n, res=0;

int max(int a, int b) {
    if (a > b) return a;
        else return b;
}

void Nhap() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i] >> b[i];
}

void SapXep() {
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
}

void Solve() {
    for (int i = 1; i <= n; i++)
        v[i] = +oo;
    for (int i = 1; i <= n; i++) {
        int vt = lower_bound(v+1, v+n+1, a[i]) - v;
        f[i] = vt;
        v[vt] = a[i]; 
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
    SapXep();
    Solve();
    InKQ();
    return 0;
}