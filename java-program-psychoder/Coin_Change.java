import java.util.*;
public class Coin_Change {
	public static int coin(int table[],int coins[],int n) {
		table[0]=1; //Selecting no coins is one way
		for(int i=0;i<coins.length;i++) {
			for(int j=coins[i];j<=n;j++) {
				table[j]+=table[j-coins[i]];
			}
		}
		return table[n];
	}
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int table[]=new int[n+1];
		int coins[]= {1,2,5};
		int ways=coin(table,coins,n);
		System.out.println(ways);
		sc.close();
	}
}
