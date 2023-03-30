#include<bits/stdc++.h>

using namespace std;

int main () {
    freopen("AVR.inp", "r", stdin);
    freopen("AVR.out", "w", stdout);
    int n;
    cin >> n;
    long long a[n+1],b[n+1];
    long long S=0;
    a[0]=0;
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) {
        S+=a[i-1];
        a[i]=b[i]*i-S;
        //cout << a[i-1] << " " << b[i] << endl;
        cout << a[i] << " ";
    }
    //for (int i=0;i<n;i++) cout << a[i] << " ";
}
