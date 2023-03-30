#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
long long f1[maxn], f2[maxn], a[maxn], Truoc1[maxn], Truoc2[maxn];
long long n, res1 = 0, res2 = 0;

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    else
        return b;
}

void Nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void QHD()
{
    f1[1] = 1;
    f2[1] = 1;
    Truoc1[1] = -1;
    Truoc2[1] = -1;
    for (int i = 2; i <= n; i++)
    {
        f1[i] = 1;
        f2[i] = 1;
        Truoc1[i] = -1, Truoc2[i] = -1;
        for (int j = 1; j <= i - 1; j++)
        {
            if (a[j] < a[i])
            {
                /// f1[i] = max(f1[i], f2[j] + 1);
                if (f1[i] < f2[j] + 1)
                {
                    f1[i] = f2[j] + 1;
                    Truoc1[i] = j;
                }
            }
            else if (a[j] > a[i])
            {
                if (f2[i] < f1[j] + 1)
                {
                    f2[i] = f1[j] + 1;
                    Truoc2[i] = j;
                }
            }
        }
    }
}

void TruyVet2(int i);

void TruyVet1(int i)
{
    if (Truoc1[i] == -1)
        cout << a[i];
    else
    {
        TruyVet2(Truoc1[i]);
        cout << " " << a[i];
    }
}

void TruyVet2(int i)
{
    if (Truoc2[i] == -1)
        cout << a[i];
    else
    {
        TruyVet1(Truoc2[i]);
        cout << " " << a[i];
    }
}

void InKQ()
{
    int k1, k2;
    for (int i = 1; i <= n; i++)
    {
        /// res1 = max(f1[i], res1);
        /// res2 = max(f2[i], res2);
        if (res1 < f1[i])
        {
            res1 = f1[i];
            k1 = i;
        }
        if (res2 < f2[i])
        {
            res2 = f2[i];
            k2 = i;
        }
    }
    cout << max(res1, res2) << endl;
    if (res1 > res2)
        TruyVet1(k1);
    else
        TruyVet2(k2);
}

int main()
{
    Nhap();
    QHD();
    InKQ();
    return 0;
}