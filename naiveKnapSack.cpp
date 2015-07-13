#include <stdio.h>
//utility function that returns max of two integers
int max(int a, int b){
	return (a > b)? a:b;
}
/*
* returns the maximum value that can be put in
* a knapsack of capacity W
*/
int knapsack(int W, int wt[], int val[], int n){
	//base case
	if(n == 0 || W == 0)
		return 0;
	// if weight of nth item is more than knapsack
	// capacity W, then
	// this item cannot be included in the optimal
	// solution
	if(wt[n-1] > W){
		return knapsack(W, wt, val, n-1);//solve the problem without that item
	}
	//return the max of the two cases.
	//(1) nth item included. knapsack substracting weights and the number of items
	//(2) nth item not included. original prob without the item
	else{
		return max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1),
					knapsack(W, wt, val, n-1));
	}
}
int main(){
	int val[] = {60, 100, 120};
	int wt[]  = {10, 20, 30};
	int W     = 50;
	int n     = sizeof(val) / sizeof(val[0]);
	printf("%d\n", knapsack(W, wt, val, n));
	return 0;
}