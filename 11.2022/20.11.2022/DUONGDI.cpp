#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

string f[maxn][maxn];
string t="1";
string t2="0";
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
string Tru(string a, string b) {
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    int nho = 0;
    int hieu=0;
    string ketqua = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        hieu=(a[i]-48)-(b[i]-48)-nho;
        if (hieu<0) {
            hieu+=10;
            nho=1;
        }
        else {
            nho=0;
        }
        ketqua=(char)(hieu+'0')+ketqua;
    }
    if (ketqua.size()>1&&ketqua[0]=='0') {
        string T=ketqua.substr(1,ketqua.size()-1);
        return T;
    }
    return ketqua;

}
string C(string k, string n) {
    if (k == t2) return t;
    if (k == n) return t;
    if (k == t) return n;
    return Cong(C(Tru(k,t), Tru(n,t)),C(k, Tru(n,t)));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int k = 1; k <= n; k++) {
        f[1][k]= "1";
        f[k][1]= "1";
    }

    for (int i=2; i<= n; i++) {
        for (int j=2; j <= n; j++) {
            f[i][j]=Cong(f[i-1][j], f[i][j-1]);
        }
    }
    cout << f[n][n] << endl;
    cout << f[n][n].size() << endl;

}
