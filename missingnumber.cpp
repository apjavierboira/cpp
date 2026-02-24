#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long num;
    cin >> num;
    long set[num], entrada;
    for (int i=0; i<num-1; i++){
        cin>> entrada;
        set[entrada-1]=1;
    }
    int i=0;
    while (set[i]==1){i++;}
    cout << i+1;
}