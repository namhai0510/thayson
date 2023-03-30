#include<bits/stdc++.h>

using namespace std;

long long a[3];

long long nhan(long long a, long long b, long long mod){
    if (b==0) return 0;
    long long t=nhan(a, b/2, mod);
    t=(t+t)%mod;
    if (b%2!=0) t=((t+a)%mod + mod)%mod;
    return t;
}

int main(){
    freopen("MAXPRO.INP", "r", stdin);
    freopen("MAXPRO.OUT", "w", stdout);
    for (int i=0; i<3; i++) cin >> a[i];
    long long m;
    cin >> m;
    sort (a, a+3);
    if (a[1]>=0) cout << nhan(a[1], a[2], m);
    else cout << nhan(a[0], a[1], m);
}