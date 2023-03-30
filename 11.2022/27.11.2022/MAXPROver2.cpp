#include<bits/stdc++.h>

using namespace std;

const long long maxn=1e18+5;
int a[4];
int main(){
    freopen("MAXPRO.INP", "r", stdin);
    freopen("MAXPRO.OUT", "w", stdout);
    for (int i=0; i<3; i++) cin >> a[i];
    int m;
    cin >> m;
    sort (a, a+3);
    long long maxn=max(a[0]*a[1], a[1]*a[2]);
    cout << maxn%m;
}