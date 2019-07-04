import java.util.*;
class Bin{
	public int binary(int a[],int lb, int ub,int key) {
		if(lb<=ub) {
			int mid=(lb+ub)/2;
			if(key==a[mid])
				return mid;
			else if(key<a[mid])
				return binary(a,lb,mid-1,key);
			else
				return binary(a,mid+1,ub,key);
		}
		else
			return -1;
	}
}
public class Binary_search {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=sc.nextInt();
		}
		int key=sc.nextInt();
		Bin ob=new Bin();
		int pos=ob.binary(arr,0,n-1,key);
		if(pos!=-1)
			System.out.println("found at position "+(pos+1));
		else
			System.out.println("Not found !");
		sc.close();
	}
}
