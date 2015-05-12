
/*
	Matheus Machado dos Santos 102449
*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, minC;
vector<int> cicloH;
vector< pair<int, int> > g[20];

void imprimeV(vector<int> v)
{
	int i;
	for(i = 0 ; i < v.size(); i++)
	{
		printf("%d " , v[i]);
	}
	printf("\n");
}

/*
	Encontra uma aresta de u para v no grafo
	Retorna o custo da aresta ou -1 se ela não existir.

	Complexidade: O( N ).

*/
int custo(int u, int v)
{
	for(int i = 0 ; i < g[u].size() ; i++) // M(u)+1
		if(g[u][i].second == v)		// M(u)
			return g[u][i].first;	// M(u)

	return -1;
/*
	M(u) - Número de arestas adjacentes do vértice u .
	Complexidade M(u) + M(u) + M(u) + 1 = 3M(u) + 1

	No pior caso M(u) é N-1 , possui arestas com todos
vértices. A complexidade pode ser considerada O(N)

	f(N) = N + 2*(N-1) = 3*N - 2

*/	
}

/*
	Encontra o custo de um ciclo hamiltoniano.

	Retorna o custo do ciclo, ou -1 se o ciclo
	não existe no grafo.

	Complexidade:
		O( N^2 ) - Onde N é o número de vértices do grafo
*/
int calculaCicloH(vector<int> ch)
{
	int sCusto = 0, c = 0 , u , v;

	for(int i = 0 ; i < N; i++)		// N+1
	{
		u = ch[i];			// N
		v = ch[(i+1)%N];	// N

		c = custo(u,v); 	// N*(3*N - 2)
		if(c >= 0)			// N
			sCusto += c;
		else
			return -1;
	}
	return sCusto;

/*
	f(N) = N+1 + 3*N + N*(3*N -2)
	f(N) = 3*N^2 - 2*N + 4*N + 1
	f(N) = 3*N^2 + 2*N + 1  = O(N^2)

*/
}

void PCV(vector<int> v , int k = 0)
{
	if(k == N)					// 1
	{
		int c = calculaCicloH(v);	// 3*N^2 + 2*N + 1
		imprimeV(v);
		printf(" %d\n", c);
		if(c >= 0 && c < minC)		// 1
		{
			minC = c;		// 1
			cicloH = v;		// 1
		}
	}

	for(int i = k; i < v.size(); i++)   // N-k + 1
	{
		swap(v[i] , v[k]);		// N-k
		PCV(v, k+1);			// N-K* T(k+1)
		swap(v[i] , v[k]);		// N-k
	}

/*
	Caso Base:
		T(N, k ) = 3*N^2 + 2*N + 5 , para k = N e N >= 1

	Recursão:
		T(N, k ) = (N-k) * T(N, k+1) + 2*(N-k) + N-k
		T(N, k ) = (N-k) * T(N, k+1) + 3*N - 3*k , para K < N-1 e N >= 1

	O Método Mestre não se aplica.

	Tentativa por indução.

		T(N, k) = (N-k) * T(N, k+1) + g(k)
		g(N, k) = 3*N - 3*k

		T(N, k) = (N-k) * T(N, k+1) + g(k)
		T(N, k) = (N-k)* ( (N-k+1) * T(N, k+2) + g(k+1) ) + g(k)
		T(N, k) = (N-k)* ( (N-k+1) * (  (N-k+2) * T(N, k+3) + g(k+2) ) + g(k+1) ) + g(k)

		T(N, k) = (N-k)*(N-k+1)*(N-k+2)*T(N, k+3) + (N-k)*(N-k+1)*g(k+2) + (N-k)*g(k+1) + g(k)

		Como k = 0:N e k = N cai no caso base.

		T(N, k) = (N-k)* (N-k+1) * (N-k+2) * ... * 1 * T(N, N) + (N-k)*(N-k+1)*g(k+2) + (N-k)*g(k+1) + g(k)

		É o mesmo que: (lembrando k começa em 0 e vai até N )
		T(N, k) = (N-k)! * T(N, N) + soma (i=0; i < N-k) de ( (N-k)!/(N-k-i)!*g(i) )

		T(N, k) = (N-k)! * (3N^2 + 2N +1) + soma (i= 0; i < N-k) de ( (N-k)!/((N-k)-i)!*(3N - 3i) )


3! = 3* 2 * 1
2! = 2 * 1

N = 3
T(N-1) = 3N^2 + 2N + 1
g(k) = 3N - 3k

		T(3,0) = 3*2*1*T(2) + 3*2*g(2) + 3*g(1) + g(0)
		T(3,0) = 3*2*1*(3*3^2 + 2*3 + 1) + 3*2*(3*3 - 3*2) + 3*(3*3-3*1) + 3*3

		T(3,0) = 6*(27 + 6 + 1) + 6*(9 - 6) + 3*(9 - 3) + 9
		T(3,0) = 6*(27 + 6 + 1) + 6*(9 - 6) + 3*(9 - 3) + 9
		T(3,0) = 186 + 18 + 18 + 9 = 231

	
	Prova por indução:

	Hipotese:
		T(N, k) = (N-k)! * (3N^2 + 2N +1) + soma (i= 0; i < N-k) de ( (N-k)!/((N-k)-i)!*(3N - 3i) )

	Teste para Base:
		T(N, N) = 3*N^2 + 2*N + 1

	Substituindo pela hipotese:
		T(N, N) = (N-N)! * (3N^2 + 2N +1) + soma (i= 0; i < N-n) de ( (N-N)!/((N-N)-i)!*(3N - 3i) )
		T(N, N) = 1 * (3N^2 + 2N +1) + 0   OK !

	Teste indutivo
		T(N, k) = (N-k) * T(N, k+1) + 3*N - 3*k

	Substituindo T(N, k+1) pela hipotese:
		T(N, k) = (N-k) * ( ( N-(k+1) )! * (3N^2 + 2N +1) + soma (i= 0; i < N-(k+1) ) de ( (N- (k+1) )!/((N- (k+1) )-i)!*(3N - 3*i) ) ) + 3*N - 3*k
		
		Aplicando a distributiva de (N-K):
		T(N, k) = (N-k) * (N-k-1)! * (3N^2 + 2N +1) + (N-k) * soma (i= 0; i < N-k-1) de ( (N-k-1)!/((N-k-1)-i)!*(3N - 3*i) ) + 3*N - 3*k

		Fazendo	(N-k) * (N-k-1)! = (N-k)! :

		T(N, k) = (N-k)! * (3N^2 + 2N +1) + (N-k) * soma (i= 0; i < N-k-1) de ( (N-k-1)!/(N-k-1-i)!*(3N - 3*i) ) + 3*N - 3*k

		Resolvendo o somatorio: de i = 0 até i = n-k-2
		T(N, k) = ... + (N-k) * soma (i= 0; i < N-k-1) de ( (N-k-1)!/(N-k-1-i)!*(3N - 3*i) ) + 3*N - 3*k

		T(N, k) = ... + (N-k) * ( (N-k-1)!/(N-k-1-0)!*(3N - 3*0) + ... + (N-k-1)!/(N-k-1-N+k+2)!*(3N - 3*(N-k-2)) ) + 3*N - 3*k
		
		Aplicando a distributiva de (N-k) no somatorio:

		T(N, k) = ... + (N-k) * (N-k-1)!/(N-k-1)!*(3N - 3*0) + ... + (N-k) * (N-k-1)!/(1)!*(3N - 3*(N-k-2) ) + 3*N - 3*k

		Fazendo	(N-k) * (N-k-1)! = (N-k)! :

		T(N, k) = ... + (N-k)!/(N-k-1)!*(3N - 3*0) + ... + (N-k)!/(1)!*(3N - 3*(N-k-2) ) + 3*N - 3*k

		A parcela 3*N - 3*k que faltava para completa o somatório para i = 0; i < N-k

		T(N, k) = (N-k)! * (3N^2 + 2N +1) + soma (i= 0; i < N-k) de ( (N-k)!/((N-k)-i)!*(3N - 3i) )  OK!

		f(N) = O(N!)


*/
}

/*
	Encontra a solução otima do problema do Caxeiro Viajante,
isto é, encontra o menor ciclo hamiltoniano de um grafo.

	Entrada:
		A entrada é composta por vários casos de teste
a primeira linha de cada caso de teste possui dois
inteiros N e M ( 0 < N , M <= 20 ) representando o
número de vértices e de arestas do grafo.
		Nas próximas M linhas possuem 3 inteiros U , V e P 
( 0 <= U , V < N e 0 <= P < 10000) indicando uma aresta que
relaciona os vertices U e V com peso P.
		O caso de teste N = M = 0 indica o fim da entrada.

	Complexidade:
		O ( N! ) - Onde N é o número de vértices do grafo.

*/
int main()
{
	vector<int> cicloHIni;
	int i, u, v, p;

	scanf("%d %d", &N, &M);
	while(N > 0)
	{
		cicloH.resize(N);

		for( i = 0 ; i < N; i++)
		{
			cicloH[i] = i;
		}

		for(i = 0 ; i < M; i++)
		{
			scanf("%d %d %d", &u, &v, &p);
			g[u].push_back(make_pair(p , v));
			g[v].push_back(make_pair(p , u));
		}

		minC = 10001;
		PCV(cicloH);	// O ( N!)

		if(minC < 10001)
		{
			printf("Melhor ciclo H = ");
			for(i = 0 ; i < N; i++)
			{
				printf("%d ", cicloH[i]);
				g[i].clear();
			}
			printf("com custo %d\n", minC);
		}else
		{
			printf("O Grafo nao possui ciclo hamiltoniano!\n");
		}

		scanf("%d %d", &N, &M);
	}

	return 0;

}


/*
	Matheus Machado dos Santos 102449
*/

