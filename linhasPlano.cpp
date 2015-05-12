/*
	Matheus Machado dos Santos 102449
*/

#include<cstdio>

/*
	Deducao da recursao:

   O numero maximo de regioes delimitado
por um determinado numero de retas é
alcancado quando nenhuma reta e paralela.
   Uma nova reta concorrente sempre
corta todas as retas existentes
 (definicao de reta concorrente).
   A adicao da reta n, divide as
 as n+1 regioes delimitadas
pelas n-1 retas cortadas.
   O numero maximo de regioes
delimitadas por n retas, e o
numero maximo de regioes delimitada
por n-1 retas mais o numero de
regioes divididas pela reta n
( n-1 retas = n+1 regios = n novas
regioes).

  1  2  3
  |  |  | 
-------------- 4
  |  |  |

   Entao, N(k) e o numero maximo de
 regioes delimitadas por k retas.

   N(0) = 1 regiao (base)
   N(k) = N(k-1) + k 

*/


int maximoRegioes(int nRetas)
{
	if(nRetas == 0)		// O(1)
		return 1;
	else return maximoRegioes(nRetas -1) + nRetas; // T(n-1)

/*
	Análise

	T(1) = 1
	T(n) = T(n-1) + 1

	Não aplica o método mestre!


	T(n) = T(n-1) + 1
	T(n-1) = T(n-2) + 2
	T(n-2) = T(n-3) + 3
	...
	T(n-k) = T(n-(k+1)) + (k+1)
	...
	T(1) = T(1) + k+1

	Qual valor de k, pra chegar em T(1) ??
	n-k = 1
	Quando k = n-1 !

	Então: T(n) = 1 + n-1

	T(n) = 1 + n -1
	T(n) = n

	Prova:

	Base:
		T(1) = 1 .: T(n) = n -> T(1) = 1 OK!

	Indução:	
		T(n) = T(n-1) + 1
	Substituindo a hipotese:
		T(n) = (n-1) + 1
		T(n) = n   OK !

	f(n) = O(n)
*/
}

int main()
{
	int i;

	for( i = 0 ; i < 10; i++) // 11
		printf("MaxRegioes %d retas = %d\n", i, maximoRegioes(i)); // O(n) * 10
	return 0;
}

/*
	Matheus Machado dos Santos 102449
*/

