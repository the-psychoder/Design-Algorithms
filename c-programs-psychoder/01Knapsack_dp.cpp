#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
	return (a>b?a:b);
}
int main(){
	int n,t;
	cin>>n>>t;		//Input number of elements and bag capacity(max weight)
	int p[n+1]={0},w[n+1]={0},dp[n+1][t+1],result[n+1]={0};
	int i,j;
	for(i=1;i<=n;i++)
	cin>>p[i];		//Input profit
	for(i=1;i<=n;i++)
	cin>>w[i];		//Input Weight
	//sort in ascending order by profit
	int temp;
	for(i=1;i<n;i++){
		for(j=1;j<=n-i;j++){
			if(p[j]>p[j+1]){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}
	// print profit and weight After sorting
	cout<<"Profit:";
	for(i=1;i<=n;i++)
		cout<<p[i]<<" ";	
	cout<<endl;	
	
	cout<<"Weight:";
	for(i=1;i<=n;i++)
		cout<<w[i]<<" ";
	cout<<endl;
	//DP approach
	for(i=0;i<=n;i++){
		for(j=0;j<=t;j++){
			if(i==0 || j==0)
				dp[i][j]=0; //for first row first column
			else{
				if(w[i]>j)
					dp[i][j]=dp[i-1][j];
				else{
					dp[i][j]=max(dp[i-1][j],(dp[i-1][j-w[i]])+p[i]);
				}
			}
		}
	}
	
	//print dp
	/*
	for(i=0;i<=n;i++){
		for(j=0;j<=t;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	//print total maximum profit
	cout<<dp[n][t]<<endl;
	
	//Get resultant array
	int total=dp[n][t];
	i=n;
	while(i>=0){
		int flag=0;
		for(j=t;j>=0;j--){
			if(dp[i][j]==total){
				flag=1;
				break;
			}		 
		}
		if(flag==0){
			total-=p[i+1];
			result[i+1]=1;
		}
		else{
			i--;
		}
			
	}
	//print result array
	for(i=1;i<=n;i++)
	cout<<result[i]<<" ";
	
	return 0;
}
