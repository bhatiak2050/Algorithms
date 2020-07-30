#include<stdio.h>
#include<stdbool.h>
#define INT_MAX 999

int min_wt(int nv, int evalues[], bool vlist[]){
	int min = INT_MAX;
	int min_index, i;

	for(i=0; i<nv; i++)
	if(vlist[i] == false && evalues[i] < min){
		min = evalues[i];
		min_index = i;
	}
	return min_index;
}

void prims(int nv, int graph[nv][nv]){
	int  parent[nv];
	int evalues[nv], i;
	bool  vlist[nv];

	//initialise vlist to false, evalues to INT_MAX
	for(i=0; i<nv; i++){
		vlist[i] = false;
		evalues[i] = INT_MAX;
	}

	evalues[0] = 0;
	 parent[0] = -1;

	for(i=0; i<nv-1; i++){
		int u = min_wt(nv, evalues, vlist);
		vlist[u] = true;

		for(int v=0; v<nv; v++)
		if(graph[u][v] != INT_MAX && 
		   vlist[v] == false && 
		   graph[u][v] < evalues[v])
		{
			evalues[v] = graph[u][v];
			 parent[v] = u;
		}
	}

	int cost=0;
	for(i=1; i<nv; i++){
		printf("%d - %d = %d\n", parent[i], i, evalues[i]);
		cost += evalues[i];
	}
	printf("The cost is %d\n", cost);
}

int main(){
	/*
	input: no of vertices: 4
	matrix:
	   20 10 50 
	20    40 70 
	10 40    30 
	50 70 30   	
	
	we're ignoring the inputs where i=j;
	*/
	int nv;
	printf("Enter the number of vertices: ");
	scanf("%d", &nv);

	int graph[nv][nv];
	printf("Enter the matrix: ");
	for(int i=0; i<nv; i++)
	for(int j=0; j<nv; j++)
		if(i==j) graph[i][j] = INT_MAX;
		else scanf("%d", &graph[i][j]);

	prims(nv, graph);
	return 0;
}
