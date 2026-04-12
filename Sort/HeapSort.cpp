#include <iostream>

using namespace std;

void outPut(int a[], int n, int m){
    int i=0;
    for(;i<n;i++)
        cout<<a[i]<<' ';
    if(n<m){
        cout<<"| ";
        for(;i<m;i++)
            cout<<a[i]<<' ';
    }
    cout<<endl;
}
void heapify(int a[], int p, int n){
    int i=p*2+1;
    while(i<n){
        if(i+1<n)
            if(a[i+1]>a[i]) i+=1;
        if(a[i]>=a[p]){
            swap(a[i],a[p]);
            p=i;
            i=p*2+1;
        }
        else
            return;
    }
}
void buildHeap(int a[], int n){
    int p=(n-1)/2;
    while(p>=0){
        heapify(a,p,n);
        p--;
    }
}
void heapSort(int a[], int n, int m){
    buildHeap(a,n);
    cout<<"Mang sau khi BuildHeap: "; outPut(a,n,m);
    while(n>1){
        cout<<"Swap "<<a[0]<<" va "<<a[n-1]<<endl;
        swap(a[0],a[n-1]);
        n--;
        heapify(a,0,n);
        cout<<"\nMang sau khi heapify voi n = "<<n<<": "; outPut(a,n,m);
    }
}


int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Mang truoc khi sap xep: \n";
    outPut(a,n,n);
    cout<<"\nSap xep:\n";
    heapSort(a,n,n);
    cout<<"Mang sau khi sap xep: \n";
    outPut(a,n,n);
}
