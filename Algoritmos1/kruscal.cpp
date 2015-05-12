/*
	Matheus Machado dos Santos
	102449
*/

#include<cstdio>
#include<climits>
#include<vector>
#include <algorithm>

using namespace std;


#define MAX_VERT 1003

short N, M; // Num Vertices, Num Arestas

// Algoritmo de kruskal trabalha diiretamente com as arestas
vector < pair < double, pair < short , short > > > arestas;

short pre[MAX_VERT]; // Predecessor do nodo na arvore de vertices
short tam[MAX_VERT]; // Importante na construcao da arvore, faz com que a raiz seja alcançada mais rapida no find


short grupo( short v)
{ // Encontra a raiz
	while(v != pre[v])
		v = pre[v];
	return v;
}

short uniao(short g1, short g2)
{// Faz a uniao dos grupos, retorna id grupo unido
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
	short i, gu , gv;
	// Ordena arestas pelo custo de forma crescente
	sort(arestas.begin() , arestas.end());
	
	// Inicializa a arvore de grupos
	for(i = 0 ; i < N ; i++)
	{
		pre[i] = i;
		tam[i] = 1;
	}
	
	for( i = 0 ; i < M ; i++)
	{
		gu = grupo(arestas[i].second.first);
		gv = grupo(arestas[i].second.second);
		if( gu != gv)
		{
			gu = uniao(gu, gv);
			// Aqui Aresta[i] pertence a MST
			
			printf("%hd <- %lg -> %hd\n",
			arestas[i].second.first+1, arestas[i].first,
			arestas[i].second.second+1);			
		}
	}
}

int main()
{
	short i, u , v;
	double p;
	
	scanf("%hd %hd", &N, &M);
	while( N != 0 || M !=0)
	{
		arestas.resize(M);
		for(i = 0 ; i < M ; i++)
		{
			scanf("%hd %hd %lg", &u , &v, &p);
			arestas[i] = make_pair(p , make_pair(u-1,v-1));
		}
		
		kruskal();
		
		printf("\n");
		arestas.clear();
		
		scanf("%hd %hd", &N, &M);
	}
}

/*
	Matheus Machado dos Santos
	102449
*/
