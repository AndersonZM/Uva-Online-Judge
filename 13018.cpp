//Accept 03/09/2016
//Anderson
#include <iostream>

using namespace std;

int main(){
    int dado1, dado2;
    int i, j, menor, n;
    bool first = true;
    
    while(cin >> dado1 >> dado2){
        if (first) first = false;
        else {
            cout << endl; 
        }
        if(dado1 < dado2){
            int aux = dado1;
            dado1 = dado2;
            dado2 = aux;
        }
        n = dado1 - dado2 + 1;
        for(i=(dado2+1); i<(dado2+1+n);++i) {
            cout<<i<<endl;
        }
    }
    return 0;
}
