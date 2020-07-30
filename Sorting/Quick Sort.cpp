#include<iostream>
using namespace std;

template <class T>
void swap(T *a, T *b)
{
    T t=*a;
    *a=*b;
    *b=t;
}

template <class T>
int partition(int l, int h, T a[])
{
    T pivot = a[l];
    int i=l, j=h;

    while (i<j)
    {
        do i++; while(a[i] <= pivot);
        do j--; while(a[j] >  pivot);
        if(i<j) swap(&a[i], &a[j]);
    }
    swap(&a[l], &a[j]);
    return j;
}

template <class T>
void quicksort(int l, int h, T a[])
{
    if(l<h)
    {
        int j = partition(l, h, a);
        quicksort(l, j, a);
        quicksort(j+1, h, a);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    char a[n];

    cout<<"Enter the elements: ";
    for (size_t i = 0; i < n; i++)
        cin>>a[i];
    
    quicksort(0, n, a);

    cout<<"The sorted array is\n";
    for (size_t i = 0; i < n; i++)
        cout<<a[i]<<" ";
    return 0;
}
