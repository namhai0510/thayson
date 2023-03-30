#include<iostream>
#include<string>
using namespace std;

int main () {
    int N;
    cin >> N;
    cout << N << endl;
    string S[N+1];
    /*for (int i=1; i<=N; i++){ cin >> S[i];
    cout << S[i];
    }*/
    bool ok[N+1];
    string A;
    memset(ok, false, sizeof(ok));
    ok[0]=true;
    for (int i=1;i<=N;i++) {
        cin >> S[i];
        cout << S[i] << " ";
    }

    cout << "Xong 1" << endl;

    for (int i=1; i<=N-1; i++){
        cin >> A;
        for (int j=1;j<=N;j++) {
            if (A==S[j]) ok[j]=true;
        }
    }

    cout << "Xong 2" << endl;

    for (int i=1;i<=N;i++) {
        if (ok[i]==false) cout << S[i];
    }

    cout << "Xong 3" << endl;
}

