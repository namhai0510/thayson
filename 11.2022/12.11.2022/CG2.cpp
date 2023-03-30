#include<bits/stdc++.h>

using namespace std;

const double epsilon = 0.001;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("CG2.inp", "r", stdin);
    freopen("CG2.out", "w", stdout);
    long long n;
    cin >> n;
    long long dem=0;
    /*for (long long i=1; i*(i+1)<2*n; i++){
        long double d=(1.00*n-i*(i+1)/2)/(i+1);
        if (d-(int)d==0.00) dem++;
        ///if (d-(int)d < epsilon) dem++;
    }*/
    long long k=sqrt(2*n);
    for (long long x=2;x<=k;x++) {
        if ((2*n)%x==0) {
            long long y=(2*n)/x;
            if (abs(y - x)%2 == 1) {
                    dem++;
                    long long a = (y - x - 1)/2;
                    ///cout << x <<  " " << a+1 << endl;
            }
        }
    }
    cout << dem;
}
