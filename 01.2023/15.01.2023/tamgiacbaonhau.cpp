#include<bits/stdc++.h>
using namespace std;
#define iam ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define second se;
#define first fi;

int n, res=-1;
const int maxn=1e4+5;
double espilon=0.0001;
long long F[maxn],Truoc[maxn];

struct tamgiac {
    int a1,a2,b1,b2,c1,c2;
    double dientich;
} pos[maxn];

bool xet(const tamgiac &x , const tamgiac &y) {
	return x.dientich<y.dientich;
}

bool Dnt (int it1, int it2, tamgiac D) {
    /*
    long long x1=(D.a1-D.b1),y1=(D.a2-D.b2),x2=(D.a1-D.c1),y2=(D.a2-D.c2);
    double S=abs(x1*y2-x2*y1)/2;
    double S1=abs((D.a1-it1)*(D.b2-it2)-(D.b1-it1)*(D.a2-it2))/2;
    double S2=abs((D.a1-it1)*(D.c2-it2)-(D.c1-it1)*(D.a2-it2))/2;
    double S3=abs((D.c1-it1)*(D.b2-it2)-(D.b1-it1)*(D.c2-it2))/2;
    */
    double S = D.dientich;
    double S1=abs((D.a1-it1)*(D.b2-it2)-(D.b1-it1)*(D.a2-it2))/2.0;
    double S2=abs((D.a1-it1)*(D.c2-it2)-(D.c1-it1)*(D.a2-it2))/2.0;
    double S3=abs((D.c1-it1)*(D.b2-it2)-(D.b1-it1)*(D.c2-it2))/2.0;
    if (abs(S-(S1+S2+S3))<espilon) return true;
    return false;
}

void Nhap () {
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> pos[i].a1 >> pos[i].a2 >> pos[i].b1 >> pos[i].b2 >> pos[i].c1 >> pos[i].c2;
        ///long long x1=(pos[i].a1-pos[i].b1),y1=(pos[i].a2-pos[i].b2),x2=(pos[i].a1-pos[i].c1),y2=(pos[i].a2-pos[i].c2);
        long long x1 = pos[i].b1 - pos[i].a1;
        long long y1 = pos[i].b2 - pos[i].a2;

        long long x2 = pos[i].c1 - pos[i].a1;
        long long y2 = pos[i].c2 - pos[i].a2;

        double S=abs(x1*y2-x2*y1)/2.0;
        pos[i].dientich=S;
    }
    
}

void QuyHoachDong () {
    sort (pos+1,pos+n+1,xet);

    F[0]=0;
    for (int i=1; i<=n; i++){
        F[i] = 1;
        for (int j=1; j<=i-1; j++){
            if (Dnt(pos[j].a1,pos[j].a2,pos[i])==true && Dnt(pos[j].b1,pos[j].b2,pos[i])==true && Dnt(pos[j].c1,pos[j].c2,pos[i])==true){
                ///f[i]=max(f[j]+1, f[i]);
                if (F[i] < F[j] + 1) {
                    F[i] = F[j] + 1;
                }
            }
        }
    }
}

void Xuat () {
    int k;
    for (int i=1; i<=n; i++){
        ///res=max(res, f[i]);
        if (res < F[i]) {
            k = i;
            res = F[i];
        }
    }
    cout << res;
}

void Dientich () {
    for (int i=1;i<=n;i++) {
        cout << pos[i].dientich << endl;
    }
}

int main () {
    iam;
    Nhap();
    QuyHoachDong();
    ///Dientich();
    Xuat();
}
