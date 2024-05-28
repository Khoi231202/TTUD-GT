#include<iostream>
using namespace std;

const int MAX =1e6;
int arr[MAX];
int n;

void merge(int arr[], int l, int m, int r){
    int n1, n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i]=arr[l+i];
    }
    for(int i=0; i<n2; i++){
        R[i]=arr[m+1+i];
    }

    int k=l;
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else if(R[j]<L[i]){
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        for(int t=l; t<=r ;t++){
            cout<< arr[t]<<' ';
        }
        cout<<endl;
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }

}
void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }    
}
int main(){
    freopen("input.txt","r", stdin);
    input();
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++)cout<<arr[i]<<' ';
    return 0;

}