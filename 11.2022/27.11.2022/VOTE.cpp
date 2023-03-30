#include<bits/stdc++.h>

using namespace std;

const int maxn=5005;
char a[maxn][maxn];
int dem[maxn];
int main(){
    freopen("VOTE.INP", "r", stdin);
    freopen("VOTE.OUT", "w", stdout);
    int n; cin >> n;
    for (int j=0; j<n; j++){
        dem[j]=0;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j]=='X') dem[j]+=1;
        }
    }
    int maxaj = -1;
    for (int j = 0; j < n; j++)
        if (maxaj < dem[j])
            maxaj = dem[j];
    int soluong = 0;
    vector<int> ds;
    for (int j = 0; j < n; j++) 
        if (dem[j] == maxaj) {
            soluong++;
            ds.push_back(j);
        }
    cout << soluong << " " << maxaj << endl;
    for (int i=0; i<ds.size(); i++) cout << ds[i]+1 << " ";
}