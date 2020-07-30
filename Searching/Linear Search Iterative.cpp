#include<stdio.h>

int lsearch(int a[], int n, int key){
    for(int i=0; i<n; i++)
	if(a[i] == key) return i;
    return -1;
}

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements\n");
    for(int i=0; i<n; i++)
            scanf("%d", &a[i]);

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

	int st = clock();
    int pos = lsearch(a, n, key);
	int et = clock();
	
    if(pos == -1) printf("Element not found\n");
    else printf("Element found at position %d\n", pos+1);
	printf("Start time = %d\nEnd time = %d\n", st, et);
    return 0;
}




