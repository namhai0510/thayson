#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
const int maxn=1e6+5;
int n,m;
ll s, a[maxn], dem=0;
bool b[maxn];

int binarysearch (ll x) {
    ll l=1,r=m*n;
    while (l<=r) {
        ll k=(l+r)/2;
        if (a[k]==x) {
            return k;
        }
        else if (a[k]<x) { /// a[l] <= a[k] < x <= a[r]
            l=k+1;
        }
        else { /// a[l] <= x < a[k] <= a[r]
            r=k-1;
        }
    }
    return -1;
}

void Solve () {
    cin >> n >> m >> s;
    for (int i=1;i<=n*m;i++) {
        cin >> a[i];
    }

    sort(a+1,a+1+n*m);

    memset(b, true, sizeof(b));
    for (int i=1;i<=n*m;i++) {
        int it=binarysearch(s-a[i]);
        //cout << it << endl;
        bool ok=true;
        if (it!=-1) {
            dem++;
            int x = it+1;
            while (x <= m*n && a[x] == s - a[i]) {
                dem++;
                x++;

            }
            int y = it-1;
            while (0 <= y && a[y] == s - a[i]) {
                dem++;
                y--;
            }
            /*
            while (ok==true) {
                int i=1,j=1;
                if (a[it+i]==s-a[i]) {
                    dem++;
                    i++;

                }
                else if (a[it-j]==s-a[i]) {
                    j++;
                    dem++;
                }
                else break;
            }
            */
        }
    }
    cout << dem/2;
}
int main () {
    iam;
    Solve();
}
