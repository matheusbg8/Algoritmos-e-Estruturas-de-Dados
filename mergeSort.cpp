/*
	Matheus Machado dos Santos - 102449
*/

#include<cstdio>

void merge(int *v, int t)
{
	int m = t/2, // Metade de v (div pilha i e j )
		tmp[t], // Resposta (temporaria)
		i=0, // Indice da pilha i
		j=m, // Indice da pilha j
		k=0; // Indice do vetor resposta

	// Escolhe os menores entre as 2 pilhas
	while( i < m && j < t)	// Pior caso , n vezes   O (n)
	{
		if(v[i] <= v[j])		// O(n)
			tmp[k] = v[i++];	// O(n)
		else tmp[k] = v[j++];	// O(n)
		k++;					// O(n)
	}

	// Pega o que sobra da pilha
	if(i == m) // pilha i acabo	// O ( 1 )
	{
		while(j < t) // copia resto pilha j	// pior caso, O(n/2)
			tmp[k++] = v[j++];		// O(n/2)
	}else // Pilha j acabo
	{
		while(i < m) // copia resto pilha i
			tmp[k++] = v[i++];
	}

	// Copia resposta pro vetor
	for(i = 0 ; i < t; i++)		// O(n)
		v[i] = tmp[i];			// O(n)

	/*
		Análise final:
		T(n) = 5*O(n) + O(1) + 2*O(n/2) + 2*O(n) =  O(n)
	*/
}

void mergeSort(int *v, int t)
{
	int m;
	if(t > 1)		// O(1)
	{
		// Divide
		m = t /2; // divide metade A e B	// O(1)
		mergeSort(v, m); // recursao A		// T(n/2)
		mergeSort(v+m, t-m); // recursao B	// T(n/2)

		// Conquista
		merge(v, t); // Combina v/2 com v/2	// O(n)
	}

	/*
		Análise final:
		T(n) = 2 * T(n/2) + O(n) + O(1).
		T(n) = 2 * T(n/2) + O(n)

		Método Mestre:
		a = 2;	b = 2;	f(n) = n

		n^log(2)_2 = n

		Como log(2)_2 = 1, n^(1) = n^(1)  (são iguais).

		Caso 2:
			T(n) = Theta ( n^( log(a)_b ) * log n )
			Para a >= 1 , b >= 1 e f(n) inteiro não negativo.

		Logo a complexidade é:
			T(n) = Theta ( n^( log(2)_2 ) * log n ) =
			T(n) = Theta ( n log n )
	*/
}

int main()
{
	int i,
        v[10] = { 5, 3 , 7 , 2 , 1 , 10 , 4, 11, 9, 8 };

	mergeSort(v, 10);	// Theta( n log n)

	for(i = 0 ; i < 10 ; i++)
		printf("%d " , v[i]);
	printf("\n");

	return 0;	
}


/*
	Matheus Machado dos Santos - 102449
*/
