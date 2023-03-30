#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20001;
const int MAXW = 20001;

int n, W, S;
int F[MAXW];
int a[MAXN]; ///, b[MAXW]; ///,cnt[MAXN];

void Nhap()
{
    cin >> n >> S; /// W;
    W = S;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
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
                if (F[j - a[i]] > -1)
                    F[j] = i;
        }
    }
}
/*
void TruyVet(int i, int j)
{
    if (i == 0)
        return;
    if (j == 0)
        return;

    ///... i > 0 and j > 0
    if (a[i] > j)
        TruyVet(i - 1, j);
    else
    { /// a[i] <= j
        if (F[i - 1][j - a[i]])
        {
            TruyVet(i - 1, j - a[i]);
            cout << a[i] << " ";
        }
        else
            TruyVet(i - 1, j);
    }
}
*/
void InKQ()
{
    /*
    cout << F[n][W] << endl;
    ///memset(cnt, 0, sizeof(cnt));
    if (F[n][W] == true)
        TruyVet(n, W);
    */
    if (F[S] > -1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Nhap();
        QHD();
        InKQ();
    }
}