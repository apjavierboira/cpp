#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,q;
    int question;
    long long c1,c2,c3,d1;

    cin >> n >> q;
    vector<long long> v(n+1);
    vector<long long> respuesta(n+1);
 
    for (long long i=1;i<=n;i++){
        cin >> v[i];
    }

    int r=0;
    for (long long j=0;j<q;j++){
        cin >> question;
        if(question==1){
            cin >> c1 >> c2 >> c3;
            for (int l=c1;l<=c2;l++){v[l]+=c3;};
        }else if(question==2){
            cin >> d1;
            respuesta[r]=v[d1];
            r=r+1;
        }
    }
    for (long long p=0;p<r;p++){
        cout << respuesta[p] << "\n";
    }
    return 0;
}



