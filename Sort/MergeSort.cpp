#include <iostream>

using namespace std;

void output(int a[], int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
void Merge(int a[],int b[], int c[], int nB, int nC, int k){
    int ib, ic, pb, pc, p;
    ib=ic=pb=pc=p=0;
    int kb=min(k,nB), kc=min(k,nC);
    while(nB>0 and nC>0){
            if(b[pb+ib]<c[pc+ic]){
                a[p]=b[pb+ib];
                ib++;
                p++;
                if(ib==kb){
                    for(;ic<kc;ic++){
                        a[p]=c[pc+ic];
                        p++;
                    }
                    ib=ic=0;
                    pb+=kb;pc+=kc;
                    nB-=kb;nC-=kc;
                    kb=min(k,nB); kc=min(k,nC);
                }
            }
            else{
                a[p]=c[pc+ic];
                ic++;
                p++;
                if(ic==kc){
                    for(;ib<kb;ib++){
                        a[p]=b[pb+ib];
                        p++;
                    }
                    ib=ic=0;
                    pb+=kb;pc+=kc;
                    nB-=kb;nC-=kc;
                    kb=min(k,nB); kc=min(k,nC);
                }
            }
    }
}
void mergeSort(int A[], int n){
    int p, pb, pc, i, k = 1;
    while (k < n) {
        cout<<"\nk = "<<k<<endl;
        cout<<"Mang A (truoc khi chia): ";
        output(A,n);
        p = pb = pc = 0;
        int *B = new int [n];
        int *C = new int [n];
        while (p < n) {
            for (i = 0; (p < n) && (i < k); i++)
                B[pb++] = A[p++];
            for (i = 0; (p < n) && (i < k); i++)
                C[pc++] = A[p++];
        }
        cout<<"Mang B: ";
        output(B,pb);
        cout<<"Mang C: ";
        output(C,pc);
        Merge(A, B, C, pb, pc, k);
        cout<<"Mang A (sau khi gop): ";
        output(A,n);
        k *= 2;
        delete B;
        delete C;
    }
}

int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Mang truoc khi sap xep:\n";
    output(a,n);
    cout<<"\nSap xep:";
    mergeSort(a,n);
    cout<<"\nMang sau khi sap xep:\n";
    output(a,n);
}
