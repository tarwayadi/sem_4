// Online C compiler to run C program online
#include <stdio.h>

void swap( int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void max_heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[largest]){
        largest=l;
    
    }
    if(r<n&&a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);
        max_heapify(a,n,largest);
    }


}
void heapsort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(a,n,i);
        
    }
     for(int i=n-1;i>=0;i--){
        swap(&a[0],&a[i]);
        max_heapify(a,i,0);
}
}
void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);

    }
}

int main() {
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d\t",&a[i]);}
     heapsort(a,n);
     printarray(a,n);
    return 0;

}