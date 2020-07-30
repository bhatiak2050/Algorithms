#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool DEBUG=true;

int main(int argc, char const *argv[])
{
	int stages = 4, min, n=8, cost[n+1], d[n+1], path[n+1];
	int c[9][9] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 1, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 2, 3, 0, 0},
		{0, 0, 0, 0, 0, 6, 7, 0, 0},
		{0, 0, 0, 0, 0, 6, 8, 9, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 6},
		{0, 0, 0, 0, 0, 0, 0, 0, 4},
		{0, 0, 0, 0, 0, 0, 0, 0, 5},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	cost[n] = 0;
	for (int i = n-1; i >= 1; --i)
	{
		min = INT_MAX;
		for (int k = i+1; k <= n; ++k)
		{
			if (c[i][k]!=0 && c[i][k]+cost[k])
			{
				min = c[i][k] + cost[k];
				d[i] = k;
			}
		}
		cost[i] = min;
	}
	path[1] = 1; path[stages] = n;
	for (int i = 2; i < stages; ++i)
	{
		path[i] = d[path[i-1]];
	}

	for (int i = 0; i < stages; ++i)
	{
		/* code */
	}
	return 0;
}