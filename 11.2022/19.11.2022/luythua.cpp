#include<bits/stdc++.h>

using namespace std;

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
string luythua2(int n){
    string res="1";
    for (int i=1; i<=n; i++){
        res=Cong(res, res);
    }
    return res;
}

int main(){
    int n; cin >> n;
    string kq = luythua2(n);
    cout << kq << endl << kq.size() << endl;
}