/*
	Matheus Machado dos Santos
	102449
*/

#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

vector< pair<int, int > > g[1000];
int vis[1000], N, M;
vector<int> acessos;

void DFS(int u)
{
	int v,p;
	acessos.push_back(u);
	for(int i = 0 ; i < g[u].size() ; i++)
	{
		v = g[u][i].second;
		p = g[u][i].first;
		if(vis[v] == 0)
		{
			vis[v] = 1;
			DFS(v);
		}
	}
}


int main()
{
	int u, v, p;
	scanf("%d %d", &N, &M);

	while(M>0 && N >0)
	{
		for(int i = 0; i < M; i++)
		{
			scanf("%d %d %d\n", &u , &v , &p);	
			u--; v--;
			g[u].push_back( make_pair(p,v));
		}

		acessos.clear();
		DFS(0);
		printf("Ordem da busca:\n");
		for(int i = 0 ; i < acessos.size() ; i++)
		{
			printf("%d: %d\n", i+1 , acessos[i]+1);
		}

		scanf("%d %d", &N, &M);
	}
	return 0;	
}

/*
	Matheus Machado dos Santos
	102449
*/

