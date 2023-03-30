#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXW = 200001;

int n, W, S;
int F[MAXW];
int a[MAXN]; ///, b[MAXW]; ///,cnt[MAXN];
bool Phan2[MAXN];

void Nhap()
{
    cin >> n;/// >> S; /// W;
    S = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S = S + a[i];
    }
        
    W = S;
}

void QHD()
{
    memset(F, -1, sizeof(F));
    F[0] = 0;

    long long tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong = tong + a[i];
        for (int j = min(tong, (long long) S); j >= 1; j--)
        ///for (int j = 1; j <= min(tong, (long long) S); j++)
        {
            if (a[i] <= j)
                if (F[j] == -1) /// Tai sao phai can dieu kien nay de hieu qua hon khi Truy vet
                    if (F[j - a[i]] > -1)
                        F[j] = i;
        }
    }
}

void TruyVet(int j)
{
    if (j == 0)
        return;

    TruyVet(j - a[F[j]]);
    ///cout << a[F[j]] << " ";
    Phan2[F[j]] = false;
}

void InKQ()
{
    long long T1;
    for (int j = S/2; j >= 0; j--)
        if (F[j] > -1) {
            T1 = j;
            break;
        }
    cout << S - 2*T1 << endl;
    memset(Phan2, true, sizeof(Phan2));
    TruyVet(T1);
    for (int i = 1; i <= n; i++) 
        if (Phan2[i] == false) cout << i << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) 
        if (Phan2[i] == true) cout << i << " "; 
}

int main()
{
  
        Nhap();
        QHD();
        InKQ();
}