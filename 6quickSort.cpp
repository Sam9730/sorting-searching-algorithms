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
/*func partition() takes an array,select pivot element ,compare pivot using start ands end indices and perform swaps 
function return the final location of pivot element after swapping */
int partition(int *a,int l,int u){
     int start=l,end=u,pivot=a[l];//start pointing lowerIndex of Array,end pointing upperIndex of Array,1st element is chosen as pivot element
     while(start<end) 
     {
        while(a[start]<=pivot)//start pointer will stop at element > pivot element
            start++;
        while(a[end]>pivot)  //end pointer will stop at element < pivot element
            end--;
        if(start<end)       //swap element at start and end only if start and end didnt crossed each other.
            swap(a[start],a[end]) ; 
     }
     swap(a[l], a[end]) ;   //pivot element will be swaped withh element pointed by end
     return end;            //return location of pivot element
 }
/*func. quickSort() calls partition function and takes the location of pivot element after swaping,
then partition array as leftside of pivot and rightside of pivot and recursively calls partion function untill array is partitioned into single elements */
 void quickSort(int *a, int l, int u){
    int loc;    //variable storing location of pivot element
    if(l<u) 
    {
        loc=partition(a, l, u);     //takes location of pivot element
        quickSort(a, l, loc-1);     //calls for leftside array from pivot element
        quickSort(a, loc+1, u) ;    //calls for rightside array from pivot element
     }
}   
int main(){
    int n, i;
    cout<<"\nEnter Number of Elements ";
    cin>>n;
    int a[n];
    cout<<"\nEnter "<<n<<" Elements ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\nBefore Sorting : ";
    display(a, n) ;
    quickSort(a, 0,n-1) ;
    cout<<"\nAfter Sorting :  ";
    display(a, n);
    return 0;
 }
