// #include<stdio.h>
#include<time.h>
#define INT_MAX 999

int kruskal(int nv, int cost[nv][nv]){
	int i, j, u, v, ne=1;
	int parent[nv];
	int min, min_cost=0;

	while(ne < nv) {
		min=INT_MAX;
		for(i=0; i<nv; i++)
	        for(j=0; j<nv; j++)
	        if(cost[i][j] < min){
	                min = cost[i][j];
	                u = i;
	                v = j;
	        }
	        if (u != v){
	                parent[v] = u;
	                ne++;
	                min_cost += min;
        	}
	        printf("%d - %d = %d\n", parent[v]+1, v+1, min);
	        cost[u][v] = cost[v][u] = INT_MAX;
	}
	return min_cost;
}

int main(){
	int st, et, nv;

	printf("Enter the no. of vertices: ");
	scanf("%d", &nv);

	int cost[nv][nv];
	printf("Enter the matrix: ");
        for(int i=0; i<nv; i++)
        for(int j=0; j<nv; j++)
                if(i==j) cost[i][j] = INT_MAX;
                else scanf("%d", &cost[i][j]);

	// st = clock();
	int min_cost = kruskal(nv, cost);
	// et = clock();

	printf("Min cost = %d\n", min_cost);
	// printf("Start time = %d\nEnd time = %d\n", st, et);
	return 0;
}
