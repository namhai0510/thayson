#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1];
    for (int i=1; i<=n; i++){
         cin >> a[i];
    }
    sort (a+1, a+1+n);
    cout << max(a[1]*a[2]*a[n], a[n-2]*a[n-1]*a[n]);
}