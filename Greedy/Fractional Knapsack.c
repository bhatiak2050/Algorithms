#include<stdio.h>
#include<stdbool.h>

bool DEBUG=false;

void swap(double *a, double *b)
{
	double t = *a;
	*a=*b;
	*b=t;
}

void sort(int size, double p[], double w[])
{
	for (int i = 0; i < size; i++)
	for (int j = i+1; j < size; j++)
		if((p[j]/w[j]) > (p[i]/w[i]))
		{
			swap(&p[i], &p[j]);
			swap(&w[i], &w[j]);
		}
}

void fractionalknapsack(int n, double p[], double w[], int W, double x[])
{
	sort(n, p, w);

	for (int i = 0; i < n; ++i)
	{
		x[i] = 0.0;
	}

	double weight=0.0;
	for (int i = 0; i < n; ++i)
	{
		if(w[i]+weight < W)
		{
			x[i] = 1;
			weight += w[i];
		}
		else
		{
			x[i] = (W-weight)/w[i];
			weight=W;
			break;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	if(DEBUG==true) n=4;
	else
	{
		printf("Enter the number of items: \n");
		scanf("%d", &n);
	}


	double p[n], w[n];
   	int W;

	if(DEBUG == true)
	{
		p[0] = 280;
		p[1] = 100,
		p[2] = 120;
		p[3] = 120;
		w[0] = 40;
		w[1] = 10;
		w[2] = 20;
		w[3] = 24;
		W=60;
	}
	else
	{
		printf("Enter the profits of the items: \n");;
		for (int i = 0; i < n; ++i)
			scanf("%lf", &p[i]);

		printf("Enter the weights of the items: \n");;
		for (int i = 0; i < n; ++i)
			scanf("%lf", &w[i]); 

		printf("Enter the capacity of the knapsack: \n");
		scanf("%d", &W);
	}
	
	double x[n];
	fractionalknapsack(n, p, w, W, x);

	if(DEBUG==true){
		printf("Profits: \n");
		for (int i = 0; i < n; ++i)
			printf("%lf, ", p[i]);
		printf("\n");

		printf("Weights: \n");
		for (int i = 0; i < n; ++i)
			printf("%lf, ", w[i]);
		printf("\n");	 

		printf("Fractions: \n");
		for (int i = 0; i < n; ++i)
			printf("%lf, ", x[i]);
		printf("\n");   

	}

	double profit, weight;
	for (int i = 0; i < n; ++i)
		if(x[i] > 0){
			profit += p[i]*x[i];
			weight += w[i]*x[i];
		}

	printf("The total Profit is %f\n", profit);
	printf("The total weight is %f\n", weight);


	return 0;
}