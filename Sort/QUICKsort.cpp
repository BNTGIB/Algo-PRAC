#include <iostream>
#include <algorithm>
using namespace std;
void output(int a[], int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
void quickSort(int a[],int l, int r, int n){
    if(l>=r) return;
    cout<<"Truoc: "; output(a,n);
    int i=l, j=r, x=a[(l+r)/2];
    cout<<"Left="<<l<<" - Right="<<r<<" - Pivot="<<x<<endl;
    while(i<j){
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    cout<<"Sau: ";output(a,n);
    cout<<endl;
    quickSort(a,l,j,n);
    quickSort(a,i,r,n);


}
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Mang truoc khi sap xep:\n";
    output(a,n);
    cout<<"\nSap xep: \n";
    quickSort(a,0,n-1,n);
    cout<<"Mang sau khi sap xep:\n";
    output(a,n);
    return 0;
}
