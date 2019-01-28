#include<stdio.h>
#include<stdlib.h>
void mergesort(int [],int,int);
void merge(int [],int,int,int);

void mergesort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high){
    int i,j,k,beg,b[20];
    i=beg=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]>a[j])
            b[beg++]=a[j++];
        else
            b[beg++]=a[i++];
    }
    while(i>mid && j<=high)
        b[beg++]=a[j++];
    while(j>high && i<=mid)
        b[beg++]=a[i++];
    for(k=low;k<beg;k++)
        a[k]=b[k];
}
void main(){
    int *a,i,n;
    printf("**********Merge Sort**********\n");
    printf("Enter number of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted Array\n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    mergesort(a,0,n-1);
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
}