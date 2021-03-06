/*
* Union Find with hashtables!
* 
*
* Fernando Lovera
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Node;
class Disjoint_set;
class Edge{
	public:
		Node *source;
		Node *destiny;
		Edge(Node *nodeSource, Node *nodeDest){
			source  = nodeSource;
			destiny = nodeDest;
		}
};
class Node{
	private:
		char name;
		vector<Edge> adjNodeList;
	public:
		Node(char nodename){
			name = nodename;
		}
};
class Graph{
	public:
		vector<Edge> set;
		Disjoint_set *rep;
		Graph(vector<Edge> s){
			set = s;
		}
		int size(){
			int counter = 0;
			for(int i = 0; i < this->set.size(); i++){
				counter ++;
			}
			return counter;
		}
};
class Disjoint_set{
	unordered_map <char, char> PARENT;
	unordered_map <char, int> RANK; //record the depth of trees
	public:
		Disjoint_set(){
			char universe[] = {'a', 'b', 'c', 'd', 'e'};
			for(char x: universe){
				PARENT[x] = x; //5 disjoint sets each set contain one item.
				RANK[x]   = 0;
			}
			PARENT['d'] = 'b';//b and d in the same set
			RANK['b']   = 1;
		}
		char Find(char item){
			if(PARENT[item] == item)
				return item;
			else
				return Find(PARENT[item]);
		}
		/*
		* use the root of the deeper tree to
		* be the new root
		*/
		void Union(char set_1, char set_2){
			if(RANK[set_1] > RANK[set_2])
				PARENT[set_2] = set_1;
			else if(RANK[set_2] > RANK[set_1])
				PARENT[set_1] = set_2;
			else{
				PARENT[set_1] = set_2;
				RANK[set_2]++;
			}
		}
};

int main(){
	Disjoint_set ds;
	cout << ds.Find('c'); //return c
	ds.Union('c', 'a'); //a and c are in the same set
	cout << ds.Find('c'); // return a
	ds.Union('a', 'b'); //a, c, b, d are in the same set
}
   	