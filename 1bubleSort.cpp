#include<iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void display(int *a, int n) {
    int i;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void bubleSort(int *a, int n){
    int c=1,i;
     while(c<n) 
     {
        for(i=0;i<n;i++)
        {
            if(a[i]>a[i+1])
                swap(a[i], a[i+1]);
        }
      c++;
    } 
}
int main()
{
    int n, i;
    cout<<"\nEnter Number of Elements ";
    cin>>n;
    int a[n];
    cout<<"\nEnter "<<n<<" Elements ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\nBefore Sorting : ";
    display(a, n);
    bubleSort(a, n); 
    cout<<"\nAfter Sorting :  ";
    display(a, n);
    return 0;
 }
