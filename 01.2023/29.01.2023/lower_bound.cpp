#include<bits/stdc++.h>

using namespace std;
const int maxn=3e4+5;
const int oo = INT_MAX/2;
long long f[maxn], Truoc[maxn], b[maxn];
long long a[maxn] = {-1, 1, 3, 5, 9, 10, 15};
                    ///  1  2  3  4   5   6
int n, res=0;



int main(){
    n = 6;
    cout << lower_bound(a + 1, a + n + 1, 16) - a;
    return 0;
}
