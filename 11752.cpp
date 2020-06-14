//Anderson Zudio
//Bruno Masquio
//Giancarlo Fran�a
//Raquel Marcolino
//AC em 05/08/2014
//C++11

#include <iostream>
#include <set>
#include <cmath>

#define BIT 64


using namespace std;

set<unsigned long long, less<unsigned long long> > myset; //Set com ordena��o come�ando pelo menor n�mero

/*Para resolver este problema basta achar todos os n�meros que tenham como base um inteiro elevado a um outro inteiro n�o primo.
Nesta implementa��o foi usado um set, o set � um container que permite que a inser��o seja ordenada e os elementos sejam �nicos.*/


//Pow da biblioteca cmath do C++11 retorna double e tem como entrada a base sendo double e o expoente tamb�m.
//Como estamos lidando com n�meros muito grandes (extamente o tamanho de unsigned l l), a melhor op��o foi usar um pow pr�prio
unsigned long long ipow( unsigned long long base, unsigned long long expo )
{
    unsigned long long oi, resp=1;
    for(oi = 0; oi < expo; oi++)
            resp*=base;

    return resp;
}

bool TestaPrimo (int q)
{    int rq;   bool primo=true;
     rq = sqrt(q);
     for (int i=2; i<=rq; i++)
         if ((q % i) == 0)
         {   primo = false;
             break;
         }
     return (primo);
}


int main() {

	unsigned long long i,j,power, powerbase;
	powerbase=2;
	myset.insert(1); //Set permite inser��o ordenada e com elementos �nicos

	while(powerbase < 65537){ //Aqui o loop foi superestimado, pouca perda de desempenho pois para i = 2 o valor de power chega no m�ximo a 63. i = 3, power = 40 e para cada incremento em i o valor de power desce muito at� chegar em 0.
		power = ceil(BIT  / (log(powerbase)/log(2)));//Aqui � calculado o expoente m�ximo
		for(i = power; i>0; i--){
			if(!TestaPrimo(i)){ //Teste de primalidade, se o expoente � primo, n�o tentar inserir no set

				unsigned long long x = ipow(powerbase, i);

				if(64*log(2) > i*log(powerbase)) myset.insert(x); //Para casos que estouram 2^64-1
			}
		}
		powerbase++;
	}

	//Set j� est� ordenado pela fun��o less<unsigned long long>
	for(auto k = myset.begin(); k!= myset.end(); k++){
		cout << *k << endl;
	}

	return 0;
}
