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
void selectionsort(int size, T a[])
{
	for (int i = 0; i < size; ++i)
	{
		int pos=i;
		for (int j = i+1; j < size; ++j)
		{
			if(a[j] < a[pos])
				pos = j;
		}
		swap(&a[i], &a[pos]);

		if(debug == true){
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

	selectionsort(size, a);
	cout<<"The sorted array is:\n";
	for (int i = 0; i < size; ++i)
		cout<<a[i]<<" ";
		
	return 0;
}