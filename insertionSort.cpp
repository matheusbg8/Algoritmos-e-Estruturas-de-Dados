/*
	Matheus Machado dos Santos 102449
*/
#include<cstdio>

using namespace std;

void insertionSort(int *v, int n)
{
	int i, j, s;

	for(i = 0 ; i < n; i++)	// n+1
	{ // i divide entre ordenados (<<) e n ordenados (>>)
		s = v[i]; // i e o selecionado	// n

		j =i-1;							// n
		while( j >= 0 && s < v[j]) // (n^2)/2 + 1
		{
		 // Desloca os elementos ja ordenados
		 // ate encontrar a posicao correta 
		 // para inserir s
			v[j+1] = v[j];  // 0 + 1 + 2 + ... + n = (0 + n)*n/2 = (n^2)/ 2  = n^2
			j--;			// n^2
		}
		// Insere s na posicao correta
		v[j+1] = s;		// n
	}

	/*
		Análise Final:
		O(n) >= g(n)

		f(n) = (n+1) + 2*n + 2*(n^2)/2 + n
		f(n) = n^2 + 4n + 1

		n^2 + 4n + 1 >= C*n^2 ,

		Para n0 >= 1 e C = 6
		1^2 + 4 + 1 >= 6 *1^2
		6 >= 6

		f(n) = O(n^2) , n0>=1 e C = 6
	*/
}

int main()
{
	int i,
        v[10] = { 5, 3 , 7 , 2 , 1 , 10 , 4, 11, 9, 8 };

	insertionSort(v, 10); // O(n^2)

	for(i = 0 ; i < 10 ; i++)
		printf("%d " , v[i]);
	printf("\n");

	return 0;	
}

/*
	Matheus Machado dos Santos 102449
*/

