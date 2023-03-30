#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i=1; i<=n; i++){
         cin >> a[i];
         b[i] = abs(a[i]);
    }
    sort (b+1, b+1+n);
    int s=b[n]*b[n-1]*b[n-2];
    int dau=1;
    for (int i=1; i<=n; i++){
        if ((abs(a[i])==b[n]) && a[i]<0) dau=-(dau);
        else if (abs(a[i])==b[n-1] && a[i]<0) dau=-(dau);
        else if (abs(a[i])==b[n-2] && a[i]<0) dau=-(dau);
    }
    cout << s*dau;
}