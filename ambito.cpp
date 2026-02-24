#include <iostream>
using namespace std;

int b=0;
int SumaUno(int *a){
    *a=*a+1;
    b=7;
    return *a;
}

int main (){
    int u,v,a;
    cin >> u;
    v=SumaUno(&u);
    cout<< "u: "<<u<<" v:"<<v<<" a:"<<a<<" b:"<<b;
}