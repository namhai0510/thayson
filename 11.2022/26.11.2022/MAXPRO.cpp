#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("MAXPRO.INP", "r", stdin);
    freopen("MAXPRO.OUT", "w", stdout);
    
    long long a[3];
    vector<long long> x;
    long long m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    a[0]=a[0]%m;
    a[1]=a[1]%m;
    a[2]=a[2]%m;
    x.push_back(abs(a[0]*a[2])%m);
    x.push_back(abs(a[0]*a[1])%m);
    x.push_back(abs(a[1]*a[2])%m);
    sort(x.begin(),x.end());
    cout << x[x.size()-1];
}