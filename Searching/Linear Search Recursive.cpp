#include<stdio.h>

int lsearch(int n, int a[n], int key, int i){
	if(i==n) return -1;
	else if(key == a[i]) return i;
	else return lsearch(n, a, key, i+1); //Please use i+1 only as i++ causes segmentation fault
}

int main(){
	int n;
	printf("Enter the size: ");
	scanf("%d", &n);

	int a[n];
	printf("Enter the elements: ");
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int key;
	printf("Enter the key: ");
	scanf("%d", &key);

	int pos = lsearch(n, a, key, 0);

	if(pos == -1) printf("Element not found\n");
	else printf("Element found at position %d\n", pos+1);

	return 0;
}
