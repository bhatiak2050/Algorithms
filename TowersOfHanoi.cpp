#include<iostream>
using namespace std;

void toh(int n, char beg, char aux, char end)
{
    if(n == 1)
    {
        cout<<"Disk 1: "<<beg<<" -> "<<end<<endl;
        return;
    }
    toh(n-1, beg, end, aux);
    cout<<"Disk "<<n<<": "<<beg<<" -> "<<end<<endl;
    toh(n-1, aux, beg, end);
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;

    toh(n, 'A', 'B', 'C');
    return 0;
}
