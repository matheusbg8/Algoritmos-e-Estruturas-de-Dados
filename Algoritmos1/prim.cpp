/*
	Matheus Machado dos Santos
	102449
*/
#include<list>
#include<cstdio>
#include<climits>
#include <list>
#include<queue>

using namespace std;

#define MAX_VERT 1003

// Grafo  destino , custo
list<pair<int, int> > g[MAX_VERT];

// Num vertice, Num arestas
int M , N;

int pre[MAX_VERT];  // Predecessor do vertice na arvore geradora minima
int cust[MAX_VERT]; //Menor custo da aresta que liga o vertice[v] com um vertice da arvore.
int frj[MAX_VERT];  // Vertice na arvore que esta do outro lado da aresta com peso cust[v], v fora da arvore.
// frj -> franja do vertice(vertice que esta na arvore e possui a aresta de menor custo que liga um vertice fora da arvore)

void prim()
{
	int i, u,v, p;
	list< pair<int,int> >::iterator li;
	
	// pilha <cuso , vertice> topo e vertice de menor custo para entrar na arvore
	priority_queue<
	pair<int, int>,
	vector<pair<int, int> >,
	greater< pair<int, int> >  > pilha; 
	
	// Inicialmente ninguem esta na arvore, ninguem tem franja
	for(i = 0 ; i < M; i++)
	{
		pre[i] = frj[i] = -1;
		cust[i] = INT_MAX;
	}
	
	// Apenas 0 esta na arvore, e a raiz
	pre[0] = 0;
	
	// Atualiza franja e custo dos vertices com relação ao 0 que ja esta na arvore
	for(li = g[0].begin(); li != g[0].end() ; li++)
	{
		v = (*li).first; p = (*li).second;
		cust[v] = p;
		frj[v] = 0;
		pilha.push(make_pair(p, v));
	}

	while(!pilha.empty())
	{
		u = pilha.top().second; // pega o vertice que vai entra pra arvore (aquele com menor custo)
		pilha.pop();
		
		if(pre[u] != -1) continue; // Elimina vertices repetidos que tiveram seus custos re ajustados por outro vertice.
		
		pre[u] = frj[u];
		// Aresta esta na arvore u <- cust[u] -> pre[u]
		
		printf("%d <- %d -> %d\n", u+1, cust[u], pre[u]+1);
		
		// Atuliza os vertices alcançaveis por u, que agora ja esta na arvore
		for(li = g[u].begin(); li != g[u].end() ; li ++)
		{
			v = (*li).first;
			p = (*li).second;
			if(pre[v] == -1)
			{
				if(frj[v] == -1 || cust[v] > p) // Define ou re-ajusta custo do vertice
				{
					cust[v] = p;
					frj[v] = u;
					pilha.push(make_pair(p, v));
				}
			}
		}
	
	}	
}

int main()
{
	int i, u , v, p;

	scanf("%d %d", &M, &N);
	
	while( M != 0 || N !=0)
	{
		for(i = 0; i < N ; i++)
		{
			scanf("%d %d %d", &u , &v, &p);
			u--; v--;
			g[u].push_back(make_pair(v,p));
			g[v].push_back(make_pair(u,p));
		}
		
		prim();
		
		printf("\n");

		for(i= 0; i < N;i++)
		{
			g[i].clear();
		}

		scanf("%d %d", &M, &N);
	}	
}

/*
	Matheus Machado dos Santos
	102449
*/
