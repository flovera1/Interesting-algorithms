/**
* Description:
* Implemantation of kruskal algorithm 
* using union-find data structure 
* This implemention finds the MST  
* (Minimun Spanning Tree)
* Date: Sat 13 June 2015
* Name: Fernando L.
* email: flovera1@gmail.com
*/
#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"

#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second
const int MAX = 10010;
using namespace std;

inline void inp(int* n){ //fast input function
	*n       = 0;
	int ch   = getchar_unlocked();
	int sign = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			sign = -1;
		}
		ch = getchar_unlocked();
	}
	while(ch >= '0' && ch <= '9')
        (*n) = ((*n)<<3) + ((*n)<<1) + ch - '0', ch = getchar_unlocked();
    *n = (*n)*sign;
}
//Union find class with Path Compression
class Union_Find{
	public: 
		int id[MAX], sz[MAX];
		Union_Find(int n){
			for(int i = 0; i < n; i++){
				id[i] = i;
				sz[i] = 1;
			}
		}
		int root(int i){
			while(i != id[i]){
				id[i] = id[id[i]]; // path compression
				i     = id[i]; 
			}
			return i;
		}
		int find(int p, int q){
			return root(p)==root(q);
		}
		void unite(int p, int q){
				int i = root(p);
				int j = root(q);
		 
				if(sz[i] < sz[j])
				{
					id[i] = j;
					sz[j] += sz[i];
				}
				else
				{
					id[j] = i;
					sz[i] += sz[j];
				}
			}
};			
vector< pip > graph;
int n, e;
long long int T;
 
void Kruskal_MST()
{
	Union_Find UF(n);
	int u, v;
 
	for (int i = 0; i < e; ++i)
	{
		u = graph[i].S.F;
		v = graph[i].S.S;
		if( !UF.find(u, v) )
		{
//			printf("uniting %d and %d\n",u,v );
			UF.unite(u, v);
			T += graph[i].F;
		}
	}
}
 
int main()
{
	int u, v, c;
	inp(&n);	//enter the no of nodes
	inp(&e);	//enter the no of edges
	
	graph.resize(e);
 
	for (int i = 0; i < e; ++i)
	{
		inp(&u);	//enter vertex u
		inp(&v);	//enter vertex v
		inp(&c);	//enter cost of edge (u,v)
		u--;
		v--;
		graph[i] = pip( c, pii(u,v));
	}
	sort(graph.begin(), graph.end());	//sort the edges in increasing order of cost
 
	T = 0;
	Kruskal_MST();
	printf("%lld\n",T);
	return 0;
}