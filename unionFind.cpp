/*
* Union Find structure to detect cycles 
* in a graph
*
* Fernando Lovera
*/
#include <stdio.h>
#include <stdlib.h>

class Union_Find{
	int * set_id, *set_size, size;
	public:
		Union_Find(int n){
			set_id   = new int[n];
			set_size = new int[n];
			for(int i = 0; i < n; i++){
				set_id[i]   = i; //there is one element in each set
				set_size[i] = 1; //at the beginning there is one element
			}
		}
		//find the id of the subset where the element is in
		int find_set_id(int element){
			while(element != set_id[element]){
				element = set_id[element];
				return element;
			}
		}
		int merge(int element1, int element2){
			int a = find_set_id(element1);
			int b = find_set_id(element2);
			if(a < b){
				set_id[b] = a;
			}else{
				set_id[a] = b;
			}
			return a < b? a:b;
		}
};
int main()
{
	return 0;
}
   	