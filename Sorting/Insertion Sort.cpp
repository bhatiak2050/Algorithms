#include<iostream>
#include<stdbool.h>
using namespace std;

bool debug = false;

template <class T>
void swap(T *a, T *b)
{
	T t = *a;
	*a=*b;
	*b=t;
}

template <class T>
void Insertionsort(int size, T a[])
{
    for (int i = 1; i < size; i++)
    {
        int j=i;
        while(j>0 && a[j-1] > a[j]){
            swap(&a[j], &a[j-1]);
            j-=1;
        }    
        
        if(debug == true)
        {
			for (int i = 0; i < size; ++i)
				cout<<a[i]<<" ";
			cout<<endl;
        }
    }
    
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

	Insertionsort(size, a);
	cout<<"The sorted array is:\n";
	for (int i = 0; i < size; ++i)
		cout<<a[i]<<" ";
		
	return 0;
}