#include <iostream>// vamos a usar cin, cout, cin.peek(), cin.ignore()
#include <vector>  // vamos a usar vectores tipo vector<int> y vector<string>
#include <string>  // vamos a usar getline(cin,linea)
#include <sstream> // vamos a usar istringstream ss(linea)
using namespace std;

int racha(vector<int>& a, int largo);

int main(){
    int N,a,resultado;
    string R;               ///------------------------usamos string
    vector<int> arr;        ///------------------------usamos vector
    vector<string> rachas; 
    cout << "cuantas rachas?";
    cin >> N;
    while (cin.peek()=='\n'){cin.ignore();}
    for(int k=0;k<N;k++){
            getline(cin, R);
            rachas.push_back(R);
    }
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

int racha(vector<int>& a, int largo){
    int suma=0;
    for(int i=0; i<largo; i++){
        suma+=a[i];
    }
    return suma;

}