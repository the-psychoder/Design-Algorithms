#include<stdio.h>
#include<stdlib.h>
int partition(int [],int, int);
void quicksort(int [],int,int);

int partition(int a[],int p,int r){
    int pivot,boundary,j,temp;
    pivot=a[r];
    boundary=p-1;
    for(j=p;j<r;j++){
        if(a[j]<=pivot){
            boundary+=1;
            temp=a[j];
            a[j]=a[boundary];
            a[boundary]=temp;
        }
    }
    boundary+=1;
    temp=a[boundary];
    a[boundary]=a[r];
    a[r]=temp;
    return boundary;
}
void quicksort(int a[],int p,int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
void main(){
    int *a,i,n;
    printf("**********Quick Sort**********\n");
    printf("Enter number of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted Array\n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    quicksort(a,0,n-1);
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
}