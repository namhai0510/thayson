#include<bits/stdc++.h>

using namespace std;

const int maxn=100;

string fib[101];

string Cong (string solon1, string solon2) {
    while (solon1.size()<solon2.size()) solon1="0"+solon1;
    while (solon2.size()<solon1.size()) solon2="0"+solon2;

    int tong;
    int nho=0;
    string res = "";
    for (int i=solon1.size()-1; i>=0; i--){
        tong=(solon1[i]-'0') + (solon2[i]-'0')+nho;
        if (tong>=10) {
            nho=tong/10;
            tong=tong%10;
        }
        else nho = 0;
        res=to_string(tong)+res;
    }
    if (nho>0) res="1"+res;
    return res;
}

int main () {
    fib[1]="1";
    fib[2]="2";
    for (int i=3;i<=maxn;i++) {
        fib[i]=Cong(fib[i-1],fib[i-2]);
    }
    int t,n;
    cin >> t;
    for (int i=1;i<=t;i++) {
        cin >> n;
        cout << fib[n] << endl;
    }
        
    cout << fib[100] << endl << fib[100].size() << endl;
}
