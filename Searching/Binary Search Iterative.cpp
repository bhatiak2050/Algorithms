#include<stdio.h>
#include<time.h>

int bsearch(int n, int a[n], int key){
	int beg=0, last=n-1, mid;
	int m = (a[0]<=a[n-1])?1:2;		//mode control for ascending or descending order
	while(beg<=last){
		mid=(beg+last)/2;
		if(key == a[mid]) return mid;
		else if(key < a[mid]) if(m==1) last=mid-1; else beg =mid+1;
		else if(key > a[mid]) if(m==1) beg =mid+1; else last=mid-1;
	}
	return -1;
}

int main(){
        int n, st, et;
        printf("Enter the size: ");
        scanf("%d", &n);

	int a[n];
        printf("Enter the elements\n");
        for(int i=0; i<n; i++)
                scanf("%d", &a[i]);

        int key;
        printf("Enter the key: ");
        scanf("%d", &key);

	st = clock();
        int pos = bsearch(a, n, key);
	et = clock();

        if(pos == -1) printf("Element not found\n");
        else printf("Element found at position %d\n", pos+1);
	printf("Start time = %d\nEnd time = %d\n", st, et);
        return 0;
}

