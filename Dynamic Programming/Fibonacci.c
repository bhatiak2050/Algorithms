#include<stdio.h>
#include<stdbool.h>

bool DEBUG=false;

void fib(int n, long long int F[n])
{
	F[0] = 0, F[1] = 1;
	for (int i = 2; i <= n; ++i)
		F[i] = F[i-2] + F[i-1];
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the position: \n");
	scanf("%d", &n);		

	long long int F[n];
	fib(n, F);
	for (int i = 0; i < n; ++i)
		printf("%lld ", F[i]);
	return 0;
}