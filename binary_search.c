#include<stdio.h>
#include<stdlib.h>

int binsearch(int a[],int lb,int ub,int key){
    int mid;
    if(lb>ub)
        return -1;
    else{
        mid=(ub+lb)/2;
        if(a[mid]==key)
            return mid;
        else if(key>mid)
            return binsearch(a,mid+1,ub,key);
        else
            return binsearch(a,lb,mid-1,key);
    }
}
void main(){
    int i,n,*a,k,pos;
    printf("**********Binary Search**********\n");
    printf("Enter number of elements:");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter key to search: ");
    scanf("%d",&k);
    pos=binsearch(a,0,n-1,k);
    if(pos==-1)
        printf("Key not found !");
    else
        printf("%d found at position %d",k,pos+1);
}