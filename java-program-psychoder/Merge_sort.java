import java.util.*;
class MergeSort{
	void mergesort(int a[],int lb,int ub) {
		if(lb<ub) {
			int mid=(lb+ub)/2;
			mergesort(a,lb,mid);
			mergesort(a,mid+1,ub);
			merge(a,lb,mid,ub);
		}
	}
	void merge(int a[],int lb,int mid,int ub) {
		int x=lb,i=lb,j=mid+1,k;
		int b[]=new int[30];
		while(i<=mid && j<=ub) {
			if(a[i]<a[j])
				b[x++]=a[i++];
			else
				b[x++]=a[j++];
		}
		while(i<=mid && j>ub)
			b[x++]=a[i++];
		while(j<=ub && i>mid)
			b[x++]=a[j++];
		for(k=lb;k<=ub;k++)
			a[k]=b[k];
	}
}
public class Merge_sort {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=sc.nextInt();
		MergeSort ob=new MergeSort();
		ob.mergesort(arr,0,n-1);
		for(int i=0;i<n;i++)
			System.out.print(arr[i]+ " ");
		sc.close();
	}
}
