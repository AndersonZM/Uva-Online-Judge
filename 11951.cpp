//Anderson Zudio
//Victor Cracel Messner
//Julio Cesar
//AC em 28/04/2014

/* Problema �rea:
    Time Limit: 1 sec
    Solu��o O(n^4) n�o � viavel, � necess�ria uma solu��o com complexidade menor que isso ou Time Limit.
    O problema foi resolvido computando uma matriz com a soma em linha (pode ser implementado em coluna tamb�m) de todos os pre�os.
    Com esta nova matriz temos como computar o pre�o de uma submatriz de maneira mais eficiente, para calcular o pre�o de qualquer submatriz basta somar os valores na �ltima coluna:
    Por exemplo, o pre�o para a11 at� aij onde i = 3 e j = 3 pode ser obtido de a13 + a23 + a33.
    Caso eu queira o pre�o de uma submatriz dentro da matriz acima, basta diminuir os valores das primeiras linhas:
    Por exemplo, o pre�o para a12 at� aij onde i =3 e j= 3 pode ser obtida de a23 + a33. Utilizando a �rea computada no exemplo acima: (a13 + a23 + a33) - a13
                                                                                                                                        �rea anterior - a13
                                                                                                                                        basta computar a subtra��o de a13.
    Com isto a solu��o fica f�cil: basta subtrair o valor da soma at� achar algo menor ou igual ao or�amento da entrada e guardar a maior �rea.


    Exemplo pr�tico:
       Seja a entrada  1 2 3      matriz soma em linha:       1  3  6
                       4 5 6                                  4  9  15
                       7 8 9                                  7  15 24
                       Pre�o de a11 at� a33: 6 + 15 + 24 = 45              para a22 at� a33:  15 + 24  (anterior menos a primeira linha)
                                             (1+2+3 + 4+5+6 + 7+8+9)

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    //Declara��es
    int t, cont, S, P, n, m, K, i, j, k, l, Satual, Patual, g, h, M[110][110];
    cin >> t;
    cont = 0;
    while(t--)
    {

        cin >> n >> m >> K;

        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                cin >> M[i][j];


        //Guardando a matriz soma por linha.
        for(i = 1; i <= n; i++)
            for(j = 2; j <= m; j++)
                 M[i][j] += M[i][j-1];


        //Computando resposta:
        S = P = 0;
        for(j = 1; j <= m; j++)
        {

            //Para cada loop, retirar os valores da primeira coluna
            if(j > 1)
                for(g = 1; g <= n; g++)
                    for(h = j; h <= m; h++)
                        M[g][h] -= M[g][j-1];
            //Ap�s este loop, a coluna j atual foi eliminada do problema e j� foi computada

            //O inteiro k identifica a coluna do come�o da submatriz que est� sendo computada
            for(k = j; k <= m; k++)
            {
                Satual = Patual = 0;

                //O inteiro i identifica a linha do come�o da submatriz a ser computada
                for(i = 1, l = 1; i <= n; i++)
                {
                    //Adiciona o pre�o que est� armazena em aik, este pre�o cont�m o valor da linha toda at� a coluna k
                    Patual += M[i][k];
                    //Se este pre�o for maior do que meu or�amento, subtraia das primeiras linhas at� encaixar no meu or�amento
                    if(Patual > K)
                    {
                        while(Patual > K)
                        {
                            Patual -= M[l++][k];
                        }
                    }

                    //Calculando a �rea da minha submatriz que come�a em alj e termina em aik, atualiza a resposta se necess�rio
                    Satual = (i - l + 1)*(k - j + 1);
                    if(Satual > S)
                    {
                        S = Satual;
                        P = Patual;
                    }
                    else if(Satual == S)
                        if(Patual < P) P = Patual;
                }
            }

        }


        cout << "Case #" << ++cont << ": " << S << " " << P << endl;
    }
    return 0;
}
