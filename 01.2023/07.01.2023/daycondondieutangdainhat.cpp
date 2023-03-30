#include<bits/stdc++.h>

using namespace std;
const int maxn=1e4+5;
long long f[maxn], a[maxn], Truoc[maxn];
int n, res=0;

int max(int a, int b) {
    if (a > b) return a;
        else return b;
}

void Nhap() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
}

void QHD() {
    f[1] = 1;
    Truoc[1] = -1;

    for (int i=2; i<=n; i++){
        f[i] = 1;
        Truoc[i] = -1;
        for (int j=1; j<=i-1; j++){
            if (a[j]<a[i]){
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
    TruyVet(k);
}

int main(){
    Nhap();
    QHD();
    InKQ();
    return 0;
}