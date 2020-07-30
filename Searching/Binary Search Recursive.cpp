#include<stdio.h>
#include<time.h>

int a[20];

int bsearch(int n, int beg, int last, int key){
	if(beg > last) return -1;
	int mid = (beg+last)/2;
	int m = (a[0] < a[1])?1:0;		//mode control for ascending or descending
	if(key == a[mid]) return mid;
	else if(key < a[mid]) return bsearch(n, (m)?beg:mid+1, (m)?mid-1:last, key);
	else if(key > a[mid]) return bsearch(n, (m)?mid+1:beg, (m)?last:mid-1, key);
}

int main(){
	int n, st, et;
	printf("Enter the size: ");
	scanf("%d", &n);

	printf("Enter the elements\n");
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int key;
	printf("Enter the key: ");
	scanf("%d", &key);

	st = clock();
	int pos = bsearch(n, 0, n-1, key);
	et = clock();

	if(pos == -1) printf("Element not found\n");
	else printf("Element found at position %d\n", pos+1);
	printf("Start time = %d\nEnd time = %d\n", st, et);
	return 0;
}
