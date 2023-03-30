#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

string f[maxn][maxn];

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