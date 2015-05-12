// Matheus Machado dos Santos  102449
// Compile usando g++ trab2_102449.c 

#include<cstdio>
#include<climits>
#include<vector>
#include <algorithm>

using namespace std;


#define MAX_VERT 1003

int N, M; // Num Vertices, Num Arestas

// Algoritmo de kruskal trabalha diretamente com as arestas
vector < pair < int, pair < int , int > > > arestas;

int pre[MAX_VERT]; // Predecessor do nodo na arvore de vertices
int tam[MAX_VERT]; // Importante na construcao da arvore, faz com que a raiz seja alcançada mais rapida no find

// Retorna o id do grupo do vertice V
int grupo( int v)
{ // O grupo é o grupo do vertice raíz
	while(v != pre[v])
		v = pre[v];
	return v;
}

// Faz a uniao dos grupos, retorna id grupo unido
int uniao(int g1, int g2)
{
	if(g1 == g2) return g1;

// Teste importante para construção da arvore com eficiencia
// de forma que a raiz seja atingida mais rapidamente (mais ramos)
	if(tam[g1] < tam[g2])
	{
		pre[g1] = g2;
		tam[g2]+= tam[g1];
		return g2;
	}else
	{
		pre[g2] = g1;
		tam[g1] += tam[g2];
		return g1;
	}
}

void kruskal()
{
	int i, gu , gv;
	// Ordena arestas pelo custo de forma crescente
	sort(arestas.begin() , arestas.end());
	
	// Inicializa a arvore de grupos
	for(i = 0 ; i < N ; i++)
	{
		pre[i] = i;
		tam[i] = 1; // Cada arvore inicialmente com 1 vertice
	}
	
	for( i = 0 ; i < M ; i++)
	{
		// Para cada aresta i do grafo, partindo do menor custo para o maior custo.
		gu = grupo(arestas[i].second.first);
		gv = grupo(arestas[i].second.second);

		// Se os vertices da aresta não pertencem ao mesmo grupo
		if( gu != gv)
		{
			// Junta os vértices, a aresta pertence a MST
			gu = uniao(gu, gv);
			
			printf("%d <- %d -> %d\n",
			arestas[i].second.first+1, arestas[i].first,
			arestas[i].second.second+1);
		}
	}
}

int main()
{
	int i, u , v, p;
	N = M = 1;
	while( N != 0 || M !=0)
	{
		printf("Digite o numero total de VERTICES do Grafo: ");	
		scanf("%d", &N);
		printf("Digite o numero total de ARESTAS do Grafo: ");	
		scanf("%d", &M);

		arestas.resize(M);

		printf("Enumero os vertices de 1 a N, onde N = %d.\n",N);
		printf("Defina as arestas digitando 3 inteiros separados por espaco. O numero correspondente ao vertice u , o numero correspondente ao vertice v e o peso da aresta p. Obs.: O grafo nao e dirigido.\n");
		for(i = 0 ; i < M ; i++)
		{
			printf("Defina a aresta %d na forma u v p: ",i+1);
			scanf("%d %d %d", &u , &v, &p);
			arestas[i] = make_pair(p , make_pair(u-1,v-1));
		}
		
		printf("\nArvore Geradora Minima:\n");
		kruskal();
		printf("\n");
		arestas.clear();		
		printf("Para encerrar o programa defina um grafo com 0 vertices e 0 arestas.\n");
	}
	return 0;
}

// Matheus Machado dos Santos  102449
// Compile usando g++ trab2_102449.c 

