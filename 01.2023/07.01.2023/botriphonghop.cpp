#include<bits/stdc++.h>

using namespace std;
const int maxn=1e4+5;
long long f[maxn], a[maxn], b[maxn], Truoc[maxn];
int n, res=0;

int max(int a, int b) {
    if (a > b) return a;
        else return b;
}

void Nhap() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i] >> b[i];
}

void QHD() {
    f[1] = 1;
    Truoc[1] = -1;

    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            ///if (a[i] > a[j]) {
                if (b[i] > b[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }

    for (int i=2; i<=n; i++){
        f[i] = 1;
        Truoc[i] = -1;
        for (int j=i-1; j>=1; j--){
            if (b[j]<=a[i]){
                ///f[i]=max(f[j]+1, f[i]);
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    Truoc[i] = j;
                }
            }
        }
    }

}

void TruyVet(int i) {
    if (Truoc[i] == -1) cout << a[i] << " " << b[i] << endl;
        else {
            TruyVet(Truoc[i]);
            cout << a[i] << " " << b[i] << endl;
        }
}

void InKQ() {
    int k;
    for (int i=n; i>=1; i--){
        ///res=max(res, f[i]);
        if (res < f[i]) {
            k = i;
            res = f[i];
        }
    }    
    cout << res << endl;
    TruyVet(k);
}

int main(){
    Nhap();
    QHD();
    InKQ();
    return 0;
}