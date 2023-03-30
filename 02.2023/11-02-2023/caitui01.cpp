#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int maxw = 1e3 + 5;
int n,w,n2,w2;
int a[maxn];
double b[maxn];
double F[maxn][maxw];


void Nhap() {
    cin >> n >> w;
    n2 = n; w2 = w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
}

void QHD() {
    memset(F, 0, sizeof(F));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i] > j) F[i][j] = F[i - 1][j];
            else { /// a[i] <= j
                F[i][j] = max(F[i-1][j], b[i] + F[i-1][j - a[i]]);
            }
        }
    }

}

/// BTVN: Sua lai phan TruyVet nay
void TruyVet() {
    vector<int> tv;
    while (n2 != 0 && w2 != 0) {
        if (a[n2] > w2) n2--;
        else { /// a[n2] <= w2
            if (F[n2][w2] != F[n2 - 1][w2]) {
                tv.push_back(n2);
                w2 -= a[n2];
            }
            n2--;           
        }
    }
    for (int i = tv.size() - 1; i >= 0; i--) cout << tv[i] << " ";
}

void TruyVet2(int i, int j) {
    if (i == 0) return;
    if (j == 0) return;

    /// i > 0 and j > 0

    if (a[i] > j) TruyVet2(i-1, j);
        else { /// a[i] <= j
            if (F[i][j] == b[i] + F[i-1][j - a[i]]) {
                TruyVet2(i-1, j - a[i]);
                cout << i << " ";
            }
            else TruyVet2(i-1, j);
        }
}

void InKQ() {
    cout << F[n][w] << endl;
    ///TruyVet2(n, w);
}

int main() {
    Nhap();
    QHD();
    InKQ();
}