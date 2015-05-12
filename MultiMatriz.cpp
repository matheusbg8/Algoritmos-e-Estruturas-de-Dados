/*
	Matheus Machado dos Santos 102449
*/
#include<cstdio>
#include<vector>

using namespace std;

vector< vector<int> > multiMatriz(vector< vector<int> > &a , vector< vector<int> > &b)
{
	int i , j , k, n = a.size() , m = b[0].size(), l = b.size();	// 1
	vector< vector<int> > c( n, vector<int>(m) );	// 1
	
	if(a[0].size() == b.size())		// 1
	{
		for(i = 0 ; i < n ; i++)				// an + 1
		{
			for(j = 0; j < m ; j++)				// an * (bm + 1)
			{
				for(k = 0 ; k < l ; k++)		// an * bm * (am+1)
				{
					c[i][j] += a[i][k]*b[k][j];	// an * bm * am
				}
			}
		}
	}

	return c;

	/*
		C = A * B
		an = Número de linhas de A
		am = Número de colunas de A
		bn = Número de linhas de B
		bm = Número de colunas de B
		cn = Número de linhas de C
		cm = Número de colunas de C

		cn = an; cm = bm;  am = bn

		Análise final:
		f(n) = 1 + 1 + 1 + an + 1 + an * (bm + 1) + an * bm*(am+1) + an*bm*am
		f(n) = 4 + an + an*bm + an + an*bm*am + an*bm + an*bm*am
		f(n) = 2*an*bm*am + 2*an*bm + 2*an + 4
		
		Considerando Matriz Quadrada de ordem n:
		an = bm = am = n

		f(n) = 2*n^3 + 2*n^2 + 2*n + 4
		g(n) = n^3

		f(n) = O(n^3) para n0 >= 1 e c = 10
		2n^3 + 2n^2 + 2n + 4 >= cn^3
	*/
}

void imprimeMatriz(vector< vector<int> > &m)
{
	for(int i = 0 ; i < m.size() ; i++)
	{
		for(int j = 0 ; j < m[0].size() ; j++)
		{
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	vector< vector<int> > a(2, vector<int>(3)) , b(3, vector<int>(2)), c;

	a[0][0] = 7;	a[0][1] = 6;	a[0][2] = 7;
	a[1][0] = 4;	a[1][1] = 8;	a[1][2] = 7;

	b[0][0] = 5;	b[0][1] = 1;
	b[1][0] = 4;	b[1][1] = 8;
	b[2][0] = 3;	b[2][1] = 2;

	c = multiMatriz(a,b);

	printf("a = \n");
	imprimeMatriz(a);
	printf("b = \n");
	imprimeMatriz(b);
	printf("c = a*b =\n");
	imprimeMatriz(c);
	return 0;	
}


/*
	Algoritmo
	a00 a01 a02
	a10 a11 a12

	b00 b01
	b10 b11
	b20 b21
	
	c = a*b

	c00 = a00 * b00 + a01 *b10 + a02*b20
	c01 = a00 * b01 + a01 *b11 + a02*b21

	c10 = a10 * b01 + a11 *b11 + a12*b21

	cij = ai0 * b0j + ai1 *b1j + ai2*b2j

	se an == bm
		k = 0:an-1 ou bm-1
			cij += aik *bkj
	
*/

/*
	Matheus Machado dos Santos 102449
*/


