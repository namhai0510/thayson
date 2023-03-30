#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,l,U,res=0;
int a[maxn],L[maxn],P[maxn];
void Nhap() {
    cin >> n >> l >> U;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
}
void QHD () {
    L[0]=1;P[0]=1;
    for (int i=1;i<n;i++) {
        L[i]=1; P[i]=1;
        for (int j=0;j<i-l;j++) {
            if (a[j]-U<=a[j]) L[i]=max(1,P[j]+1);
            if (a[i]-a[j]<=U) P[i]=max(1,L[j]+1);
        }
    }
}
void Xuat () {
    for (int i=0; i<n; i++){
        res=max(res, (L[i]+P[i])/2);
    }
    cout << res;
}
int main () {
    Nhap();
    QHD();
    Xuat();
}
