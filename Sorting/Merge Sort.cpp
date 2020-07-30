#include<iostream>
using namespace std;

template <class T>
void merge(int nl, T left[], int nr, T right[], T a[])
{
    int i=0, j=0, k=0;

    while(i<nl && j<nr)
    {
        if(left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while(i<nl) a[k++] = left[i++];
    while(j<nr) a[k++] = right[j++];
}

template <class T>
void mergesort(int n, T a[])
{
    if(n<2) return;

    int mid = n/2;
    T left[mid], right[n-mid];

    for (size_t i = 0; i < mid; i++)
        left[i] = a[i];
    for (size_t i = mid; i < n; i++)
        right[i-mid] = a[i];
    
    mergesort(mid, left);
    mergesort(n-mid, right);
    merge(mid, left, n-mid, right, a);
}

//Driver code
int main(int argc, char const *argv[])
{
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;

	int a[size];
	cout<<"Enter the elements: ";
	for (int i = 0; i < size; ++i)
		cin>>a[i];

	mergesort(size, a);
	cout<<"The sorted array is:\n";
	for (int i = 0; i < size; ++i)
		cout<<a[i]<<" ";
		
	return 0;
}