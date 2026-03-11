#include <iostream>// vamos a usar cin, cout, cin.peek(), cin.ignore()
#include <vector>  // vamos a usar vectores tipo vector<int> y vector<string>
#include <string>  // vamos a usar getline(cin,linea)
#include <sstream> // vamos a usar istringstream ss(linea)
using namespace std;

int racha(vector<int> &a, int largo);
void PideRachas(int N, vector<string> &v);

int main(){
    int N,a,resultado;
    string R;               ///------------------------usamos string
    vector<int> arr;        ///------------------------usamos vector
    vector<string> rachas; 
    cout << "cuantas rachas?";
    cin >> N;
    PideRachas(N,rachas);

    for(int i=0; i<N;i++){
        istringstream ss(rachas[i]);  // convierte el string en un "stream"
        arr.clear();
        while(ss >> a){arr.push_back(a);}
        if (arr.size()>0){
            resultado=racha(arr, arr.size());
            cout << resultado <<" ";
        } else {cout << "0 ";}
    }
}

int racha(vector<int> &a, int largo){
    if (largo<1){return 0;};
    int MejorRacha=a[0];
    int suma=a[0];
    for(int i=1; i<largo; i++){
        if(suma+a[i]<a[i]){
            suma=a[i];  
        }else{
            suma+=a[i];
        }
        if(suma>MejorRacha){MejorRacha=suma;}  
    }
    return MejorRacha;

}

void PideRachas(int N, vector<string> &v){
    string R;
    while (cin.peek()=='\n'){cin.ignore();}
    for(int k=0;k<N;k++){
            getline(cin, R);
            v.push_back(R);
    }
}