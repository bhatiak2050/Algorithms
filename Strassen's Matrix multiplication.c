#include<stdio.h>

void matrixadd(int n, int a[][n], int b[][n], int sum[][n]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			sum[i][j] = a[i][j] + b[i][j];
}

void matrixsub(int n, int a[][n], int b[][n], int sum[][n]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			sum[i][j] = a[i][j] - b[i][j];
}


void subdivide(int n, int m, int a[][n], int p[][m], int q[][m], int r[][m], int s[][m])
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			p[i][j] = a[i][j];
		for (int j = m; j < n; ++j)
			q[i][j-m] = a[i][j];
	}
	for (int i = m; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			r[i-m][j] = a[i][j];
		for (int j = m; j < n; ++j)
			s[i-m][j-m] = a[i][j];
	}
}

void combine(int n, int m, int a[][n], int p[][m], int q[][m], int r[][m], int s[][m])
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			a[i][j] = p[i][j];
		for (int j = m; j < n; ++j)
			a[i][j] = q[i][j-m];
	}
	for (int i = m; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			a[i][j] = r[i-m][j];
		for (int j = m; j < n; ++j)
			a[i][j] = s[i-m][j-m];
	}
}

void multiply(int n, int x[][n], int y[][n], int z[][n]){

	if(n==0) return;

	if(n==1) {
		z[0][0] = x[0][0] * y[0][0];
	}
	
	else if(n==2) {
		z[0][0] = x[0][0] * y[0][0] + x[0][1] * y[1][0];
		z[0][1] = x[0][0] * y[0][1] + x[0][1] * y[1][1];
		z[1][0] = x[1][0] * y[0][0] + x[1][1] * y[1][0];
		z[1][1] = x[1][0] * y[0][1] + x[1][1] * y[1][1];
	}

	else {
		int m = n / 2;
		int a[m][m], b[m][m], c[m][m], d[m][m], e[m][m], f[m][m], g[m][m], h[m][m];
		
		subdivide(n, m, x, a, b, c, d);
		subdivide(n, m, y, e, f, g, h);

		int ac[m][m]; matrixadd(m, a, c, ac);
		int ef[m][m]; matrixadd(m, e, f, ef);
		int bd[m][m]; matrixadd(m, b, d, bd);
		int gh[m][m]; matrixadd(m, g, h, gh);
		int ad[m][m]; matrixsub(m, a, d, ad);
		int eh[m][m]; matrixadd(m, e, h, eh);
		int fh[m][m]; matrixsub(m, h, f, fh);
		int cd[m][m]; matrixadd(m, c, d, cd);
		int ab[m][m]; matrixadd(m, a, b, ab);
		int ge[m][m]; matrixsub(m, g, e, ge);

		int m1[m][m]; multiply(m, ac, ef, m1);
		int m2[m][m]; multiply(m, bd, gh, m2);
		int m3[m][m]; multiply(m, ad, eh, m3);
		int m4[m][m]; multiply(m, a, fh, m4);
		int m5[m][m]; multiply(m, cd, e, m5);
		int m6[m][m]; multiply(m, ab, h, m6);
		int m7[m][m]; multiply(m, d, ge, m7);

		int m23[m][m]; matrixadd(m, m2, m3, m23);
		int m67[m][m]; matrixadd(m, m6, m7, m67);
		int   i[m][m]; matrixsub(m, m23, m67, i);

		int   j[m][m]; matrixadd(m, m4, m6, j);

		int   k[m][m]; matrixadd(m, m5, m7, k);

		int m13[m][m]; matrixsub(m, m1, m3, m13);
		int m45[m][m]; matrixadd(m, m4, m5, m45);
		int   l[m][m]; matrixsub(m, m13, m45, l);


		combine(n, m, z, i, j, k, l);
	}		
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the size of the matrices\n(should be a power of 2 ex. 2,4,8,16...): ");
	scanf("%d", &n);

	int x[n][n], y[n][n], z[n][n];
	printf("Enter the elements of the first matrix: ");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			scanf("%d", &x[i][j]);
	}

	printf("Enter the elements of the second matrix: ");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			scanf("%d", &y[i][j]);
	}

	multiply(n, x, y, z);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%d ", z[i][j]);
		printf("\n");
	}
	return 0;
}