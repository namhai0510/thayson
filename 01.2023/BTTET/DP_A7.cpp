#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
const int maxn=1e3+5;
ull t = 18446744073709551615;
ll it = 0;
string A,B;
ll dema=0,demb=0;
void Solve() {
    cin >> A >> B;
    for (int i = 0; i < A.size(); i++) {
        if (B.find(A[i])<t && B.find(A[i])>=it) {
            it = B.find(A[i]) + 1;
            dema++;
            //cout << it << " ";
        }
    }
    it = 0;
    for (int i = 0; i < B.size(); i++) {
        if (A.find(B[i])<t && A.find(B[i])>=it) {
            it = A.find(B[i]) + 1;
            demb++;
        }
    }
    cout << max(dema,demb);
}
int main () {
    freopen("DP_A7.INP","r",stdin);
    freopen("DP_A7.OUT","w",stdout);
    iam;
    Solve();
}
