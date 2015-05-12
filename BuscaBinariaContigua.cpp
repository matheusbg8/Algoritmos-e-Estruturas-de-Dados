/*
	Matheus Machado dos Santos 102449
*/
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

typedef struct
{
	string nome;
	int valor;
}Registro;

// Funcao que compra 2 registross (usado para ordenar)
bool comp (const Registro &a, const Registro &b)
{
	return (a.nome <b.nome);
}

int busca(Registro *rs, const string &nome, int i, int f)
{
	int m = (i+f)/2;				// O(1)  pega o meio
	if(rs[m].nome == nome)			// O(1)  compara se encontrou
		return rs[m].valor;
	else if(nome > rs[m].nome)				// O(1)
		return busca( rs, nome,  m+1, f);	
	else
		return busca( rs, nome, i, m-1); 	// T( n/2 )

/*
	T(n) = T(n/2) + 3

	Análise pelo método mestre:
	a = 1 ,  b = 2  , f(n) = 3 .: f(n) = c

	n^( log(a)_b )  ->  3
	n^( log(1)_2 )  ->  3

	n^ (k<1) > 3

	Caso 1:

	n^ (k<1)  > 3

	n^ (k<1) - e >= 3
	
	O ( n log n) 

Análise Direta:
	
	Considerando n = 2^k

	Base: T(1) = 1
	
	T(n) = T(n/2) + 1


	T(n/2) = T(n/4) + 2
	T(n/4) = T(n/8) + 3
	T(n/2^k) = T(n/2^k) + k
	...
	T(1) = 1 + k

	Quando n/2^k = 1 ? Quando n = 2^k !

	Pra que k ?
	n = 2^k
	log(n)_2 = k

	Então:

	T(n) = T(1) + log(n)_2
	T(n) = 1 + log(n)_2 , para n = 2^k .


	Prova para todo n, T(n) = 1 + log(n)_2 , por indução:

	Para base: 
		T(1) = 1 ,  T(1) = log(1)_2 + 1 = 0 + 1 = 1 OK!

	Para todo n, supondo T(n) = 1 + log(n)_2
		T(n) =  T(n/2) + 1

		Substituindo T(n/2) pela hipotese:
		T(n) = (log(n/2)_2 + 1) + 1
		T(n) = ( log(n)_2 - log(2)_2) + 2
		T(n) = log(n)_2 - 1 + 2
		T(n) = log(n)_2 + 1		OK !
*/

}

int main()
{
	Registro regs[] ={
		{ "Machado", 10 },
		{ "Monica", 16 },
		{ "Marta", 13 },
		{ "Itamar", 29 },
		{ "Marlete", 27 },
		{ "Vander", 30 },
		{ "Guilherme", 12 },
		{ "Fabio", 5 },
		{ "Thais", 8 },
		{ "Giovana", 1 },
		{ "Laura", 34 },
		{ "Luiza", 19 },
		{ "Mariele", 22 }
	};
	int n = 13;

	sort(regs , regs+13, comp);

	// Mostra que os registros foram ordenados
	for(int i = 0 ; i < 13; i++)
		printf("%d: %s %d\n", i, regs[i].nome.c_str(), regs[i].valor);
	printf("\n");

	printf("Busca(Machado) = %d\n", busca(regs,string("Machado"),0, n-1)); // O ( log n )
	printf("Busca(Guilherme) = %d\n", busca(regs,string("Guilherme"),0, n-1)); // O ( log n )
	printf("Busca(Laura) = %d\n", busca(regs,string("Laura"),0, n-1)); // O ( log n )
	printf("Busca(Mariele) = %d\n", busca(regs,string("Mariele"),0, n-1)); // O ( log n )
	printf("Busca(Vander) = %d\n", busca(regs,string("Vander"),0, n-1)); // O ( log n )

	return 0;
}

/*
	Matheus Machado dos Santos 102449
*/

