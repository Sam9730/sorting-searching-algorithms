#include<iostream>
using namespace std;
//function return Sorted array
void selectSort(int *a, int n){
    int i, j, min, loc;
    for(i=0;i<n;i++)
    {
        min=a[i];
        loc=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<min)
            {
               min=a[j] ;
               loc=j;
            }
         }
        int temp;
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
   }
}
// funct perform binary search and take parameters l-Lower index,u-upper index,s-element to search 
int binarySearch(int *a, int l, int u, int s){
    int mid;
    if(l<=u)
    {
        mid=(l+u)/2;
        //function recursively calls itself passing mid index untill either element is found or lower index > upper index
        if(a[mid]==s)
            return mid;
        if(a[mid]>s)
            return binarySearch(a,l, mid-1,s);
        if(a[mid]<s)
            return binarySearch(a, mid+1,u, s);
    }
     return -1;
}
int main(){
    int n, i, s,c;
    cout<<"\nEnter Number of Elements ";
    cin>>n;
    int a[n];
    cout<<"\nEnter "<<n<<" Elements ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    //calling sort func. to arrange array in sorted order
    selectSort(a, n);
    cout<<"\nEnter element to search ";
    cin>>s;
    c=binarySearch(a, 0,n-1,s);
    if(c==-1)
        cout<<"\nElement not found ";
     else
        cout<<"\n"<<s<<" found at index "<<c;
    return 0;
}
