#include <iostream>
#include <cmath>
using namespace std;

int main(){
    string cadena;
    cin>>cadena;
    long longitud, longitudmaxima;
    char adn;
    adn=cadena[0];
    longitud=1;
    longitudmaxima=1;
    for (int i=1; i<cadena.length(); i++){
        if(adn==cadena[i]){
            longitud++;
        } else {
            if (longitud>longitudmaxima){longitudmaxima=longitud;}
            longitud=1;
            adn=cadena[i];
        }
    }
    if (longitud>longitudmaxima){cout << longitud;}else{cout<<longitudmaxima;}
}